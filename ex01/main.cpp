#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

std::string getInput(const std::string& prompt) {
    std::string input;
    
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        
        if (std::cin.eof()) {
            std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
            exit(0);
        }
        
        if (!input.empty()) {
            return input;
        }
        
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
}

Contact createContact() {
    Contact contact;
    
    std::string firstName = getInput("Enter first name: ");
    contact.setFirstName(firstName);
    
    std::string lastName = getInput("Enter last name: ");
    contact.setLastName(lastName);
    
    std::string nickname = getInput("Enter nickname: ");
    contact.setNickname(nickname);
    
    std::string phoneNumber = getInput("Enter phone number: ");
    contact.setPhoneNumber(phoneNumber);
    
    std::string darkestSecret = getInput("Enter darkest secret: ");
    contact.setDarkestSecret(darkestSecret);
    
    return contact;
}

void handleSearch(const PhoneBook& phoneBook) {
    phoneBook.displayContacts();
    
    if (phoneBook.getContactCount() == 0) {
        return;
    }
    
    std::cout << "Enter index of contact to display: ";
    std::string input;
    std::getline(std::cin, input);
    
    if (std::cin.eof()) {
        std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
        exit(0);
    }
    
    std::stringstream ss(input);
    int index;
    
    if (ss >> index && ss.eof()) {
        phoneBook.displayContact(index);
    } else {
        std::cout << "Invalid index format!" << std::endl;
    }
}

int main() {
    PhoneBook phoneBook;
    std::string command;
    
    std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
    std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
    
    while (true) {
        std::cout << std::endl << "Enter command: ";
        std::getline(std::cin, command);
        
        if (std::cin.eof()) {
            std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
            break;
        }
        
        if (command == "ADD") {
            Contact contact = createContact();
            phoneBook.addContact(contact);
            std::cout << "Contact added successfully!" << std::endl;
        }
        else if (command == "SEARCH") {
            handleSearch(phoneBook);
        }
        else if (command == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        else if (!command.empty()) {
            std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    
    return 0;
}