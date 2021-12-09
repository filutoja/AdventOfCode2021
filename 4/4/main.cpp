#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "board.h"

namespace {
std::vector<int> Split(std::string str) {
    std::vector<int> vec {};
    std::stringstream ss(str);

    while( ss.good() ) {
        std::string substr;
        getline( ss, substr, ',' );
        vec.push_back(std::stoi(substr));
    }
    return vec;
}

int Play(std::vector<Board>& boards, std::vector<int> numbers) {
    for(auto number : numbers) {
        for(int i = 0; i<boards.size(); ++i) {
            if(boards[i].UpdateBoard(number)) {
                if(boards.size() == 1) {
                   auto res = boards[i].GetUnmarkedSum();
                   std::cout << "unmarked sum = " << res << " number " << number << std::endl;
                   return number * res;
                }
                boards.erase(boards.begin()+i);
                i--;
            }
        }
    }
    return {};
}

}

int main()
{
    std::string numbers_s;
    std::ifstream infile("../input.txt");
    std::getline(infile, numbers_s);
    auto numbers = Split(numbers_s);

    std::vector<Board> boards;
    Board board;
    int a,b,c,d,e, counter;
    while (infile >> a >> b >> c >> d >> e) {
        counter++;
        board.AddRow({a,b,c,d,e});
        if(counter == 5) {
            boards.push_back(std::move(board));
            counter = 0;
            board = {};
        }
    }

    auto res = Play(boards, numbers);
    std::cout << "Result = " << res << std::endl;

    return 0;
}
