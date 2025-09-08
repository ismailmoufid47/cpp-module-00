#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	return ;
}

Account::~Account( void )
{
	_displayTimestamp();
	this->_nbAccounts--;
	this->_totalAmount -= this->_amount;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	return ;
}
int Account::getNbAccounts( void )
{
	return _nbAccounts;
}
int Account::getTotalAmount( void )
{
	return _totalAmount;
}
int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
int Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}
void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
	return ;
}

void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
	std::cout << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
	return ;
}

bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (this->_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalAmount -= withdrawal;
	this->_totalNbWithdrawals++;
	std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount( void ) const
{
	return this->_amount;
}
void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

void Account::_displayTimestamp( void )
{
	struct tm t;
	time_t now = time(0);
	localtime_r(&now, &t);
	std::cout << "[" 
		<< t.tm_year + 1900;
		t.tm_mon + 1 < 10 ? std::cout << "0" << t.tm_mon + 1 : std::cout << t.tm_mon + 1;
		t.tm_mday < 10 ? std::cout << "0" << t.tm_mday : std::cout << t.tm_mday;
		std::cout << "_";
		t.tm_hour < 10 ? std::cout << "0" << t.tm_hour : std::cout << t.tm_hour;
		t.tm_min < 10 ? std::cout << "0" << t.tm_min : std::cout << t.tm_min;
		t.tm_sec < 10 ? std::cout << "0" << t.tm_sec : std::cout << t.tm_sec;
	std::cout << "] ";
	return ;
}