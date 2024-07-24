#ifndef NEURON_H_INCLUDED
#define NEURON_H_INCLUDED

#include <iostream>
#include <vector>

using namespace std;

class Neuron {
    public:
        double output;
        double error;
        vector<double> weights;
};

#endif // NEURON_H_INCLUDED
