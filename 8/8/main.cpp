#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int res1 = 0;

bool IsThree(std::string& num, std::vector<std::string>& patterns){
    for(const auto& ch : patterns[0]) {
        if(num.find(ch) == std::string::npos) return false;
    }

    return true;
}

bool IsFive(std::string& num, std::vector<std::string>& patterns){
    bool one_missing = false;
    for(const auto& ch : patterns[2]) {
        if(num.find(ch) == std::string::npos) {
            if(!one_missing) {
                one_missing = true;
            } else {
                return false;
            }
        }
    }

    return true;
}

bool IsZero(std::string& num, std::vector<std::string>& patterns){
    for(const auto& ch : patterns[0]) {
        if(num.find(ch) == std::string::npos) return false;
    }

    return true;
}

bool IsNine(std::string& num, std::vector<std::string>& patterns){
    for(const auto& ch : patterns[2]) {
        if(num.find(ch) == std::string::npos) {
            return false;
        }
    }

    return true;
}

int Decode(std::string& num, std::vector<std::string>& patterns) {
    switch (num.size()) {
    case 2:
        res1++;
        return 1;
    case 3:
        res1++;
       return 7;
    case 4:
        res1++;
        return 4;
    case 5:
        if(IsThree(num, patterns)) return 3;
        if(IsFive(num, patterns)) return 5;

        return 2;
    case 6:
        if(IsNine(num, patterns)) return 9;
        if(IsZero(num, patterns)) return 0;

        return 6;
    case 7:
        res1++;
        return 8;
    default:
        return 0;
    }
}

int HandleData(std::vector<std::string> input) {
    std::sort(input.begin(), input.begin()+10,
              [](const std::string& first, const std::string& second){return first.size() < second.size();});

    std::vector<std::string> patterns(input.begin(), input.begin()+10);
    std::vector<std::string> decoded_num(input.begin()+11, input.end());
    int res = 0;
    int multi = 1000;
    for(auto num : decoded_num) {
        res += Decode(num, patterns) * multi;
        multi = multi / 10;
    }
    std::cout << res << std::endl;
    return res;
}



int main()
{
    std::ifstream infile("../input.txt");

    std::string number;
    int line_counter = 15;
    int res2 = 0;
    std::vector<std::string> data {};
    while (infile >> number) {
        data.push_back(number);
        line_counter--;
        if(!line_counter) {
            line_counter = 15;
            res2 += HandleData(data);
            data = {};
        }
    }
    std::cout << "res1 = " << res1 << std::endl;
    std::cout << "res2 = " << res2 << std::endl;

    return 0;
}
