#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <utility>

class Board
{
public:
    Board() = default;
    void AddRow(std::vector<int> row);
    bool UpdateBoard(int value);
    int GetUnmarkedSum();

private:
    bool UpdateBingo(int x, int y);
    bool CheckBingo(int x, int y);

    std::vector<std::vector<int>> board_;
    int unmarked_sum_ {0};
    std::vector<int> row_ {0,0,0,0,0};
    std::vector<int> col_ {0,0,0,0,0};
    std::pair<int, int> result_ {-1,-1};
};

#endif // BOARD_H
