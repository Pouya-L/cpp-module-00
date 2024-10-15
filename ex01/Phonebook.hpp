/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:32:38 by plashkar          #+#    #+#             */
/*   Updated: 2024/10/15 09:15:20 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook
{
private:
	Contact contacts[8];

	int	getInputIndex(void);
public:
	Phonebook();
	~Phonebook();
	void	welcome_msg(void);
	void	addContact(void);
	void	printTable(void);
	void	search(void);
};

#endif //PHONEBOOK_HPP
