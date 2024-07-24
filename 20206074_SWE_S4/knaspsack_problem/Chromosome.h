#ifndef CHROMOSOME_H_INCLUDED
#define CHROMOSOME_H_INCLUDED

#include <vector>
#include <cstdlib>

using namespace std;

class Chromosome {
    private:
        vector<bool> genes;
        double fitness = 0.0;

    public:
        // Constructor
        Chromosome();
        Chromosome(int);
        // Setters
        void setGenes(const vector<bool>&);
        void setGeneAtIndex(int, bool);
        void setFitness(double);
        // Getters
        vector<bool> getGenes() const;
        bool getGeneAtIndex(int) const;
        int getChromosomeSize() const;
        double getFitness() const;
};

Chromosome::Chromosome() {}

Chromosome::Chromosome(int numOfGenes) {
    // Resizes the genes vector to have a size of numOfGenes.
    genes.resize(numOfGenes);
    for (int i = 0; i < numOfGenes; i++) {
        // Assigns a random value between 0 and 1 to each gene in the chromosome
        genes[i] = rand() % 2;
    }
    fitness = 0.0;
}
void Chromosome::setGenes(const vector<bool>& newGenes) {
    genes = newGenes;
}

void Chromosome::setGeneAtIndex(int index, bool value) {
    genes[index] = value;
}

void Chromosome::setFitness(double newFitness) {
    fitness = newFitness;
}

vector<bool> Chromosome::getGenes() const {
    return genes;
}

bool Chromosome::getGeneAtIndex(int index) const {
    return genes[index];
}

int Chromosome::getChromosomeSize() const {
    return genes.size();
}

double Chromosome::getFitness() const {
    return fitness;
}

#endif // CHROMOSOME_H_INCLUDED
