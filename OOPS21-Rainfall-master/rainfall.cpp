/*
    rainfall.cpp
    This is a rainfall report. Individiual rain amounts per hour are input. output
    is the average and heaviest hourly rainfall.
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

//average of rainfall data
double average(const std::vector<double>& data){
    return std::accumulate (data.begin(), data.end(), 0.0)/data.size();
}

//heaviest Rainfall
double heaviest(const std::vector<double>& data){
    return *std::max_element (data.begin(), data.end());
}


int main() {

    //input hourly rainfall rate
    std::vector<double> rainfall{ std::istream_iterator<double>(std::cin),
                                  std::istream_iterator<double>() };
    if (!rainfall.size())
        return 1;
    // output the rainfall report
    std::cout << "Average Hourly Rainfall: " << std::fixed << std::setprecision(2) << average(rainfall) << " hundreds of inches" << '\n';
    std::cout << "Heaviest Hourly Rainfall: " << heaviest(rainfall) << " hundreds of inches" << '\n' ;

    return 0;
}
