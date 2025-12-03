#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

std::string operator*(const std::string& s, int n) {
	std::string result;
	result.reserve(s.length() * n);
	for (int i = 0; i < n; ++i) {
		result += s;
	}
	return result;
}

bool is_invalid_id(long long x) {
	std::string s = std::to_string(x);
	int len = static_cast<int>(s.size());
	if (len < 2) return false;

	for (int L = 1; L <= len / 2; ++L) {
		if (len % L != 0) continue; // string not divisible by L
		int factor = len / L; // 
		if (factor < 2) continue; // gotta appear more than once
		std::string pattern = s.substr(0, L);
		if (pattern * factor == s) {
			return true;
		}
	}
	return false;
}

int main() {
	long long sum = 0;
	std::ifstream in("input.txt");
	if (!in) {
		std::cerr << "Error: could not open test.txt\n";
		return 1;
	}
	std::string line;
	while (std::getline(in, line)) {
		if (line.empty()) continue;

		std::stringstream ss(line);
		std::string token;

		while (std::getline(ss, token, ',')) {
			std::list<long long> invalidIDs;

			if (token.empty()) continue;

			std::size_t dashPos = token.find('-');
			if (dashPos == std::string::npos) {
				std::cerr << "Warning: invalid token (no dash): " << token << '\n';
				continue;
			}

			long long low  = std::stoll(token.substr(0, dashPos));
			long long high = std::stoll(token.substr(dashPos + 1));

			std::cout << "low: \"" << low << "\"  high: \"" << high << "\"\n";
			for (long long i = low; i <= high; ++i) {
				if (is_invalid_id(i)) {
					invalidIDs.push_back(i);
					std::cout << i << " ";
				}
			}
			std::cout << "\n";
			for (long long num : invalidIDs) {
				sum += num;
			}
		}
		std::cout << "sum: " << sum << "\n";
	}
	return 0;
}
