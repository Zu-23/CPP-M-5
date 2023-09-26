#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> tokenize(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream tokenStream(input);
    std::string token;

    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

int main() {
    std::string date = "2011-31-11";
	size_t pos = date.find('-') + 1;
	int prpos = 0;
	std::string ar[3];
	for(int i = 0; i < 3; i++)
	{
		pos = date.find('-', prpos);
		ar[i] = date.substr(prpos, pos - prpos);
		prpos = pos + 1;
	}
	int year = std::atoi(ar[0].c_str());
    int month = std::atoi(ar[1].c_str());
    int day = std::atoi(ar[2].c_str());
    std::cout << year << " " << month << " " << day << " " << std::endl;
}
