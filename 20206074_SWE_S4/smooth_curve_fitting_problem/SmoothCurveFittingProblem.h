#ifndef SMOOTHCURVEFITTINGPROBLEM_H_INCLUDED
#define SMOOTHCURVEFITTINGPROBLEM_H_INCLUDED

#include <random>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <vector>
#include "Chromosome.h"

using namespace std;

class SmoothCurveFittingProblem {
    private:
        int populationSize;
        int polynomialDegree;
        int tournamentSize;
        int numOfPassedChromosomes;
        int maxNumOfGenerations;
        double mutationRate;
        double crossoverRate;
        double elitismRatio;
        double lowerBound;
        double upperBound;
        double calculateFitness(const Chromosome&, const vector<Point>&);
        double calculateMeanSquareError(const Chromosome&, const vector<Point>&);
        Chromosome tournamentSelection(const vector<Chromosome>&);
        void twoPointCrossover(Chromosome&, Chromosome&);
        void nonUniformMutation(Chromosome&, int);
        vector<Chromosome> elitistReplacement(const vector<Chromosome>&);

    public:
        SmoothCurveFittingProblem(int, int, int, int, double, double, double, double, double);
        void solve(const vector<Point>&);
};

SmoothCurveFittingProblem::SmoothCurveFittingProblem(int N, int pDegree, int tournamentS, int generationsNum, double m, double c, double elitismR, double lBound, double uBound) {
    populationSize = N;
    polynomialDegree = pDegree;
    tournamentSize = tournamentS;
    numOfPassedChromosomes = elitismR * N;
    maxNumOfGenerations = generationsNum;
    mutationRate = m;
    crossoverRate = c;
    elitismRatio = elitismR;
    lowerBound = lBound;
    upperBound = uBound;

    srand(static_cast<unsigned int>(time(0)));
}

double SmoothCurveFittingProblem::calculateFitness(const Chromosome& chromosome, const vector<Point>& points) {
    double chromosomeFitness = 1.0 / calculateMeanSquareError(chromosome, points);
    return chromosomeFitness;
}

double SmoothCurveFittingProblem::calculateMeanSquareError(const Chromosome& chromosome, const vector<Point>& points) {
    double error = 0.0, polynomialValueAtX = 0.0;
    for (int i = 0; i < points.size(); i++) {
        for (int j = 0; j < chromosome.getChromosomeSize(); j++) {
            polynomialValueAtX += chromosome.getGeneAtIndex(j) * pow(points[i].x, j);
        }
        error += pow((polynomialValueAtX - points[i].y), 2);
        polynomialValueAtX = 0.0;
    }
    return error/points.size();
}

Chromosome SmoothCurveFittingProblem::tournamentSelection(const vector<Chromosome>& population) {
    Chromosome bestChromosome;
    for (int i = 0; i < tournamentSize; i++) {
        int randomIndex = rand() % populationSize;
        if (population[randomIndex].getFitness() > bestChromosome.getFitness()) {
            bestChromosome = population[randomIndex];
        }
    }
    return bestChromosome;
}

void SmoothCurveFittingProblem::twoPointCrossover(Chromosome& parent1, Chromosome& parent2) {
    // Randomly generate randomNum in the range [0.0, 1.0]
    double randomNum = static_cast<double>(rand()) / RAND_MAX;
    if (randomNum <= crossoverRate) {
        // Randomly generate crossoverPoint1 and crossoverPoint2 in the range [1, ChromosomeLength -1]
        int crossoverPoint1 = (rand() % (parent1.getChromosomeSize() - 1)) + 1;
        int crossoverPoint2;
        do {
            crossoverPoint2 = (rand() % (parent2.getChromosomeSize() - 1)) + 1;
        } while (crossoverPoint2 == crossoverPoint1);
        if (crossoverPoint1 > crossoverPoint2) {
            swap(crossoverPoint1, crossoverPoint2);
        }
        for (int i = crossoverPoint1; i < crossoverPoint2; i++) {
            parent1.swapGeneAtIndex(i, parent2);
        }
    }
}

