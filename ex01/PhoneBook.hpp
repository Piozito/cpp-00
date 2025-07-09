/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:40:11 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/07/09 12:28:05 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phonenumber;
		std::string darksecret;
	public:
		void getinfo();
		void display();
		std::string trunc(int option);
		std::string getstring(std::string prompt);
		std::string getnumber(std::string prompt);
		size_t check_number(std::string prompt);
		Contact();
};

class PhoneBook
{
	private:
		Contact *contacts[8];
	public:
		void SEARCH();
		void ADD();
		PhoneBook();
		~PhoneBook();
};

#endif