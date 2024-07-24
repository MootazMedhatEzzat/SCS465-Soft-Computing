#ifndef KNAPSACKPROBLEM_H_INCLUDED
#define KNAPSACKPROBLEM_H_INCLUDED

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include "Chromosome.h"

using namespace std;

struct Item {
    int weight;
    int value;
};

class KnapsackProblem {
    private:
        int populationSize;
        int maxNumOfGenerations;
        double mutationRate;
        double calculateFitness(const Chromosome&, const vector<Item>&, int);
        int calculateTotalWeight(const vector<bool>&, const vector<Item>&);
        Chromosome crossover(const Chromosome&, const Chromosome&);
        void mutate(Chromosome&);

    public:
        KnapsackProblem(int, int, double);
        void solve(const vector<Item>&, int);
};

KnapsackProblem::KnapsackProblem(int N, int numGenerations, double m) {
    populationSize = N;
    maxNumOfGenerations = numGenerations;
    mutationRate = m;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
}

// The fitness function is evaluated for every chromosome and used in the selection process.
double KnapsackProblem::calculateFitness(const Chromosome& chromosome, const vector<Item>& items, int knapsackCapacity) {
    int totalWeight = calculateTotalWeight(chromosome.getGenes(), items);
    // Handles the infeasible solutions
    if (totalWeight > knapsackCapacity) {
        return 0.0;
    }
    double totalValue = 0.0;
    for (int i = 0; i < chromosome.getChromosomeSize(); i++) {
        if (chromosome.getGeneAtIndex(i) == 1) {
            totalValue += items[i].value;
        }
    }
    return totalValue;
}

int KnapsackProblem::calculateTotalWeight(const vector<bool>& genes, const vector<Item>& items) {
    int totalWeight = 0;
    for (int i = 0; i < genes.size(); i++) {
        if (genes[i]) {
            totalWeight += items[i].weight;
        }
    }
    return totalWeight;
}

// Implements the one-point crossover operation
Chromosome KnapsackProblem::crossover(const Chromosome& parent1, const Chromosome& parent2) {
    int numOfGenes = parent1.getChromosomeSize();
    // Randomly generates a crossover point by generating a random number between 0 and (number of Genes - 1)
    int crossoverPoint = rand() % numOfGenes;
    Chromosome child(numOfGenes);
    for (int i = 0; i < crossoverPoint; i++) {
        child.setGeneAtIndex(i, parent1.getGeneAtIndex(i));
    }
    for (int i = crossoverPoint; i < numOfGenes; i++) {
        child.setGeneAtIndex(i, parent2.getGeneAtIndex(i));
    }
    return child;
}

// Implements the mutation operation
void KnapsackProblem::mutate(Chromosome& chromosome) {
    for (int i = 0; i < chromosome.getChromosomeSize(); i++) {
        // For each gene, generates a random number between 0 and 1
        double randomNum = static_cast<double>(rand()) / RAND_MAX;
        // If the random generated number is less than the mutation rate(m), then it flips the gene
        if (randomNum < mutationRate) {
            chromosome.setGeneAtIndex(i, !chromosome.getGeneAtIndex(i));
        }
    }
}

void KnapsackProblem::solve(const vector<Item>& items, int knapsackCapacity) {
    int numOfItems = items.size();
    // Initializes the population by creating a vector of Chromosome objects with a size of population size
    vector<Chromosome> population(populationSize, Chromosome(numOfItems));
    for (int generation = 0; generation < maxNumOfGenerations; generation++) {
        // Calculates the fitness of each chromosome in the population
        for (int i = 0; i < populationSize; i++) {
            population[i].setFitness(calculateFitness(population[i], items, knapsackCapacity));
        }
        // Performs rank selection to select parents for crossover based on fitness(sorts the chromosomes in the population from highest to lowest fitness)
        sort(population.begin(), population.end(), [](const Chromosome& a, const Chromosome& b) {
            return a.getFitness() > b.getFitness();
        });
        vector<Chromosome> newPopulation(populationSize);
        // For each chromosome, calculates a rank probability based on its position in the sorted population
        for (int i = 0; i < populationSize; i++) {
            double rankProb = static_cast<double>(i + 1) / populationSize;
            // Generates a random number between 0 and 1 for each chromosome
            double randomNum = static_cast<double>(rand()) / RAND_MAX;
            // If the random generated number less than the rank probability, copies the chromosome as is to the new population.
            if (randomNum < rankProb) {
                cout << "copiesAsIt: " << i << endl;
                newPopulation[i] = population[i];
            } else { // Randomly selects two parents from the top half of the population and performs crossover
                int parentIndex = rand() % (populationSize / 2);
                cout << "parentIndex: " << parentIndex << endl;
                newPopulation[i] = crossover(population[parentIndex], population[parentIndex + 1]);
            }
        }
        // Applies mutation to each chromosome in the new population
        for (int i = 0; i < populationSize; i++) {
            mutate(newPopulation[i]);
        }
        population = newPopulation;
    }

    // Select the best chromosome from the final population
    Chromosome bestChromosome = *std::max_element(population.begin(), population.end(), [](const Chromosome& a, const Chromosome& b) {
        return a.getFitness() < b.getFitness();
    });

    // Output the results
    vector<bool> genes = bestChromosome.getGenes();
    cout << "Number of selected items: " << count(genes.begin(), genes.end(), true) << endl;
    cout << "Total value: " << bestChromosome.getFitness() << endl;
    cout << "Total weight: " << calculateTotalWeight(bestChromosome.getGenes(), items) << endl;

    cout << "Selected items:" << endl;
    for (int i = 0; i < items.size(); i++) {
        if (bestChromosome.getGeneAtIndex(i)) {
            cout << "Weight: " << items[i].weight << ", Value: " << items[i].value << endl;
        }
    }
}

#endif // KNAPSACKPROBLEM_H_INCLUDED
