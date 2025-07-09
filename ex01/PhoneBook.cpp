/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:40:22 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/07/09 12:14:59 by aaleixo-         ###   ########.fr       */
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
	contacts[i]->getinfo();
	if(i < 7)
		i++;
	else
		i = 0;
}

void PhoneBook::SEARCH()
{
	std::string input;
	int res = -1;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::right << std::setw(10) << "Index";
	std::cout << "|" << std::right << std::setw(10) << "First Name";
	std::cout << "|" << std::right << std::setw(10) << "Last Name";
	std::cout << "|" << std::right << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for(int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::right << std::setw(10) << i;
		std::cout << "|" << std::right << std::setw(10) << contacts[i]->trunc(1);
		std::cout << "|" << std::right << std::setw(10) << contacts[i]->trunc(2);
		std::cout << "|" << std::right << std::setw(10) << contacts[i]->trunc(3) << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	while(std::cin)
	{
		std::cout << "Input index: ";
		if(!std::getline(std::cin, input))
			break;
		if(input.length() == 1)
			res = input[0] - '0';
		if(res >= 0 && res <= 7)
		{
			contacts[res]->display();
			break;
		}
		else
			std::cout << "Invalid index." << std::endl;
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
	while(std::cin)
	{
		std::cout << "What would you like to do? (ADD | SEARCH | EXIT): ";
		if(!std::getline(std::cin, input))
			break;
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
