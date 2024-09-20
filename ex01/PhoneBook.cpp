#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	for (int i = 0; i < CONTACTS_MAX; ++i)
	{
		contacts_book[i] = Contact();
	}
}

PhoneBook::~PhoneBook()
{
}

std::string truncateString(const std::string &text, std::size_t width)
{
	if (text.length() > width)
	{
		return (text.substr(0, width - 1) + '.');
	}
	return (text);
}

// Fonction pour afficher les contacts
void PhoneBook::displayContacts() const
{
	std::cout << "+------------+------------+------------+------------+" << std::endl;
	std::cout << "| " << BLUE << std::setw(10) << "Index" << RESET << " | " << BLUE << std::setw(10) << "First Name" << RESET << " | " << BLUE << std::setw(10) << "Last Name" << RESET << " | " << BLUE << std::setw(10) << "Nickname" << RESET << " |" << std::endl;
	std::cout << "+------------+------------+------------+------------+" << std::endl;

	for (int i = 0; i < CONTACTS_MAX; ++i)
	{
		if (!contacts_book[i].getFirstName().empty())
		{
			std::cout << "| " << std::setw(10) << i
				+ 1 << " | " << std::setw(10) << truncateString(contacts_book[i].getFirstName(),
				10) << " | " << std::setw(10) << truncateString(contacts_book[i].getLastName(),
				10) << " | " << std::setw(10) << truncateString(contacts_book[i].getNickName(),
				10) << " |" << std::endl;
		}
	}

	std::cout << "+------------+------------+------------+------------+" << std::endl;
}

int PhoneBook::addContact(int index)
{
	Contact	new_contact;

	if (index >= CONTACTS_MAX)
	{
		index = 0;
	}
	
	if (new_contact.inputContact() == 1)
		return -1;
	contacts_book[index] = new_contact;
	index++;
	return (index);
}

// afficher un contact à un index donné
void PhoneBook::displayContactindice(int index) const
{
	while (true)
	{
		std::cout << "Enter the index of the contact you want to view: ";
		std::cin >> index;
		if (std::cin.eof())
			exit(1);
		if (std::cin.fail() || index < 1 || index > CONTACTS_MAX
			|| contacts_book[index - 1].getFirstName().empty())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << RED + "Invalid contact index. Please try again."
				+ RESET << std::endl;
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			contacts_book[index - 1].displayContact();
			break ;
		}
	}
}
