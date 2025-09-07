#include "macros.hpp"
#include <iostream>

std::string filterString(const std::string& str)
{
	std::string result;
	for (size_t i = 0; i < str.length(); i++)
		if (str[i] >= 33 && str[i] <= 126)
			result += str[i];
	return result;
}

std::string getInput(const std::string& prompt)
{
	std::string input;
	
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		if (!input.empty())
			return filterString(input);
		if (std::cin.eof())
		{
			freopen("/dev/tty", "r", stdin);
			std::cin.clear();
			return "";
		}
		std::cout << CLEAR_SCREEN "Field cannot be empty. Please try again." << std::endl;
	}
}

std::string truncateString(const std::string& str, size_t width)
{
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";

	return str;
}