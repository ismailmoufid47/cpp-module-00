#include "PhoneBook.hpp"

Contact createContact()
{
	Contact contact;

	std::string firstName = getInput(ENTER("first name"));
	contact.setFirstName(firstName);

	if (firstName.empty())
		return contact;

	std::string lastName = getInput(ENTER("last name"));
	contact.setLastName(lastName);

	if (lastName.empty())
		return contact;

	std::string nickname = getInput(ENTER("nickname"));
	contact.setNickname(nickname);

	if (nickname.empty())
		return contact;

	std::string phoneNumber = getInput(ENTER("phone number"));

	bool allDigits = true;
	for (size_t i = 0; i < phoneNumber.length(); i++)
	{
		if (!isdigit(phoneNumber[i]))
		{
			allDigits = false;
			break;
		}
	}
	if (!allDigits)
	{
		std::cout << CLEAR_SCREEN "Phone number must contain only digits. Please try again." << std::endl;
		return createContact();
	}
	contact.setPhoneNumber(phoneNumber);

	if (phoneNumber.empty())
		return contact;

	std::string darkestSecret = getInput(ENTER("darkest secret"));
	contact.setDarkestSecret(darkestSecret);
	return contact;
}

void handleSearch(const PhoneBook &phoneBook)
{
	phoneBook.displayContacts();
	if (phoneBook.getContactCount() == 0)
		return;
	std::string input = getInput(ENTER("contact index to view details"));
	std::cout << CLEAR_SCREEN;
	if (input.empty())
	{
		std::cout << "Operation cancelled." << std::endl;
		return;
	}
	bool allDigits = true;
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]))
		{
			allDigits = false;
			break;
		}
	}
	if (!allDigits)
	{
		std::cout << "Invalid input. Please enter a valid index." << std::endl;
		handleSearch(phoneBook);
		return;
	}
	
	int index;
	try
	{
		index = std::stoi(input);
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Number too large. Please enter a valid index." << std::endl;
		handleSearch(phoneBook);
		return;
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << "Invalid input. Please enter a valid index." << std::endl;
		handleSearch(phoneBook);
		return;
	}
	if (index < 0 || index >= phoneBook.getContactCount())
	{
		std::cout << "Index out of range. Please try again." << std::endl;
		handleSearch(phoneBook);
		return;
	}
	phoneBook.displayContact(index);
}

int main()
{
	PhoneBook phoneBook;
	std::string command;

	std::cout << CLEAR_SCREEN "Welcome to My Awesome PhoneBook!" << std::endl;

	while (true)
	{
		std::string command = getInput("\nAvailable commands: ADD, SEARCH, EXIT\n" ENTER("command"));

		if (command == "ADD")
		{
			Contact contact = createContact();
			if (contact.isEmpty())
			{
				std::cout << CLEAR_SCREEN "Contact creation cancelled." << std::endl;
				continue;
			}
			phoneBook.addContact(contact);
			std::cout << CLEAR_SCREEN "Contact added successfully!" << std::endl;
		}

		else if (command == "SEARCH")
		{
			std::cout << CLEAR_SCREEN;
			handleSearch(phoneBook);
		}

		else if (command == "EXIT")
		{
			std::cout << CLEAR_SCREEN BOLD_TEXT("Goodbye!") << std::endl;
			break;
		}
		else if (command.empty())
			std::cout << CLEAR_SCREEN "To quit the program, type EXIT." << std::endl;
		else
			std::cout << CLEAR_SCREEN "Invalid command." << std::endl;
	}
}