#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define CONTACTS_MAX 8

class PhoneBook{
  
  private:

	Contact contacts_book[CONTACTS_MAX];
  
  public:
	PhoneBook();
	~PhoneBook();
	int 	addContact(int index);
	void 	displayContactindice(int index)const;	
	void 	displayContacts()const;
};

#endif