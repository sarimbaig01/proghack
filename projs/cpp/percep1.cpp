#include <vector>
#include <utility> // for std::pair
#include <iostream>

using namespace std;

// Applies the step activation function to the weighted sum.
int stepActivation(double z);

// Calculates the weighted sum of inputs and weights (including the bias as w0).
double weightedSum(const vector<double>& weights, const vector<double>& inputs);

// Initializes the weights (including bias as w0) to small random values or zeros.
void initializeWeights(vector<double>& weights, int m);

// Calculates the error between the predicted output and the actual output.
double computeError(double actual, double predicted);

// Updates the weights based on the error and learning rate.
void updateWeights(vector<double>& weights, const vector<double>& inputs, double error, double learningRate);

// Uses the trained perceptron model to make predictions on new data.
int predict(const vector<double>& weights, const vector<double>& inputs);

// Evaluates the model's performance on a validation or test dataset.
double evaluateModel(const vector<pair<vector<double>, double>>& dataset, const vector<double>& weights);

// Prints the training progress for each training cycle.
void printTrainingProgress(int cycle, int totalCycles, double currentError);

// Coordinates the entire training process (corresponds to the algorithm in Figure 3)
void trainPerceptron(const vector<pair<vector<double>, double>>& trainingData, int numOfTrainingCycles, double learningRate, vector<double>& weights);
    