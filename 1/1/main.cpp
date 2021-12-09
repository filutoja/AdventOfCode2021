#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream infile("../input.txt");
    std::vector<int> input{};
    int x = 0;
    int prev = 0;
    int count = 0;
    while (infile >> x)
    {
//        if(prev < x) {
//            count++;
//        }
//        prev = x;
        input.push_back(x);
    }
    std::vector<int> sum_in{};
    for(int i=2;i<input.size(); ++i){
        sum_in.push_back(input[i] + input[i-1] + input[i-2]);
    }

    for(auto a : sum_in) {
                if(prev < a) {
                    count++;
                }
                prev = a;
    }
    std::cout << input.size();
    std::cout << "count = " << count - 1 << std::endl;
    return 0;
}
