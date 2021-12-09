#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <utility>

int main()
{
    std::ifstream infile("../input.txt");
    std::map<std::pair<int,int>, int> coordinates;

    char coma;
    std::string separator;
    int x1,y1,x2,y2;
    while (infile >> x1 >> coma >> y1 >> separator >> x2 >> coma >> y2) {
        if(x1==x2) {
            if(y2<y1) {
                int tmp = y2;
                y2=y1;
                y1=tmp;
            }
            for(int i = y1; i <= y2; i++) {
                auto pair = std::make_pair(x1, i);
                coordinates[pair]++;
            }
        } else if (y1==y2) {
            if(x2<x1) {
                int tmp = x2;
                x2=x1;
                x1=tmp;
            }
            for(int i = x1; i <= x2; i++) {
                auto pair = std::make_pair(i, y1);
                coordinates[pair]++;
            }
        } else {
            int x_dif = x2 > x1 ? 1 : -1;
            int y_dif = y2 > y1 ? 1 : -1;
            while(x1 != x2) {
                auto pair = std::make_pair(x1, y1);
                coordinates[pair]++;
                x1 += x_dif;
                y1 += y_dif;
            }
            auto pair = std::make_pair(x2, y2);
            coordinates[pair]++;
        }
    }

    int counter = 0;
    for(const auto a : coordinates) {
        if(a.second > 1) {
            counter ++;
        }
    }

    std::cout << "result = " << counter << std::endl;

    return 0;
}
