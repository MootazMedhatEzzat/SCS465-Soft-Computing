#include <iostream>
#include <fstream>
#include <vector>

#include "Chromosome.h"
#include "KnapsackProblem.h"

using namespace std;

int main()
{
    // Reads the input from knapsack_input.text file
    ifstream inputFile("knapsack_input.txt");

    // Reads the number of test cases from the first line
    int numOfTestCases;
    inputFile >> numOfTestCases;

    // For each test case
    for (int testCase = 0; testCase < numOfTestCases; testCase++) {
        // Reads the size of the knapsack and the number of items
        int knapsackSize, numItems;
        inputFile >> knapsackSize >> numItems;

        // Reads the weight and value for each item and store them in vector
        vector<Item> items(numItems);
        for (int i = 0; i < numItems; i++) {
            inputFile >> items[i].weight >> items[i].value;
        }

        cout << "Test Case " << testCase + 1 << ":" << endl;

        // Set the genetic algorithm parameters
        int N = 50;                // population size (N)
        int maxNumGenerations = 50;
        double m = 0.05;            // mutation rate (c)

        // Solve the Knapsack Problem using the genetic algorithm
        KnapsackProblem knapsackProblem(N, maxNumGenerations, m);
        knapsackProblem.solve(items, knapsackSize);

        cout << endl;
    }
    return 0;
}
