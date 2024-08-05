#include "Contact.hpp"

int main() {
    Contact contact;
    
    // Saisie des informations de contact
    contact.inputContact();
    
    // Affichage des informations de contact
    contact.displayContact();

    // Accès aux données via les getters
    std::cout << "Access via getter - First name: " << contact.getFirstname() << std::endl;
    
    return 0;
}
