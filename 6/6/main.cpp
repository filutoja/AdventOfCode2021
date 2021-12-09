#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iostream>

void NewDay(std::vector<unsigned long long>& fishes) {
    auto new_fished = fishes[0];
    for(int i = 1; i < 9; i++) {
        fishes[i-1] = fishes[i];
    }
    fishes[8]= new_fished;
    fishes[6]+= new_fished;
}

int main()
{
    std::ifstream infile("../input.txt");
    std::vector<unsigned long long> fish_map {0,0,0,0,0,0,0,0,0};

    char coma;
    short fish_age;
    while (infile >> fish_age) {
        fish_map[fish_age]++;
        infile >> coma;
    }

    for(int i = 0; i < 256; ++i) {
        NewDay(fish_map);
    }
    unsigned long long res = 0;
    for(auto a : fish_map) {
        res += a;
    }
    std::cout << "res = "  << res << std::endl;

}
