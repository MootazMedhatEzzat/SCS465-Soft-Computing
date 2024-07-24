#ifndef NEURALNETWORK_H_INCLUDED
#define NEURALNETWORK_H_INCLUDED

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include "Layer.h"

using namespace std;

class NeuralNetwork {
    private:
        Layer inputLayer;
        Layer hiddenLayer;
        Layer outputLayer;
        double learningRate = 0.01;
        int epochs = 1000;

        void feedForward(const vector<double>&);
        double backpropagate(double);
        double sigmoid(double) const;
        double sigmoid_derivative(double) const;

    public:
        NeuralNetwork(int, int, int);

        void setHyperparameters(double, int);
        void train(const vector<vector<double>>&, const vector<double>&);
        double predict(const vector<double>&);
};

void NeuralNetwork::feedForward(const vector<double>& input)
{
    // Set input values
    for (size_t i = 0; i < inputLayer.neurons.size(); ++i) {
        inputLayer.neurons[i].output = input[i];
    }

    // Hidden layer
    for (size_t i = 0; i < hiddenLayer.neurons.size(); ++i) {
        double sum = 0.0;
        for (size_t j = 0; j < inputLayer.neurons.size(); ++j) {
            sum += inputLayer.neurons[j].output * hiddenLayer.neurons[i].weights[j];
        }
        hiddenLayer.neurons[i].output = sigmoid(sum);
    }

    // Output layer
    for (size_t i = 0; i < outputLayer.neurons.size(); ++i) {
        double sum = 0.0;
        for (size_t j = 0; j < hiddenLayer.neurons.size(); ++j) {
            sum += hiddenLayer.neurons[j].output * outputLayer.neurons[i].weights[j];
        }
        // Linear activation for regression
        outputLayer.neurons[i].output = sum;
    }
}

double NeuralNetwork::backpropagate(double target) {
    double output = 0.0;

    // Calculate output layer error
    for (size_t i = 0; i < outputLayer.neurons.size(); ++i) {
        output = outputLayer.neurons[i].output;
        outputLayer.neurons[i].error = target - outputLayer.neurons[i].output;
    }

    // Calculate hidden layer error
    for (size_t i = 0; i < outputLayer.neurons.size(); ++i) {
        for (size_t j = 0; j < hiddenLayer.neurons.size(); ++j) {
            hiddenLayer.neurons[j].error = outputLayer.neurons[i].error * outputLayer.neurons[i].weights[j] * sigmoid_derivative(hiddenLayer.neurons[j].output);
        }
    }

    // Update output layer weights
    for (size_t i = 0; i < outputLayer.neurons.size(); ++i) {
        for (size_t j = 0; j < hiddenLayer.neurons.size(); ++j) {
            outputLayer.neurons[i].weights[j] += learningRate * outputLayer.neurons[i].error * hiddenLayer.neurons[j].output;
        }
    }

    // Update hidden layer weights
    for (size_t i = 0; i < hiddenLayer.neurons.size(); ++i) {
        for (size_t j = 0; j < inputLayer.neurons.size(); ++j) {
            hiddenLayer.neurons[i].weights[j] += learningRate * hiddenLayer.neurons[i].error * inputLayer.neurons[j].output;
        }
    }
    // Mean Squared Error
    return 0.5 * pow(target - output, 2.0);
}

double NeuralNetwork::sigmoid(double x) const {
    return 1.0 / (1.0 + exp(-x));
}

double NeuralNetwork::sigmoid_derivative(double x) const {
    return x * (1.0 - x);
}

NeuralNetwork::NeuralNetwork(int inputSize, int hiddenSize, int outputSize) : inputLayer(), hiddenLayer(), outputLayer() {

    srand(static_cast<unsigned int>(time(0)));

    inputLayer.initialize(inputSize, 0);

    hiddenLayer.initialize(hiddenSize, inputSize);

    outputLayer.initialize(outputSize, hiddenSize);
}

void NeuralNetwork::setHyperparameters(double learningRate, int epochs) {
    this->learningRate = learningRate;
    this->epochs = epochs;
}

void NeuralNetwork::train(const vector<vector<double>>& features, const vector<double>& targets) {
    for (int epoch = 0; epoch < epochs; ++epoch) {
        double totalError = 0.0;
        for (size_t i = 0; i < features.size(); ++i) {
            feedForward(features[i]);
            totalError += backpropagate(targets[i]);
        }
        // double meanError = totalError / features.size();
        // cout << "Epoch: " << epoch + 1 << ", Mean Squared Error: " << meanError << endl;
    }
}

double NeuralNetwork::predict(const vector<double>& features) {
    feedForward(features);
    return outputLayer.neurons[0].output; // Assuming a single output neuron for regression
}
#endif // NEURALNETWORK_H_INCLUDED
