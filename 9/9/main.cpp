#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

void CreateBasin(const std::pair<int, int>& low, std::vector<std::pair<int, int>>& basin, std::vector<std::vector<short>>& data) {
    basin.push_back(low);
    //up
        if(low.first-1 >= 0 && (data[low.first-1][low.second] != 9) && (std::find(basin.begin(), basin.end(), std::make_pair(low.first-1, low.second)) == basin.end())) {
            CreateBasin(std::make_pair(low.first-1, low.second), basin, data);
        }
    //down
        if(low.first+1 < data.size() && (data[low.first+1][low.second] != 9) && (std::find(basin.begin(), basin.end(), std::make_pair(low.first+1, low.second)) == basin.end())) {
            CreateBasin(std::make_pair(low.first+1, low.second), basin, data);
        }
    //left
        if(low.second-1 >= 0 && (data[low.first][low.second-1] != 9) && (std::find(basin.begin(), basin.end(), std::make_pair(low.first, low.second-1)) == basin.end())) {
            CreateBasin(std::make_pair(low.first,low.second-1), basin, data);
        }
    //right
        if((low.second < data[low.first].size()-1) && (data[low.first][low.second+1] != 9) && (std::find(basin.begin(), basin.end(), std::make_pair(low.first, low.second+1)) == basin.end())) {
            CreateBasin(std::make_pair(low.first, low.second+1), basin, data);
        }
}

int main() {
    std::ifstream infile("../input.txt");
    std::string line;

    std::vector<std::vector<short>> data {};
    while (infile >> line) {
        std::vector<short> v;
        for(auto& ch : line ) {
            v.push_back(ch - '0');
        }
        data.push_back(v);
    }

    std::vector<std::pair<int,int>> lowest{};

    for(int i = 0; i < data.size(); ++i) {
        for(int j = 0; j < data[i].size(); ++j) {
            auto point = data[i][j];
            if(
               ((i-1 < 0) || (point <  data[i-1][j])) && //left
               ((i+1 >= data.size()) || (point < data[i+1][j])) && //right
               ((j-1 < 0) || (point <  data[i][j-1])) && // down
               ((j+1 >= data[i].size()) || (point < data[i][j+1])) //up
                    ) {
                lowest.push_back(std::make_pair(i,j));
            }
        }
    }

    int res = 0;
    for(auto a : lowest) {
        res += data[a.first][a.second]+1;
    }

    std::cout << "res 1 = " << res << std::endl;

    std::vector<std::vector<std::pair<int,int>>> all_basins;

    for(auto low : lowest) {
        std::vector<std::pair<int,int>> basin;
        CreateBasin(low, basin, data);
        all_basins.push_back(basin);
    }
    std::sort(all_basins.begin(), all_basins.end(), [](const std::vector<std::pair<int,int>>& a, const std::vector<std::pair<int,int>>& b){return a.size()>b.size();});

    std::cout << "res 2 = " << all_basins[0].size() * all_basins[1].size() * all_basins[2].size() << std::endl;


    return 0;
}
