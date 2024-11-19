/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:23:12 by plashkar          #+#    #+#             */
/*   Updated: 2024/11/19 13:50:31 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	// std::cout << "Contact constructor called" << std::endl;
}

Contact::~Contact()
{
	// std::cout << "Contact deconstructor called" << std::endl;
}

bool		Contact::isAllDigits(std::string& input)
{
	std::string::size_type	i = 0;

	while (i < input.length())
	{
		if (!isdigit(input[i]))
		{
			std::cout << "The input must be all digits, please try again." << std::endl;
			return (false);
		}
		i++;
	}
	return (true);
}

std::string	Contact::getInput(std::string msg, int flag)
{
	std::string				input;
	bool					validInput = false;

	do {
		std::cout << msg;
		std::getline(std::cin, input);
		if (std::cin.eof() || std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (std::cin.eof())
			{
				std::cout << std::endl;
				break ;
			}
			std::cout << "Invalid input; please try again." << std::endl;
			continue ;
		}
		if (flag == 1)
		{
			if (!isAllDigits(input))
			{
				validInput = false;
				continue ;
			}
				validInput = true;
		}
		else
		{
			validInput = true;
		}
	} while (input.empty() || !validInput);
	return (input);
}

std::string	Contact::printLen(std::string str)
{
	if (str.length() > 10)
		return	(str.substr(0, 9) + ".");
	else
		return (str);
}

void	Contact::init(void)
{
	this->firstName = this->getInput("Please enter the first name: ", 0);
	if (this->firstName == "")
		return ;
	this->lastName = this->getInput("Please enter the last name: ", 0);
	if (this->lastName == "")
		return ;
	this->nickName = this->getInput("Please enter a nickname for them: ", 0);
	if (this->nickName == "")
		return ;
	this->phoneNumber = this->getInput("Please enter the phone number: ", 1);
	if (this->phoneNumber == "")
		return ;
	this->darkestSecret = this->getInput("Please enter their darkest secret: ", 0);
	if (this->darkestSecret == "")
		return ;
}

void	Contact::setIndex(int index)
{
	this->index = index;
}

void	Contact::viewTable(int index)
{
	if (this->firstName.empty() || this->lastName.empty() || this->nickName.empty())
		return ;
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << this->printLen(this->firstName) << std::flush;
	std::cout << "|" << std::setw(10) << this->printLen(this->lastName) << std::flush;
	std::cout << "|" << std::setw(10) << this->printLen(this->nickName) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::displayContact(int	index)
{
	if (this->firstName.empty())
	{
		std::cout << "There is no entry for that index" << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "Contact #" << index << std::endl;
	std::cout << "First name: " << this->firstName << std::endl;
	std::cout << "Last name: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickName << std::endl;
	std::cout << "Phone number: " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->darkestSecret << std::endl;
	std::cout << std::endl;
}

