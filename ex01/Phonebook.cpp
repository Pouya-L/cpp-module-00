/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:30:29 by plashkar          #+#    #+#             */
/*   Updated: 2024/07/26 23:49:25 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	// std::cout << "Phonebook constructor called" << std::endl;
}

Phonebook::~Phonebook()
{
	// std::cout << "Phonebook deconstructor called" << std::endl;
}

int	Phonebook::getInputIndex(void)
{
	bool	valid = false;
	int		input = -1;

	do {
		std::cout << "Please enter the contact index: " << std::flush;
		if (!(std::cin >> input))
		{
			if (std::cin.eof()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				return (-1);
			}
			else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input; please try again." << std::endl;
			}
		}
		else if (input >= 0 && input <= 7)
			valid = true;
		else
			std::cout << "Input was out of range; please try again." << std::endl;
	} while (!valid);
	return (input);
}

void	Phonebook::welcome_msg(void)
{
	std::cout << YELLOW;
	std::cout << "┌───────────────────────────────────────────────────────┐" << std::endl;
	std::cout << "|             Welcome to the 80s phonebook!             |" << std::endl;
	std::cout << "|"<< std::setw(56) << "|" << std::endl;
	std::cout << "|   __i   " << GREEN << " List of commands ⇓";
	std::cout << std::setw(34) << YELLOW << "|" << std::endl;
	std::cout << "|  |---|  " << GREEN << "ADD    : to add a contact";
	std::cout << std::setw(28) << YELLOW << "|" << std::endl;
	std::cout << "|  |[_]|  " << GREEN << "SEARCH : to search and show details";
	std::cout << std::setw(18) << YELLOW << "|" << std::endl;
	std::cout << "|  |:::|  " << GREEN << "EXIT   : to exit the program";
	std::cout << std::setw(25) << YELLOW << "|" << std::endl;
	std::cout << "|  |:::|  ";
	std::cout << std::setw(53) << YELLOW << "|" << std::endl;
	std::cout << "|  `\\   \\  ";
	std::cout << std::setw(52) << YELLOW << "|" << std::endl;
	std::cout << "|    \\_=_\\                               by plashkar";
	std::cout << std::setw(11) << YELLOW << "|" << std::endl;
	std::cout << "|"<< std::setw(56) << "|" << std::endl;
	std::cout << "└───────────────────────────────────────────────────────┘" << RESET << std::endl;
}

void	Phonebook::addContact(void)
{
	static int	i;
	this->contacts[i % 8].init();
	this->contacts[i % 8].setIndex(i % 8);
	i++;
}

void	Phonebook::printTable(void)
{
	int	i = 0;
	std::cout << "┌───────────────────────────────────────────┐" << std::endl;
	std::cout << "|" << " Contacts " << std::setw(34) << "|" << std::endl;
	std::cout << "|───────────────────────────────────────────|" << std::endl;
	// std::cout << "|" << std::setw(44) << "|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|──────────|──────────|──────────|──────────|" << std::endl;
	while (i < 8)
	{
		this->contacts[i].viewTable(i);
		i++;
	}
	std::cout << "└───────────────────────────────────────────┘" << std::endl;
	std::cout << std::endl;
}

void	Phonebook::search(void)
{
	int i = this->getInputIndex();
	if (i < 0)
		return ;
	this->contacts[i].displayContact(i);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

