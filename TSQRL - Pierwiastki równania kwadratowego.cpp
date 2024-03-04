#include <iostream>
#include <string>

std::string convertBase(std::string n, int fromBase, int toBase) {
	if (n == "0") {
		return "0";
	}

	const std::string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string result = "";
	int itr = 0;

	while (n != "\0") {
		int digit = 0;

		for (int i = 0; i < n.size(); ++i) {
			digit = digit * fromBase + digits.find(n[i]);
			n[i] = digits[digit / toBase];
			digit %= toBase;
		}

		result = digits[digit] + result;

		while (n.size() > 0 && n[0] == '0') {
			n.erase(0, 1);
		}
	}
	return result;
}

int main() {
	int itr_number;
	std::string n, r, s;
	std::cin >> itr_number;
	for (int i = 0; i < itr_number; i++) {
		std::cin >> n >> r >> s;
		std::string result = convertBase(n, std::stoi(r), std::stoi(s));
		std::cout << result << std::endl;
	}
	return 0;
}