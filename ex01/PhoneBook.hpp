/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 15:40:11 by aaleixo-          #+#    #+#             */
/*   Updated: 2025/06/25 17:40:51 by aaleixo-         ###   ########.fr       */
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
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phonenumber;
		std::string darksecret;
		Contact();
};

class PhoneBook
{
	private:
		void display(int index);
		std::string trunc(std::string arg);
		std::string getstring(std::string prompt);
		std::string getnumber(std::string prompt);
		size_t check_number(std::string prompt);
	public:
		Contact *contacts[8];

		PhoneBook();
		~PhoneBook();
		void ADD();
		void SEARCH();
};

#endif