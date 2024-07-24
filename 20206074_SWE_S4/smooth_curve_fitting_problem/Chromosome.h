#ifndef CHROMOSOME_H_INCLUDED
#define CHROMOSOME_H_INCLUDED

#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

struct Point {
    double x;
    double y;
};

class Chromosome {
    private:
        vector<double> genes;  // genes refers to coefficients.
        double fitness = 0.0;

    public:
        // Constructor
        Chromosome();
        Chromosome(int, double, double);
        // Setters
        void setGenes(const vector<double>&);
        void setGeneAtIndex(int, double);
        void setFitness(double);
        // Getters
        vector<double> getGenes() const;
        double getGeneAtIndex(int) const;
        int getChromosomeSize() const;
        double getFitness() const;
        // swap specific genes of two chromosomes
        void swapGeneAtIndex(int, Chromosome&);
};

Chromosome::Chromosome() {}

Chromosome::Chromosome(int numOfGenes, double lowerBound, double upperBound) {
    // Resizes the genes vector to have a size of numOfGenes.
    genes.resize(numOfGenes);

    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < numOfGenes; i++) {
        // Assigns a random value between lowerBound and upperBound to each gene in the chromosome
        genes[i] = lowerBound + ((double)rand() / RAND_MAX) * (upperBound - lowerBound);
    }
    setFitness(0.0);
}

void Chromosome::setGenes(const vector<double>& newGenes) {
    genes = newGenes;
}

void Chromosome::setGeneAtIndex(int index, double value) {
    genes[index] = value;
}

void Chromosome::setFitness(double newFitness) {
    fitness = newFitness;
}

vector<double> Chromosome::getGenes() const {
    return genes;
}

double Chromosome::getGeneAtIndex(int index) const {
    return genes[index];
}

int Chromosome::getChromosomeSize() const {
    return genes.size();
}

double Chromosome::getFitness() const {
    return fitness;
}

void Chromosome::swapGeneAtIndex(int index, Chromosome& other) {
    swap(genes[index], other.genes[index]);
}

#endif // CHROMOSOME_H_INCLUDED
