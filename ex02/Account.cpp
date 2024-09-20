
#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account ::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	_nbAccounts++;
}

Account ::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";

	this->_amount -= withdrawal;
	if (checkAmount())
	{
		this->_amount += withdrawal;
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount(void) const
{
	if (this->_amount < 0)
		return (1);
	return (0);
}
void Account::_displayTimestamp(void)
{
	std::time_t t = std::time(NULL);
	std::tm *now = std::localtime(&t);

	std::cout << "[";
	std::cout << (now->tm_year + 1900);
	std::cout << std::setw(2) << std::setfill('0') << (now->tm_mon + 1);
	std::cout << std::setw(2) << std::setfill('0') << now->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << now->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << now->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << now->tm_sec;
	std::cout << "] ";
}
void Account::displayStatus(void) const
{
	  _displayTimestamp();
	 std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::displayAccountsInfos(void)
{
	std::cout << std::endl;
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl << std::endl;
}
int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int ::Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int ::Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int ::Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
