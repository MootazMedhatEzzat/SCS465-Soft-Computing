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

// Structure to define an item with weight and value
struct Item {
    int weight;
    int value;
};

class KnapsackProblem {
    private:
        int populationSize;             // Size of the population
        int maxNumOfGenerations;        // Maximum number of generations to evolve
        double mutationRate;            // Probability of mutation
        double calculateFitness(const Chromosome&, const vector<Item>&, int); // Function to calculate fitness
        int calculateTotalWeight(const vector<bool>&, const vector<Item>&);   // Function to calculate total weight
        Chromosome crossover(const Chromosome&, const Chromosome&);           // Function to perform crossover
        void mutate(Chromosome&);                                             // Function to perform mutation

    public:
        KnapsackProblem(int, int, double);    // Constructor
        void solve(const vector<Item>&, int); // Function to solve the problem
};

// Constructor to initialize the problem parameters
KnapsackProblem::KnapsackProblem(int N, int numGenerations, double m) {
    populationSize = N;                  // Set population size
    maxNumOfGenerations = numGenerations;// Set maximum number of generations
    mutationRate = m;                    // Set mutation rate

    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
}

// Function to calculate the fitness of a chromosome
double KnapsackProblem::calculateFitness(const Chromosome& chromosome, const vector<Item>& items, int knapsackCapacity) {
    int totalWeight = calculateTotalWeight(chromosome.getGenes(), items); // Calculate total weight of selected items
    
    // If the total weight exceeds the capacity, the solution is infeasible
    if (totalWeight > knapsackCapacity) {
        return 0.0; // Return zero fitness for infeasible solutions
    }
    
    double totalValue = 0.0; // Initialize total value
    for (int i = 0; i < chromosome.getChromosomeSize(); i++) {
        if (chromosome.getGeneAtIndex(i) == 1) { // If item is selected
            totalValue += items[i].value; // Add its value to the total value
        }
    }
    return totalValue; // Return the total value as fitness
}

// Function to calculate the total weight of selected items in a chromosome
int KnapsackProblem::calculateTotalWeight(const vector<bool>& genes, const vector<Item>& items) {
    int totalWeight = 0; // Initialize total weight
    for (int i = 0; i < genes.size(); i++) {
        if (genes[i]) { // If gene is true (item is selected)
            totalWeight += items[i].weight; // Add item's weight to total weight
        }
    }
    return totalWeight; // Return the total weight
}

// Function to perform one-point crossover between two parent chromosomes
Chromosome KnapsackProblem::crossover(const Chromosome& parent1, const Chromosome& parent2) {
    int numOfGenes = parent1.getChromosomeSize(); // Get number of genes in a chromosome
    int crossoverPoint = rand() % numOfGenes;     // Select a random crossover point
    Chromosome child(numOfGenes);                 // Create a child chromosome
    
    // Copy genes from parent1 to child up to the crossover point
    for (int i = 0; i < crossoverPoint; i++) {
        child.setGeneAtIndex(i, parent1.getGeneAtIndex(i));
    }
    // Copy genes from parent2 to child from the crossover point onward
    for (int i = crossoverPoint; i < numOfGenes; i++) {
        child.setGeneAtIndex(i, parent2.getGeneAtIndex(i));
    }
    return child; // Return the new child chromosome
}

// Function to mutate a chromosome based on the mutation rate
void KnapsackProblem::mutate(Chromosome& chromosome) {
    for (int i = 0; i < chromosome.getChromosomeSize(); i++) {
        double randomNum = static_cast<double>(rand()) / RAND_MAX; // Generate a random number between 0 and 1
        if (randomNum < mutationRate) { // If random number is less than mutation rate
            chromosome.setGeneAtIndex(i, !chromosome.getGeneAtIndex(i)); // Flip the gene
        }
    }
}

// Function to solve the knapsack problem using a genetic algorithm
void KnapsackProblem::solve(const vector<Item>& items, int knapsackCapacity) {
    int numOfItems = items.size(); // Get number of items available
    vector<Chromosome> population(populationSize, Chromosome(numOfItems)); // Initialize population
    
    // Loop through each generation
    for (int generation = 0; generation < maxNumOfGenerations; generation++) {
        // Calculate fitness for each chromosome in the population
        for (int i = 0; i < populationSize; i++) {
            population[i].setFitness(calculateFitness(population[i], items, knapsackCapacity));
        }
        
        // Sort chromosomes by fitness in descending order
        sort(population.begin(), population.end(), [](const Chromosome& a, const Chromosome& b) {
            return a.getFitness() > b.getFitness();
        });

        vector<Chromosome> newPopulation(populationSize); // New population for the next generation

        // Calculate cumulative probabilities for rank-based selection
        vector<double> cumulativeProbabilities(populationSize);
        double totalRank = 0.0;
        for (int i = 0; i < populationSize; i++) {
            totalRank += (populationSize - i); // Sum ranks
        }
        double sumProb = 0.0;
        for (int i = 0; i < populationSize; i++) {
            sumProb += (populationSize - i) / totalRank; // Calculate cumulative probability
            cumulativeProbabilities[i] = sumProb; // Store cumulative probability
        }

        // Select chromosomes for the new population based on rank-based selection
        for (int i = 0; i < populationSize; i++) {
            double randomNum = static_cast<double>(rand()) / RAND_MAX; // Generate a random number
            int selectedIndex = 0;
            for (int j = 0; j < populationSize; j++) {
                if (randomNum < cumulativeProbabilities[j]) { // Select based on cumulative probability
                    selectedIndex = j;
                    break;
                }
            }
            newPopulation[i] = population[selectedIndex]; // Add selected chromosome to new population
        }

        // Apply crossover to create new offspring
        for (int i = 0; i < populationSize; i++) {
            if (static_cast<double>(rand()) / RAND_MAX < 0.7) { // 70% probability of crossover
                int parent1Index = rand() % populationSize; // Select first parent
                int parent2Index = rand() % populationSize; // Select second parent
                newPopulation[i] = crossover(population[parent1Index], population[parent2Index]); // Perform crossover
            }
        }

        // Apply mutation to the new population
        for (int i = 0; i < populationSize; i++) {
            mutate(newPopulation[i]);
        }

        population = newPopulation; // Replace old population with new population
    }

    // Find the best chromosome in the final population
    Chromosome bestChromosome = *std::max_element(population.begin(), population.end(), [](const Chromosome& a, const Chromosome& b) {
        return a.getFitness() < b.getFitness();
    });

    // Output the results
    vector<bool> genes = bestChromosome.getGenes();
    cout << "Number of selected items: " << count(genes.begin(), genes.end(), true) << endl; // Output number of selected items
    cout << "Total value: " << bestChromosome.getFitness() << endl; // Output total value of selected items
    cout << "Total weight: " << calculateTotalWeight(bestChromosome.getGenes(), items) << endl; // Output total weight

    cout << "Selected items:" << endl;
    for (int i = 0; i < items.size(); i++) {
        if (bestChromosome.getGeneAtIndex(i)) { // If item is selected
            cout << "Weight: " << items[i].weight << ", Value: " << items[i].value << endl; // Output item details
        }
    }
}

#endif // KNAPSACKPROBLEM_H_INCLUDED
