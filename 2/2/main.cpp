#include <iostream>
#include <fstream>
#include <string>


long horizontal = 0;
long depth = 0;
long aim = 0;

void count(const std::string& key, int value) {
    if(key == "down") {
//        depth +=value;
        aim +=value;
        return;
    }
    if(key == "up"){
//        depth -= value;
        aim -= value;
        return;
    }
    if(key == "forward") {
        horizontal +=value;
        depth += (aim * value);
        return;
    }
}

int main()
{
    std::ifstream infile("../input.txt");
    std::string key;
    int value;
    while (infile >> key >> value) {
        count(key,value);
    }

    std::cout << "wynik horizontal = " << horizontal << " depth = " << depth << " all = " << horizontal*depth << std::endl;

    return 0;
}
