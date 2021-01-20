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

//average of rainfall data
double average(const std::vector<double>& data){
    auto total= data[0];
    for (int i = 1; i < data.size(); ++i){
        total += data [i];
    }
    return total /data.size();
}

//heaviest Rainfall
double heaviest(const std::vector<double>& data){
    return *std::max_element (data.begin(), data.end());

    auto max= data[0];
    for (int i=1; i < data.size(); ++i){
        if (data[i] > max)
            max= data[i];
    }
    return max;
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
