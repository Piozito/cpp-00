/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:43:10 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/07/03 16:14:03 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

size_t PhoneBook::check_number(std::string prompt)
{
	for(size_t i = 0; prompt[i]; i++)
	{
		if(std::isdigit(prompt[i]) == 0)
			return 1;
	}
	return 0;
}

std::string PhoneBook::getnumber(std::string prompt)
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

void PhoneBook::display(int input)
{
	std::cout << "First name: " << contacts[input]->first_name << std::endl;
	std::cout << "Last name: " << contacts[input]->last_name << std::endl;
	std::cout << "Nickname: " << contacts[input]->nickname << std::endl;
	std::cout << "Phone number: " << contacts[input]->phonenumber << std::endl;
	std::cout << "Darkest Secret: " << contacts[input]->darksecret << std::endl;
}

std::string PhoneBook::trunc(std::string arg)
{
	if(arg.size() >= 10)
		return (arg.substr(0, 9) + ".");
	else
		return arg;
}

std::string PhoneBook::getstring(std::string prompt)
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
