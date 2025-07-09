/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:43:10 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/07/09 12:14:28 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

size_t Contact::check_number(std::string prompt)
{
	for(size_t i = 0; prompt[i]; i++)
	{
		if(std::isdigit(prompt[i]) == 0)
			return 1;
	}
	return 0;
}

void Contact::display()
{
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phonenumber << std::endl;
	std::cout << "Darkest Secret: " << darksecret << std::endl;
}

std::string Contact::trunc(int option)
{
	std::string arg;
	if(option == 1)
		arg = first_name;
	else if(option == 2)
		arg = last_name;
	else if(option == 3)
		arg = nickname;
	if(arg.size() >= 10)
		return (arg.substr(0, 9) + ".");
	else
		return arg;
}

void Contact::getinfo()
{
	first_name = getstring("Please input your first name: ");
	last_name = getstring("Please input your last name: ");
	nickname = getstring("Please input your nickname: ");
	phonenumber = getnumber("Please input your phone number: ");
	darksecret = getstring("Please input your darkest secret: ");
}

std::string Contact::getnumber(std::string prompt)
{
	std::string input;
	while(std::cin)
	{
		std::cout << prompt;
		if(!std::getline(std::cin, input))
			break;
		if((!input.empty() && check_number(input) == 0))
			break;
		std::cout << "Input cannot be empty and must be only digits." << std::endl;
	}
	return input;
}

std::string Contact::getstring(std::string prompt)
{
	std::string input;
	while(std::cin)
	{
		std::cout << prompt;
		if(!std::getline(std::cin, input))
			break;
		if(!input.empty() && !input.find_first_not_of(' ', 0) && !input.find_first_not_of('\t', 0))
			break;
		std::cout << "Input cannot be empty." << std::endl;
	}
	return input;
}
