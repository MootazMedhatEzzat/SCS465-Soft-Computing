#ifndef LAYER_H_INCLUDED
#define LAYER_H_INCLUDED

#include <iostream>
#include <vector>
#include <cstdlib>

#include "Neuron.h"

using namespace std;

class Layer {
    private:
        // vector<Neuron> neurons;
    public:
        vector<Neuron> neurons;

        Layer();
        void initialize(int, int);
};

Layer::Layer(){
    // default constructor
}

void Layer::initialize(int numNeurons, int numInputsPerNeuron) {
    neurons.resize(numNeurons);
    for (int i = 0; i < numNeurons; ++i) {
        neurons[i].weights.resize(numInputsPerNeuron);
        for (int j = 0; j < numInputsPerNeuron; ++j) {
            // Initialize weights with small random values between -0.1 and 1.0
            neurons[i].weights[j] = ((rand() % 2001) / 1000.0) - 1.0;
            // cout << "neurons[" << i << "]" << "." << "weights[" << j << "]" << neurons[i].weights[j] << endl;
        }
    }
}

#endif // LAYER_H_INCLUDED
