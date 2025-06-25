/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:40:22 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/06/25 18:34:09 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	for(int i = 0; i < 8; i++)
		contacts[i] = new Contact();
}

PhoneBook::~PhoneBook()
{
	for(int i = 0; i < 8; i++)
		delete contacts[i];
}

Contact::Contact()
{
	first_name = "";
	last_name = "";
	nickname = "";
	phonenumber = "";
	darksecret = "";
}

void PhoneBook::ADD()
{
	static int i = 0;
	contacts[i]->first_name = getstring("Please input your first name: ");
	contacts[i]->last_name = getstring("Please input your last name: ");
	contacts[i]->nickname = getstring("Please input your nickname: ");
	contacts[i]->phonenumber = getnumber("Please input your phone number: ");
	contacts[i]->darksecret = getstring("Please input your darkest secret: ");
	if(i < 7)
		i++;
	else
		i = 0;
}

void PhoneBook::SEARCH()
{
	int input = 0;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::right << std::setw(10) << "Index";
	std::cout << "|" << std::right << std::setw(10) << "First Name";
	std::cout << "|" << std::right << std::setw(10) << "Last Name";
	std::cout << "|" << std::right << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for(int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::right << std::setw(10) << i + 1;
		std::cout << "|" << std::right << std::setw(10) << trunc(contacts[i]->first_name);
		std::cout << "|" << std::right << std::setw(10) << trunc(contacts[i]->last_name);
		std::cout << "|" << std::right << std::setw(10) << trunc(contacts[i]->nickname) << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	for(int i = 0; i == 0;)
	{
		std::cout << "Input index: ";
		std::cin >> input;
		if(input > 0 && input < 9)
		{
			display(input - 1);
			i = 1;
		}
		else
			std::cout << "Invalid index." << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}
}

void intro()
{
	std::cout << "---------------------------------------------------------------" << std::endl;
	std::cout << "|      ____  __  ______  _   ____________  ____  ____  __ __  |" << std::endl;
	std::cout << "|     / __ \\/ / / / __ \\/ | / / ____/ __ )/ __ \\/ __ \\/ //_/  |" << std::endl;
	std::cout << "|    / /_/ / /_/ / / / /  |/ / __/ / __  / / / / / / / , |    |" << std::endl;
	std::cout << "|   / ____/ __  / /_/ / /|  / /___/ /_/ / /_/ / /_/ / /| |    |" << std::endl;
	std::cout << "|  /_/   /_/ /_/\\____/_/ |_/_____/_____/\\____/\\____/_/ |_|    |" << std::endl;
	std::cout << "|                                                             |" << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
}

int main()
{
	PhoneBook phone;
	std::string input;

	intro();
	while(1)
	{
		std::cout << "What would you like to do? (ADD | SEARCH | EXIT): ";
		std::getline(std::cin, input);
		if(input == "ADD")
			phone.ADD();
		else if(input == "SEARCH")
			phone.SEARCH();
		else if(input == "EXIT")
		{
			std::cout << "Until next time!" << std::endl;
			break;
		}
		else
			std::cout << "Invalid input." << std::endl;
	}
	return 0;
}