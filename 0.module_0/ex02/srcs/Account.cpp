#include "../includes/Account.Class.hpp"
#include <ctime>
#include <iostream>

int	Account::_totalNbWithdrawals = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalAmount = 0;
int	Account::_nbAccounts = 0;

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout	<< "accounts:"
				<< Account::getNbAccounts()
				<< ";total:"
				<< Account::getTotalAmount()
				<< ";deposits:"
				<< Account::getNbDeposits()
				<< ";withdrawals:"
				<< Account::getNbWithdrawals()
				<< std::endl;
}

Account::Account(int initial_deposit)	:	_nbWithdrawals(0),
											_accountIndex(_nbAccounts),
											_nbDeposits(0),
											_amount(initial_deposit)
{
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;

	_displayTimestamp();
	std::cout	<< "index:"
				<< this->_accountIndex
				<< ";amount:"
				<< this->_amount
				<< ";created"
				<< std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout	<< "index:"
				<< this->_accountIndex
				<< ";amount:"
				<< this->_amount
				<< ";closed"
				<< std::endl;
	Account::_nbAccounts--;
	Account::_amount -= this->_amount;
}

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	_displayTimestamp();
	std::cout	<<"index:"
				<< this->_accountIndex
				<< ";p_amount:"
				<< this->_amount - deposit
				<< ";deposit:"
				<< deposit
				<< ";amount:"
				<< this->_amount
				<< ";deposits:"
				<< this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout	<<"index:"
				<< this->_accountIndex
				<< ";p_amount:"
				<< this->_amount;
	if (this->_amount >= withdrawal)
	{
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout	<< ";withdrawal:"
					<< withdrawal
					<< ";amount:"
					<< this->_amount
					<< ";withdrawals:"
					<< this->_nbWithdrawals
					<< std::endl;
		return (true);
	}
	std::cout	<< ";withdrawal:refused"
				<< std::endl;
	return (false);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout	<<"index:"
				<< this->_accountIndex
				<< ";amount:"
				<< this->_amount
				<< ";deposits:"
				<< this->_nbDeposits
				<< ";withdrawals:"
				<< this->_nbWithdrawals
				<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t	timestamp = std::time(0);
	tm			*time = localtime(&timestamp);

	std::cout	<< "["
				<< time->tm_year + 1900
				<< time->tm_mon
				<< time->tm_mday
				<< '_'
				<< time->tm_hour
				<< time->tm_min
				<< time->tm_sec
				<< "] ";
}

Account::Account(void)
{
	return ;
}