void SmoothCurveFittingProblem::nonUniformMutation(Chromosome& chromosome, int currentGeneration) {
    // Randomly generate b in the range [0.5, 5]
    double b = 0.5 + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / 4.5));
    for (int i = 0; i < chromosome.getChromosomeSize(); i++) {
        // Randomly generate randomNum in the range [0.0, 1.0]
        double randomNum = static_cast<double>(rand()) / RAND_MAX;
        if (randomNum <= mutationRate) {
            double deltaLower = chromosome.getGeneAtIndex(i) - lowerBound;
            double deltaUpper = upperBound - chromosome.getGeneAtIndex(i);
            double r1 = static_cast<double>(rand()) / RAND_MAX;
            double y;
            if (r1 <= 0.5) {
                y = deltaLower;
            } else {
                y = deltaUpper;
            }
            double r = static_cast<double>(rand()) / RAND_MAX;
            double mutationValue = y * (1 - pow(r, pow((1 - currentGeneration / maxNumOfGenerations), b)));
            if (y == deltaLower) {
                chromosome.setGeneAtIndex(i, (chromosome.getGeneAtIndex(i)-mutationValue));
                if (chromosome.getGeneAtIndex(i) < lowerBound) {
                    chromosome.setGeneAtIndex(i, lowerBound);
                }
            } else {
                chromosome.setGeneAtIndex(i, (chromosome.getGeneAtIndex(i)+mutationValue));
                if (chromosome.getGeneAtIndex(i) > upperBound) {
                    chromosome.setGeneAtIndex(i, upperBound);
                }
            }
        }
    }
}

vector<Chromosome> SmoothCurveFittingProblem::elitistReplacement(const vector<Chromosome>& population) {
    vector<Chromosome> pop(populationSize);
    pop = population;
    vector<Chromosome> newPopulation(populationSize);
    sort(pop.begin(), pop.end(), [](const Chromosome& a, const Chromosome& b) {
         return a.getFitness() > b.getFitness();
    });
    for (int i = 0; i < numOfPassedChromosomes; i++) {
        newPopulation[i] = pop[i];
    }
    return newPopulation;
}

void SmoothCurveFittingProblem::solve(const vector<Point>& points) {
    int numOfCoefficients = polynomialDegree + 1;

    // Initializes the population by creating a vector of Chromosome objects with a size of population size
    vector<Chromosome> population;
    random_device rd;
    mt19937 gen(rd());

    for (int i = 0; i < populationSize; i++) {
        uniform_real_distribution<double> dis(lowerBound, upperBound);
        population.emplace_back(Chromosome(numOfCoefficients, dis(gen), dis(gen)));
    }

    for (int generation = 0; generation < maxNumOfGenerations; generation++) {

        // Calculates the fitness of each chromosome in the population
        for (int i = 0; i < populationSize; i++) {
            population[i].setFitness(calculateFitness(population[i], points));
        }

        vector<Chromosome> newPopulation(populationSize);
        newPopulation = elitistReplacement(population);

        for (int i = numOfPassedChromosomes; i < populationSize; i++) {
            Chromosome parent1 = tournamentSelection(population);
            Chromosome parent2 = tournamentSelection(population);

            twoPointCrossover(parent1, parent2);

            nonUniformMutation(parent1, generation);
            nonUniformMutation(parent2, generation);

            parent1.setFitness(calculateFitness(parent1, points));
            parent2.setFitness(calculateFitness(parent2, points));

            newPopulation[i] = parent1;
            newPopulation[i+1] = parent2;
            i++;
        }
        population = newPopulation;
    }
    // Select the best chromosome from the final population
    Chromosome bestChromosome = *std::max_element(population.begin(), population.end(), [](const Chromosome& a, const Chromosome& b) {
        return a.getFitness() < b.getFitness();
    });

    cout << "Polynomial coefficients: ";
    for (int i = 0; i < bestChromosome.getChromosomeSize(); i++) {
        cout << bestChromosome.getGeneAtIndex(i) << " ";
    }
    cout << endl;
    cout << "Mean square error: " << calculateMeanSquareError(bestChromosome, points) << endl;
}

#endif // SMOOTHCURVEFITTINGPROBLEM_H_INCLUDED
