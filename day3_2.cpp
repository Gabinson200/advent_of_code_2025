#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cctype>   // for std::isdigit
#include <cmath>

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
				int value = c - '0';   // convert char '1'..'9' to int 1..9
				numbers_list.push_back(value);
			}
		}

		for (int n : numbers_list) {
			std::cout << n << " ";
		}
		std::cout << "\n";

		int digits_remaining = 12;
		int pos = -1;
		std::string line_sum;
		while(digits_remaining > 0) {
			int largest_pos = -1;
			int largest_num = -1;
			for(int i = pos+1; i <= numbers_list.size() - digits_remaining; ++i) {
			    if(numbers_list[i]>largest_num){
			        largest_num = numbers_list[i];
			        largest_pos = i;
			    }
			}
			std::cout << " : " << largest_num << ", ";
			line_sum.push_back('0' + largest_num); //+= largest_num * pow(10, digits_remaining);
			digits_remaining--;
			pos = largest_pos;
		}
		std::cout << "line_sum: " << line_sum << "\n";
		sum += std::stol(line_sum);
	}
	std::cout << "sum: "<< sum<< "\n";
	input_file.close();
	return 0;
}
