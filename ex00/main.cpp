#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	   std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string currentArg = argv[i];
			int currentArgLength = currentArg.length();
			for (int i = 0; i < currentArgLength; i++)
				std::cout << static_cast<char>(toupper(currentArg[i]));
		}
		std::cout << std::endl;
	}
}
