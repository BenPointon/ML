#include <iostream>

double pow(double num, double raise){
    double ans = 1;
    for (int i=0; i<raise; i++){
        ans *= num;
    }
    return ans;
}

double cost(double prediction, double data){
    double costAns = pow((prediction - data),2);
    return costAns;
}

double num_slope(double prediction, double data){
    double h = 0.0001;
    double numSlopeAns = (cost((prediction+h), data) - cost(prediction, data)) / h;
    return numSlopeAns;
}

void move_prediction(double& prediction, double data, double learningRate){
    prediction -= (learningRate*num_slope(prediction, data));
}

int main() {
    double pred = 8;
    int input;
    std::cout << "Enter number of itterations: \n";
    std::cin >> input;
    for (int i = 0;i<input; i++){
        move_prediction(pred, 4, 0.9);
    }
    std::cout << pred;
    return 0;
}