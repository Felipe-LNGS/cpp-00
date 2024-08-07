#include "Contact.hpp"

// Constructeur par defaut
Contact::Contact() {}

// Constructeur avec parametres
Contact::Contact(const std::string &firstName, const std::string &lastName, const std::string &nickName, const std::string &phoneNumber, const std::string &darkestSecret) {
    setFirstName(firstName);
    setLastName(lastName);
    setNickName(nickName);
    setPhoneNumber(phoneNumber);
    setDarkestSecret(darkestSecret);
}

// Destructeur
Contact::~Contact() {}

// Setters
void Contact::setFirstName(const std::string &firstName) {
    this->firstname = firstName;
}

void Contact::setLastName(const std::string &lastName) {
    this->lastname = lastName;
}

void Contact::setNickName(const std::string &nickName) {
    this->nickname = nickName;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
    this->phonenumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
    this->darkestsecret = darkestSecret;
}

//getters
std::string Contact::getFirstName() const { 
    return this->firstname; }

std::string Contact::getLastName() const { 
    return this->lastname; }

std::string Contact::getNickName() const { 
    return this->nickname; }

std::string Contact::getDarkestSecret() const { 
    return this->darkestsecret; }

std::string Contact::getPhoneNumber() const { 
    return this->phonenumber; }

std::string Contact::getValidInput(const std::string &prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof()) 
            exit(EXIT_FAILURE);
        if (!input.empty()) 
            return input;
         else 
            std::cerr << RED + "Invalid format. Please enter a non-empty value."+ RESET << std::endl;
    }
}

bool Contact::isValidPhoneNumber(const std::string &number, size_t Length) {
    if (number.length() != Length)
        return false;
    for (char ch : number) {
        if (!(ch >= '0' && ch <= '9')) {
            return false;
        }
    }
    return true;
}

void Contact::inputContact() {
    firstname = getValidInput(GREEN + "First name: " + RESET);
    lastname = getValidInput(GREEN +"Last name: "+ RESET);
    nickname = getValidInput(GREEN +"Nickname: "+ RESET);
    darkestsecret = getValidInput(GREEN +"Darkest secret: "+ RESET);

    while (true) {
        phonenumber = getValidInput(GREEN +"Phone number: "+ RESET);
        if (isValidPhoneNumber(phonenumber, 10)) {
            break;
        } else {
            std::cout << RED + "Invalid phone number format."+ RESET << std::endl;
        }
    }
}

void Contact::displayContact() const {
    std::cout << "+---------------------+" << std::endl;
    std::cout << "| " << BLUE << std::setw(16) << "First name:" << RESET << " " << std::setw(10) << firstname << " |" << std::endl;
    std::cout << "+---------------------+" << std::endl;
    std::cout << "| " << BLUE << std::setw(16) << "Last name:" << RESET << " " << std::setw(10) << lastname << " |" << std::endl;
    std::cout << "+---------------------+" << std::endl;
    std::cout << "| " << BLUE << std::setw(16) << "Nickname:" << RESET << " " << std::setw(10) << nickname << " |" << std::endl;
    std::cout << "+---------------------+" << std::endl;
    std::cout << "| " << BLUE << std::setw(16) << "Darkest secret:" << RESET << " " << std::setw(10) << darkestsecret << " |" << std::endl;
    std::cout << "+---------------------+" << std::endl;
    std::cout << "| " << BLUE << std::setw(16) << "Phone number:" << RESET << " " << std::setw(10) << phonenumber << " |" << std::endl;
    std::cout << "+---------------------+" << std::endl;
}


