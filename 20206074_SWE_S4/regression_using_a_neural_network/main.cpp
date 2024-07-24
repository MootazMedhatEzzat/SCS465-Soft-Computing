#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>

#include "NeuralNetwork.h"

using namespace std;

vector<vector<double>> loadDataSet(const string&);

void normalizeData(vector<vector<double>>&);

int main() {
    // Load data
    vector<vector<double>> dataSet = loadDataSet("concrete_data.txt");

    // Separate features and targets
    vector<vector<double>> features;
    vector<double> targets;

    for (size_t i = 0; i < dataSet.size(); ++i) {
        std::vector<double> featureRecord(dataSet[i].begin(), dataSet[i].end() - 1);
        features.push_back(featureRecord);
        targets.push_back(dataSet[i].back());
    }

    // Normalize data
    normalizeData(features);

    // Split data into training and testing sets (75% training, 25% testing)
    size_t splitIndex = static_cast<size_t>(features.size() * 0.75);

    vector<vector<double>> trainingFeatures(features.begin(), features.begin() + splitIndex);
    vector<double> trainingTargets(targets.begin(), targets.begin() + splitIndex);

    vector<vector<double>> testingFeatures(features.begin() + splitIndex, features.end());
    vector<double> testingTargets(targets.begin() + splitIndex, targets.end());

    // Neural Network
    NeuralNetwork neuralNetwork(features[0].size(), 15, 1);
    neuralNetwork.setHyperparameters(0.01, 10000);

    // Train the neural network
    neuralNetwork.train(trainingFeatures, trainingTargets);

    // Testing phase
    double totalError = 0.0;
    for (size_t i = 0; i < testingFeatures.size(); ++i) {
        double predicted = neuralNetwork.predict(testingFeatures[i]);
        std::cout << "Actual: " << testingTargets[i] << ", Predicted: " << predicted << std::endl;
        totalError += 0.5 * std::pow(testingTargets[i] - predicted, 2.0); // Mean Squared Error
    }

    double meanError = totalError / testingFeatures.size();
    cout << "Mean Squared Error on Testing Set: " << meanError << endl;

    return 0;
}

vector<vector<double>> loadDataSet(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    vector<std::vector<double>> dataSet;
    string line;
    while (std::getline(file, line)) {
        vector<double> record;
        size_t pos = 0;
        while ((pos = line.find('\t')) != string::npos) {
            record.push_back(stod(line.substr(0, pos)));
            line.erase(0, pos + 1);
        }
        record.push_back(stod(line)); // Last column
        dataSet.push_back(record);
    }

    file.close();
    return dataSet;
}

void normalizeData(vector<vector<double>>& dataSet) {
    for (size_t i = 0; i < dataSet[0].size(); ++i) {
        vector<double> column;
        for (size_t j = 0; j < dataSet.size(); ++j) {
            column.push_back(dataSet[j][i]);
        }

        double minVal = *min_element(column.begin(), column.end());
        double maxVal = *max_element(column.begin(), column.end());

        for (size_t j = 0; j < dataSet.size(); ++j) {
            dataSet[j][i] = (dataSet[j][i] - minVal) / (maxVal - minVal);
        }
    }
}
