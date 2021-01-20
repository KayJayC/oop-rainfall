/*
    rainfall.cpp
    This is a rainfall report. Individiual rain amounts per hour are input. output
    is the average and heaviest hourly rainfall.
*/
#include <iostream>
#include <iomanip>
#include <vector>


int main() {

    //input hourly rainfall rate
    std::vector<double> rainfall;
    double n;

    while (std::cin >>n){
        rainfall.push_back(n);
    }
    if (!rainfall.size())
        return 1;

    //calculate average
    auto total= rainfall[0];
    for (int i=1; i < rainfall.size(); ++i){
        total += rainfall [i];
    }

    //calculate heaviest rainfall
    auto max= rainfall[0];
    for (int i=1; i < rainfall.size(); ++i){
        if (rainfall[i] > max)
            max= rainfall [i];
    }

    // output the rainfall report
    std::cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << (total /rainfall.size()) << " hundreds of inches" << '\n';
    std::cout << "Heaviest Hourly Rainfall: " << max << " hundreds of inches" << '\n' ;

    return 0;
}
