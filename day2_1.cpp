#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <list>


int main() {
    long long sum = 0;
    
    std::ifstream in("input.txt");
    if (!in) {
        std::cerr << "Error: could not open ranges.txt\n";
        return 1;
    }

    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue; // skip empty lines

        std::stringstream ss(line);
        std::string token;

        while (std::getline(ss, token, ',')) {
            std::list<long> invalidIDs = {};
            if (token.empty()) continue;

            std::size_t dashPos = token.find('-');
            if (dashPos == std::string::npos) {
                std::cerr << "Warning: invalid token (no dash): " << token << '\n';
                continue;
            }

            std::string low  = token.substr(0, dashPos);
            std::string high = token.substr(dashPos + 1);
            std::cout << "low: \"" << low << "\"  high: \"" << high << "\"\n";
            
            for(long i = std::stol(low); i<= std::stol(high); ++i){
                //std::cout << i << " ";
                if(std::to_string(i).length() % 2){ 
                    continue;
                }
                
                int middle_pos = std::to_string(i).length() / 2;
                if(std::to_string(i).substr(0, middle_pos) == std::to_string(i).substr(middle_pos, std::to_string(i).length())){
                    //std::cout << std::to_string(i) << " ";
                    invalidIDs.push_back(i);
                }
            }
            
            for (long num : invalidIDs) {
                std::cout << num << " ";
                sum += num;
            }
            std::cout << std::endl;
        }
        std::cout << "sum: "<< sum << "\n"; 
    }

    return 0;
}
