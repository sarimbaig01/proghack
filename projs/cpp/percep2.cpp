// Function to split data into training and test sets
void splitData(const std::vector<std::pair<std::vector<double>, double>>& data,
               std::vector<std::pair<std::vector<double>, double>>& trainingData,
               std::vector<std::pair<std::vector<double>, double>>& testData, double trainRatio) {
    int trainSize = static_cast<int>(data.size() * trainRatio);
    trainingData.assign(data.begin(), data.begin() + trainSize);
    testData.assign(data.begin() + trainSize, data.end());
}

int main() {

    // Fitness dataset with features 
    // Features (Column names):
    // Age, Gender (Male = 0, Female=1), Exercise Frequency (times per week), 
    // BMI, Hours of Sleep, Label (Fit =1, Unfit=0)

    std::vector<std::pair<std::vector<double>, double>> data = {
        {{25, 1, 3, 22.0, 7}, 0}, {{30, 0, 4, 27.0, 5}, 1}, {{45, 1, 2, 23.5, 6}, 0},
        {{50, 0, 1, 30.0, 5}, 1}, {{35, 1, 5, 20.0, 7}, 0}, {{60, 0, 0, 28.0, 4}, 1},
        {{55, 0, 1, 32.0, 5}, 1}, {{40, 1, 3, 25.0, 6}, 0}, {{28, 0, 2, 26.0, 5}, 1},
        {{33, 1, 4, 24.0, 6}, 0}, {{22, 0, 5, 23.0, 8}, 0}, {{48, 1, 1, 29.0, 5}, 1},
        {{29, 0, 3, 21.0, 7}, 0}, {{39, 1, 2, 27.5, 6}, 1}, {{58, 0, 1, 31.0, 5}, 1},
        {{36, 1, 4, 22.5, 6}, 0}, {{52, 0, 0, 30.0, 4}, 1}, {{31, 1, 3, 25.0, 6}, 0},
        {{24, 0, 5, 22.0, 7}, 0}, {{49, 1, 1, 28.0, 5}, 1}, {{42, 0, 2, 27.0, 6}, 1},
        {{37, 1, 4, 24.5, 6}, 0}, {{26, 0, 3, 23.0, 7}, 0}, {{55, 0, 0, 29.5, 4}, 1},
        {{34, 1, 2, 25.5, 6}, 0}, {{41, 0, 3, 26.0, 5}, 1}, {{23, 1, 5, 21.5, 8}, 0},
        {{47, 0, 1, 30.5, 5}, 1}, {{38, 1, 4, 23.5, 6}, 0}, {{32, 0, 2, 27.0, 5}, 1},
        {{29, 1, 3, 24.0, 7}, 0}, {{54, 0, 0, 32.5, 4}, 1}, {{33, 1, 5, 22.5, 6}, 0},
        {{44, 0, 2, 28.0, 5}, 1}, {{27, 1, 3, 25.0, 7}, 0}, {{50, 0, 1, 29.0, 5}, 1},
        {{36, 1, 4, 24.0, 6}, 0}, {{39, 0, 2, 26.5, 6}, 1}, {{53, 0, 1, 31.0, 5}, 1},
        {{48, 1, 3, 23.5, 6}, 0}, {{30, 0, 5, 22.0, 7}, 0}, {{57, 0, 0, 30.0, 4}, 1},
        {{35, 1, 4, 25.0, 6}, 0}, {{45, 0, 2, 27.0, 5}, 1}, {{26, 1, 3, 24.0, 7}, 0},
        {{52, 0, 1, 28.5, 5}, 1}, {{37, 1, 4, 23.0, 6}, 0}, {{31, 0, 3, 26.0, 5}, 1},
        {{40, 1, 2, 25.5, 6}, 0}
    };

    // Question to answer: given the age, gender, exercise frequency, BMI, 
    // and hours of sleep of an individual, predict whether they are
    // fit or unfit.

    // Split data into training and test sets (75% training, 25% test)
    std::vector<std::pair<std::vector<double>, double>> trainingData, testData;
    splitData(data, trainingData, testData, 0.75);

    // Initialize perceptron parameters
    std::vector<double> weights;   

    // The following hyper-parameters may be tweaked to improve accuracy          
    int numOfTrainingCycles = 8;      
    double learningRate = 0.01;     

    // Train the perceptron model using the training data
    trainPerceptron(trainingData, numOfTrainingCycles, learningRate, weights);

    // Evaluate the trained model using the test data
    double accuracy = evaluateModel(testData, weights);
    std::cout << "Model Accuracy on Test Data: " << accuracy << std::endl;

    // General query
    // A 25 year old female who exercises daily
    // has a BMI of 22 and sleeps 8 hours a day
    if (predict(weights, {25, 1, 7, 22, 8}) == 0) {
        std::cout << "Unfit\n";
    } else {
        std::cout << "Fit\n";
    }

     // General query
    // A 42 year old male who doesn't exercise
    // has a BMI of 26 and sleeps 6 hours a day
    if (predict(weights, {42, 0, 0, 26, 6}) == 0) {
        std::cout << "Unfit\n";
    } else {
        std::cout << "Fit\n";
    }

    return 0;
}
