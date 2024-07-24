#include <iostream>
#include <fstream>
#include <vector>

#include "Chromosome.h"
#include "SmoothCurveFittingProblem.h"

using namespace std;

int main()
{
    // Setting the genetic algorithm parameters
    int N = 100;                  // population size   (N)
    int tournamentS = 2;          // number of chromosomes that will be randomly selected to participate in tournament.
    int generationsNum = 200;
    double m = 0.1;               // mutation rate     (m)
    double c = 0.9;               // crossover rate    (c)
    double elitismR = 0.2;        // ratio of best chromosomes from the current population that will be passed to the next generation without crossover & mutation.
    double lBound = -10.0;        //
    double uBound =  10.0;        //

    int numOfDatasets;
    int numOfDataPoints, pDegree;
    // Reads the input from "curve_fitting_input.txt" file
    ifstream inputFile("curve_fitting_input.txt");

    // Reads the number of data sets from the first line
    inputFile >> numOfDatasets;

    // For each data set
    for (int dataset = 0; dataset < numOfDatasets; dataset++) {
        // Reads the size of the number of data points and the polynomial degree
        inputFile >> numOfDataPoints >> pDegree;

        // Reads the x-coordinate and y-coordinate for each point and store them in vector
        vector<Point> points(numOfDataPoints);

        for (int i = 0; i < numOfDataPoints; i++) {
            inputFile >> points[i].x >> points[i].y;
        }

        cout << "Dataset: " << dataset + 1 << ":" << endl;

        // Solve the SmoothCurve Fitting Problem using the genetic algorithm
        SmoothCurveFittingProblem smoothCurveFittingProblem(N, pDegree, tournamentS, generationsNum, m, c, elitismR, lBound, uBound);
        smoothCurveFittingProblem.solve(points);
    }

    return 0;
}
