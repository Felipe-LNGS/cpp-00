#include "Contact.hpp"

Contact::Contact(){

}

Contact::~Contact() {
    std::cout << "Destructeur" << std::endl;
}

bool isValidPhoneNumber(const std::string &number, size_t maxLength) {
    if (number.length() > maxLength) 
        return false;
    for (char ch : number) {
        if (!(ch >= '0' && ch <= '9') && ch != '.')
            return false;
    }
    return true;
}

void Contact::inputContact() {
    auto getValidInput = [](const std::string& prompt) -> std::string {
        std::string input;
        while (true) {
            std::cout << prompt;
            std::getline(std::cin, input);

            if (std::cin.eof()) {
                std::cerr << "EOF. Exiting input." << std::endl;
                exit(EXIT_FAILURE);
            }

            if (!input.empty()) {
                return input;
            } else {
                std::cerr << "Invalid format. Please enter a non-empty value." << std::endl;
            }
        }
    };


    firstname = getValidInput(GREEN + "First name: " + RESET);
    lastname = getValidInput(GREEN + "Last name: " + RESET);
    nickname = getValidInput(GREEN + "Nickname: " + RESET);
    darkestsecret = getValidInput(GREEN + "Darkest secret: " + RESET);

    while (true) {
        phonenumber = getValidInput(GREEN + "Phone number: " + RESET);
        if (isValidPhoneNumber(phonenumber, 16)) {
            break;
        } else {
            std::cout << RED << "Invalid phone number format or exceeds 16 characters. Please enter again." << RESET << std::endl;
        }
    }
}

void Contact::displayContact() const {
    std::cout << BLUE << "First name: " << RESET << firstname << std::endl;
    std::cout << BLUE << "Last name: " << RESET << lastname << std::endl;
    std::cout << BLUE << "Nickname: " << RESET << nickname << std::endl;
    std::cout << BLUE << "Darkest secret: " << RESET << darkestsecret << std::endl;
    std::cout << BLUE << "Phone number: " << RESET << phonenumber << std::endl;
}

std::string Contact::getFirstname() const { return firstname; }
std::string Contact::getLastname() const { return lastname; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getDarkestSecret() const { return darkestsecret; }
std::string Contact::getPhonenumber() const { return phonenumber; }
