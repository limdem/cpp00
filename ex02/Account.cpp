/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgauvin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:59:59 by dgauvin           #+#    #+#             */
/*   Updated: 2022/08/04 17:00:05 by dgauvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts=0;
int	Account::_totalAmount=0;
int	Account::_totalNbDeposits=0;
int	Account::_totalNbWithdrawals=0;

void	Account::_displayTimestamp( void )
{
    time_t curr_time;
	curr_time = time(NULL);

	tm *tm_local = localtime(&curr_time);
    std::cout << '[' << tm_local->tm_year + 1900;
    if ((tm_local->tm_mon + 1) / 10 >= 1)
        std::cout << tm_local->tm_mon + 1;
    else
        std::cout << '0' << tm_local->tm_mon + 1;
    if (tm_local->tm_mday / 10 >= 1)
        std::cout << tm_local->tm_mday;
    else
        std::cout << '0' << tm_local->tm_mday;
    std::cout << '_';
    if (tm_local->tm_hour / 10 >= 1)
        std::cout << tm_local->tm_hour;
    else
        std::cout << '0' << tm_local->tm_hour;
    if (tm_local->tm_min / 10 >= 1)
        std::cout << tm_local->tm_min;
    else
        std::cout << '0' << tm_local->tm_min;
    if (tm_local->tm_sec / 10 >= 1)
        std::cout << tm_local->tm_sec;
    else
        std::cout << '0' << tm_local->tm_sec;
    std::cout << "] ";
}

Account::Account(int initial_deposit)
{
    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    _amount = initial_deposit;
    _totalAmount += _amount;
    Account::_displayTimestamp();
    std::cout <<"index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbWithdrawals()
{
    return (_totalNbWithdrawals);
}

int	Account::getNbDeposits()
{
    return (_totalNbDeposits);
}

int	Account::getTotalAmount()
{
    return (_totalAmount);
}

int	Account::getNbAccounts()
{
    return (_nbAccounts);
}

void Account::displayAccountsInfos()
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus() const
{
    Account::_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
    this->_amount += deposit;
    _totalAmount += deposit;
    this->_nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

int		Account::checkAmount( void ) const
{
    if (this->_amount < 0)
        return (1);
    return (0);
}

bool	Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;
    if (checkAmount())
    {
        this->_amount += withdrawal;
        _totalAmount += withdrawal;
        this->_nbWithdrawals--;
        _totalNbWithdrawals--;
        std::cout << ";withdrawal:refused" << std::endl;
    }
    else
        std::cout << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}
