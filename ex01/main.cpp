#include "Contact.hpp"
#include "PhoneBook.hpp"

void	menu(void)
{
	std::cout << BLUE << "+-----------------------------+" << RESET << std::endl;
	std::cout << BLUE << "| " << BOLD << "    Available Commands" << RESET << BLUE << "      |" << RESET << std::endl;
	std::cout << BLUE << "+-----------------------------+" << RESET << std::endl;
	std::cout << BLUE << "| " << GREEN << "ADD" << RESET << BLUE << "    | " << YELLOW << "Add a new contact" << RESET << BLUE << "  |" << RESET << std::endl;
	std::cout << BLUE << "| " << GREEN << "SEARCH" << RESET << BLUE << " | " << YELLOW << "Search contacts" << RESET << BLUE << "    |" << RESET << std::endl;
	std::cout << BLUE << "| " << GREEN << "EXIT" << RESET << BLUE << "   | " << YELLOW << "Exit the program" << RESET << BLUE << "   |" << RESET << std::endl;
	std::cout << BLUE << "+-----------------------------+" << RESET << std::endl;
}
int	main(void)
{
	static PhoneBook phonebook;
	std::string command;
	int index;

	index = 0;
	system("clear");

	while (true)
	{
		menu();
		std::cout << "Enter your command: ";
		if (!std::getline(std::cin, command))
		{
			std::cout << std::endl;
			break ;
		}
		if (command == "ADD")
		{
			{
				index = phonebook.addContact(index);
				if (index == -1)
					break ;
			}
		}
		else if (command == "SEARCH")
		{
			if (index == 0)
				std::cout << RED
					+ "You need to have at least one contact to check the phonebook."
					+ RESET << std::endl;
			else
			{
				phonebook.displayContacts();
				phonebook.displayContactindice(index);
			}
		}
		else if (command == "EXIT")
		{
			break ;
		}
		else
		{
			std::cout << "Invalid command. Please try again." << std::endl;
		}
	}

	return (0);
}
