#include "Contact.hpp"

void Contact::setFirstName(const std::string& firstName)
{
	this->firstName = firstName;
}

void Contact::setLastName(const std::string& lastName)
{
	this->lastName = lastName;
}

void Contact::setNickname(const std::string& nickname)
{
	this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}

bool Contact::isEmpty() const
{
	return firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty();
}

void Contact::displayFullInfo() const
{
	std::cout << BOLD_TEXT("First Name: ") << firstName << std::endl;
	std::cout << BOLD_TEXT("Last Name: ") << lastName << std::endl;
	std::cout << BOLD_TEXT("Nickname: ") << nickname << std::endl;
	std::cout << BOLD_TEXT("Phone Number: ") << phoneNumber << std::endl;
	std::cout << BOLD_TEXT("Darkest Secret: ") << darkestSecret << std::endl;
}