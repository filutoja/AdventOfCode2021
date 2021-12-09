#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <numeric>

unsigned Accumulate(unsigned value) {
    unsigned res=0;
    for(int i=1; i <=value; ++i){
        res+=i;
    }
    return res;
}

int main()
{
    std::ifstream infile("../input.txt");

    char coma;
    unsigned number;
    std::vector<unsigned> data;
    while (infile >> number) {
        data.push_back(number);
        infile >> coma;
    }
    std::sort(data.begin(), data.end());
    unsigned median = data[data.size()/2];
    std::cout << "median = " << median << std::endl;
    unsigned long res = 0;
    for(const auto & d : data){
        res+= abs(d-median);
    }
    std::cout << "Part1 res = " << res << std::endl;

    double average = (std::accumulate(data.begin(), data.end(), 0))*1.0 / data.size();

    unsigned long res1=0;
    for(const auto & d : data) {
        res1+= Accumulate(abs(d-static_cast<int>(average)));
    }
    unsigned long res2=0;
    for(const auto & d : data) {
        res2+= Accumulate(abs(d-(static_cast<int>(average)+1)));
    }
    res = std::min(res1, res2);
    std::cout << "Part2 res = " << res << std::endl;

    return 0;
}
