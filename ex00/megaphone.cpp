#include <cctype>
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; ++i)
		{
			std::string arg = av[i];
			for (char &ch : arg)
			{
				ch = std::toupper(ch);
			}
			std::cout << arg;
		}
	}
	std::cout << std::endl;
	return (0);
}
