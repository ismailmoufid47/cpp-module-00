#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0), nextIndex(0) {}

void PhoneBook::addContact(const Contact &contact)
{
	contacts[nextIndex] = contact;
	nextIndex = (nextIndex + 1) % 8;

	if (contactCount < 8)
		contactCount++;
}

std::string PhoneBook::truncateString(const std::string &str, size_t width) const
{
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";

	return str;
}

void PhoneBook::displayContacts() const
{
	if (contactCount == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}

	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < contactCount; i++)
	{
		if (!contacts[i].isEmpty())
		{
			std::cout << std::setw(10) << i << "|";
			std::cout << std::setw(10) << truncateString(contacts[i].getFirstName(), 10) << "|";
			std::cout << std::setw(10) << truncateString(contacts[i].getLastName(), 10) << "|";
			std::cout << std::setw(10) << truncateString(contacts[i].getNickname(), 10) << std::endl;
		}
	}
}

void PhoneBook::displayContact(int index) const
{
	contacts[index].displayFullInfo();
}

int PhoneBook::getContactCount() const
{
	return contactCount;
}