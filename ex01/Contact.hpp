#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <limits>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";

class Contact {

private:
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::string darkestsecret;
    std::string phonenumber;

public:
    
    Contact();
    ~Contact();
    void inputContact();
    void displayContact() const;

    std::string getFirstname() const;
    std::string getLastname() const;
    std::string getNickname() const;
    std::string getDarkestSecret() const;
    std::string getPhonenumber() const;
};

#endif // CONTACT_HPP
