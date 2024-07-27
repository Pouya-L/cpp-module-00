/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:32:38 by plashkar          #+#    #+#             */
/*   Updated: 2024/07/26 20:38:31 by plashkar         ###   ########.fr       */
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
