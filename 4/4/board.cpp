#include "board.h"

#include <algorithm>
#include <cassert>

#include <iostream>

namespace {
int GetIndex(std::vector<int> v, int value)
{
    auto it = find(v.begin(), v.end(), value);
    if (it != v.end()) {
        return it - v.begin();
    }
    return -1;
}

}

void Board::AddRow(std::vector<int> row) {
    board_.push_back(std::move(row));

    assert(("Bingo board can not extned 5 rows", board_.size() <= 5));
    if(board_.size() == 5) {
        for(auto row : board_) {
            for(auto n : row) {
                unmarked_sum_ += n;
            }
        }
        std::cout << "sum = " << unmarked_sum_ << std::endl;
    }
}

bool Board::UpdateBoard(int value) {
    for(int x = 0; x<board_.size(); ++x) {
        int y = GetIndex(board_[x], value);
        if(y != -1) {
            unmarked_sum_ -= value;
            if(UpdateBingo(x,y)) {
            return true;
            }
        }
    }
    return false;
}

bool Board::UpdateBingo(int x, int y) {
    row_[x]= row_[x] + 1;
    col_[y]= col_[y] + 1;
    if(row_[x] == 5) {
        result_.first = x;
        return true;
    }
    if(col_[y] == 5) {
        result_.second = y;
        return true;
    }
    return false;
}

int Board::GetUnmarkedSum() {
        std::vector<int> res;
        if(result_.first != -1) {
            res = board_[result_.first];
        } else {
            for(const auto& row : board_) {
                res.push_back(row[result_.second]);
            }
        }


        std::cout << "res = ";
        for(auto a: res) {
            std::cout << a << ",";
        }
        std::cout << std::endl;
    return unmarked_sum_;
}
