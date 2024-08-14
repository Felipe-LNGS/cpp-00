#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string BOLD = "\033[1m";
const std::string UNDERLINE = "\033[4m";

class Contact {

private:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string darkestsecret;
    std::string phonenumber;

public:
    
    Contact();

    // Constructeur avec parametres
    Contact(const std::string &firstName, const std::string &lastName, const std::string &nickName, const std::string &phoneNumber, const std::string &darkestSecret);

    // Destructeur
    ~Contact();

    bool isValidPhoneNumber(const std::string &number, size_t Length);
    std::string getValidInput(const std::string &prompt);
    void inputContact();
    void displayContact() const;

    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setNickName(const std::string &nickName);
    void setPhoneNumber(const std::string &phoneNumber);
    void setDarkestSecret(const std::string &darkestSecret);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getDarkestSecret() const;
    std::string getPhoneNumber() const;
};

#endif
