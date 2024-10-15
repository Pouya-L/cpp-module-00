/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:39:23 by plashkar          #+#    #+#             */
/*   Updated: 2024/10/15 09:13:37 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main(void)
{
	Phonebook yellowPages;
	std::string input = "";
	yellowPages.welcome_msg();
	while (true)
	{
		std::cout << GREEN <<"> " << RESET;
		std::getline(std::cin, input);
		if (std::cin.eof()) {
			std::cout << RED << "EOF detected. Exiting the program." << RESET << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break ;
		}
		if (input == "ADD")
			yellowPages.addContact();
		if (input == "SEARCH") {
			yellowPages.printTable();
			yellowPages.search();
		}
		if (input == "EXIT") {
			std::cout << YELLOW << "I'll be back..." << RESET << std::endl;
			return(0);
		}
	}
	return (0);
}
