#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

char GetCommonBitOxygen(std::vector<std::string> data, int index) {
    int count = 0;
    for (int i = 0; i < data.size(); ++i) {
        if(data[i][index] == '1') {
            count++;
        }
    }
    auto res = count < data.size()/2.0 ? '0' : '1';
    return res;
}

int main()
{
    std::ifstream infile("../input.txt");
    std::string value;
    std::map<int, int> common_value;
    std::vector<std::string> data;
    int result_count = 0;
    while (infile >> value) {
        for(int i = 0; i < value.size(); ++i) {
            if(value[i] == '1') {
                common_value[i]++;
            }
        }
        data.push_back(value);
        result_count++;
    }
    int gamma_rate = 0;
    int epsilon_rate = 0;
    int half_res = result_count/2;
    for(int i = 0; i < common_value.size(); ++i) {
        int gamma_tmp;
        int epsilon_tmp;
        if(common_value[i] > half_res) {
            gamma_tmp = 1;
            epsilon_tmp = 0;
        } else {
            gamma_tmp = 0;
            epsilon_tmp = 1;
        }
        gamma_rate += (gamma_tmp << (common_value.size() - i - 1));
        epsilon_rate += (epsilon_tmp << (common_value.size() - i - 1));
    }

    std::cout << "gamma = " << gamma_rate << " epsilon " << epsilon_rate << " wynik= " << gamma_rate*epsilon_rate << std::endl;

    //////////////second step
    std::vector<std::string> oxygen_data = data;
    for(int i = 0; i < common_value.size(); ++i) {
        std::vector<std::string> tmp_data;
        char common_bit_char = GetCommonBitOxygen(oxygen_data, i);
        for(int j = 0; j < oxygen_data.size(); ++j) {
            if(oxygen_data[j][i] == common_bit_char) {
                tmp_data.push_back(oxygen_data[j]);
            }
        }
        std::cout << "tmp data step: " << i << " size: " << tmp_data.size() << std::endl;
        oxygen_data = tmp_data;
        if(oxygen_data.size() == 1) {
            break;
        }
    }

    auto co2_data = data;
    for(int i = 0; i < common_value.size(); ++i) {
        std::vector<std::string> tmp_data;
        char common_bit_char = GetCommonBitOxygen(co2_data, i);
        for(int j = 0; j < co2_data.size(); ++j) {
            if(co2_data[j][i] != common_bit_char) {
                tmp_data.push_back(co2_data[j]);
            }
        }
        std::cout << "tmp data step: " << i << " size: " << tmp_data.size() << std::endl;
        co2_data = tmp_data;
        if(co2_data.size() == 1) {
            break;
        }
    }

    std::cout << "oxygen size = " << oxygen_data.size() << " data: " << stoi(oxygen_data[0], 0, 2) << " co2 size = " << co2_data.size() << " data = " << stoi(co2_data[0], 0, 2) << std::endl;
    std::cout << "result = " << stoi(oxygen_data[0], 0, 2) * stoi(co2_data[0], 0, 2);

    return 0;
}

