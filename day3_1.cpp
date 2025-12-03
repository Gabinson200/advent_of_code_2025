#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cctype>   // for std::isdigit

int main() {
    std::string file_path = "input.txt";
    std::ifstream input_file(file_path);

    if (!input_file.is_open()) {
        std::cerr << "Error: Could not open file " << file_path << std::endl;
        return 1;
    }

    std::string line;
    std::vector<int> numbers_list;
    long sum = 0;

    while (std::getline(input_file, line)) {
        numbers_list.clear();

        for (char c : line) {
            if (std::isdigit(static_cast<unsigned char>(c))) {
                int value = c - '0';   // convert char '1'..'9' → int 1..9
                numbers_list.push_back(value);
            }
        }

        //std::cout << "Parsed " << numbers_list.size() << " numbers: ";
        for (int n : numbers_list) {
            std::cout << n << " ";
        }
        std::cout << "\n";
        
        int largest = 0;
        int largest_pos = 0;
        for(int i = 0; i < numbers_list.size()-1; ++i){
            if(numbers_list[i] > largest){
                largest = numbers_list[i];
                largest_pos = i;
            }
        }
        std::cout << "largest_pos: " << largest_pos << " ";
        largest = 0;
        int second_largest_pos = 0;
        for(int j = largest_pos+1; j < numbers_list.size(); ++j){
            if(numbers_list[j] > largest){
                largest = numbers_list[j];
                second_largest_pos = j;
            }
        }
        std::cout << "second_largest_pos: " << second_largest_pos << " ";
        
        int num = numbers_list[largest_pos] * 10 + numbers_list[second_largest_pos];
        std::cout << num << "\n";
        sum += num;
    }
    std::cout << sum<< " ";
    input_file.close();
    return 0;
}
