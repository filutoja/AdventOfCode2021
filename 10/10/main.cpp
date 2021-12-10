#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>

int res1 = 0;
std::vector<long> res2 {};

std::map<char, bool> kIsOpen {
    {')', false},
    {'(', true},
    {']', false},
    {'[', true},
    {'}', false},
    {'{', true},
    {'>', false},
    {'<', true},
};

std::map<char, char> kClosingMatcher {
    {')','('},
    {']','['},
    {'}','{'},
    {'>','<'},
};

std::map<char, int> kScore1Map {
    {')',3},
    {']',57},
    {'}',1197},
    {'>',25137},
};

std::map<char, int> kScore2Map {
    {'(',1},
    {'[',2},
    {'{',3},
    {'<',4},
};

void InterpretLine(const std::string& line) {
    std::stack<char> stack;
    for(int i = 0; i< line.size(); ++i) {
        if(kIsOpen[line[i]]) {
            stack.push(line[i]);
        } else {
            if(kClosingMatcher[line[i]] != stack.top()) {
                res1 += kScore1Map[line[i]];
                return;
            }
            stack.pop();
        }
    }
    long res = 0;
    while(!stack.empty()) {
        res = res * 5 + kScore2Map[stack.top()];
        stack.pop();
    }
    res2.push_back(res);
}

int main() {
    std::ifstream infile("../input.txt");
    std::string line;


    while (infile >> line) {
        InterpretLine(line);
        }
    std::sort(res2.begin(), res2.end());
    std::cout << "res1 = " << res1 << std::endl;

    std::cout << "res2 = " << res2[res2.size()/2] << std::endl;
    return 0;
}
