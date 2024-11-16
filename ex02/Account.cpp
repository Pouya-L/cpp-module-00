/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 00:02:49 by plashkar          #+#    #+#             */
/*   Updated: 2024/11/16 18:03:48 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

/**
 * Static member variables are shared across all instances of the class,
 * and they need to be defined and initialized outside the class definition in
 * a single .cpp file. This ensures they are allocated storage
 * and initialized before they are used.
 */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * on-static member variables of the Account class. Unlike static member variables,
 * these do not need to be initialized outside the class in a .cpp file.
 * Instead, they should be initialized within the class constructor to
 * ensure that every instance of the Account class starts with a well-defined state.
 * @brief the constructor function, sets the non static memeber vars and displays
 * the time stamp, then it prints the info of the account.
 * @param initial_deposit
 * @return Constructors don't have a return value.
 */
Account::Account(int initial_deposit)
{
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount= initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
}

Account::~Account()
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
}

/**
 * @brief Gets the time and prints in to the screen using put_time in a specific format.
 * uses the #include <ctime>, time(), and localtime(*time_t struct)
 * time() gets the current calander time and then stores it in time_t now.
 * the nullptr indicates that time() does not need to store the results in a buffer.
 * localtime() gets a refrence of now and converts it to  the tm struct, with broken down parts
 * strftime() prints the time stored in the tm struct in the format (kinda like printf)
 * but it requires a buffer, so we just make one and make sure it is big enough.
 * @param void
 * @return void
 */
void	Account::_displayTimestamp(void)
{
	char buffer[20];

	std::time_t	now = time(NULL);
	std::tm *local_time = std::localtime(&now);
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", local_time);
	std::cout << "[" << buffer << "] " << std::flush;
}

/**
 * static member variables are shared across all instances of a class,
 * not bound to any specific instance. Therefore, you cannot use this-> to access static members
 */
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);
}

/**
 * @brief prints the info of all the accounts combined, it prints the following:
 * "_nbAccounts" , "_totalAmount", "_totalNbDeposits" and "_totalNbWithdrawals".
 * @param void
 * @return void
 */
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";"
				<< "total:" << Account::getTotalAmount() << ";"
				<< "deposits:" << Account::getNbDeposits() << ";"
				<< "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

/**
 * @brief Makes a deposit and displays the info of the account
 * with index, p_ammount which is the previous ammount, deposit ammount,
 * the current ammount and the number of total deposits
 * it also updates the "_nbDeposits", "_totalNbDeposits" and "_totalAmount"
 * @param deposit the ammount to deposit to the account.
 * @return void
 */
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";" << std::flush;
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount +=deposit;
	std::cout << "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits << std::endl;
}

/**
 * @brief Makes a withdrawal and displays the info of the account
 * with index, p_ammount which is the previous ammount, withdrawal ammount,
 * the current ammount and the number of total withdrawal
 * It checks if a withrawl is possible or not, if not it prints "withdrawal:refused"
 * it also updates the "_nbWithdrawals", "_totalNbWithdrawals" and "_totalAmount"
 * @param withdrawal the ammount to withdraw from the account.
 * @return true if withdrawal was possible and done, false if it was not.
 */
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";" << std::flush;
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal << ";"
					<< "amount:" << _amount << ";"
					<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
}

/**
 * @brief returns the amount of money in that instance of Account class.
 * @param void
 * @return _amount
 */
int		Account::checkAmount(void) const
{
	return (this->_amount);
}

/**
 * @brief Prints the index, the ammount, the number of deposits, the number of withdrawals
 * of an instance of the account class (which would be one of the accounts)
 * @param void
 * @return void
 */
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << checkAmount() << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}
