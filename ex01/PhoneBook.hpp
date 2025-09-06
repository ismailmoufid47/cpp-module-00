#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;
    int nextIndex;
    
    std::string truncateString(const std::string& str, size_t width) const;
    std::string formatColumn(const std::string& str, size_t width) const;
    
public:
    PhoneBook();
    ~PhoneBook();
    
    void addContact(const Contact& contact);
    void displayContacts() const;
    void displayContact(int index) const;
    int getContactCount() const;
};

#endif