/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.cpp
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/

/* ------------------------------------------------------
Workshop 5 part 2
Module: N/A
Filename: Portfolio.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       02/19/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"
#include <cstring>
using namespace std;
namespace sdds {


	Portfolio::Portfolio() {
		emptyPortfolio();
	}

	void Portfolio::emptyPortfolio()
	{
		m_value = 0;
		m_stock[0] = 0;
		m_type = 'E';
	}
	Portfolio::Portfolio(double value, const char* stock, char type) {
		emptyPortfolio();
		if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
			m_value = value;
			m_type = type;
			strcpy(m_stock, stock);
		}
	}

	void Portfolio::dispPortfolio() const {
		cout << " ";
		cout.width(10);
		cout << (const char*)(*this);
		cout << " | ";
		cout << "Value: ";
		cout.width(10);
		cout << double(*this);
		cout << " | ";
		cout << " Type: ";
		cout << char(*this);
	}
	std::ostream& Portfolio::display() const {

		if (~*this) {
			cout << " Portfolio  |  Bad-NG |";
			dispPortfolio();
		}
		else if (*this) {
			cout << " Portfolio  |  Active |";
			dispPortfolio();

		}
		else {
			cout << " Portfolio  |  EMPTY  |";
			dispPortfolio();
		}
		return cout;
	}
	Portfolio::operator double() const {
		return m_value;
	}
	Portfolio::operator char* () const {
		return (char*)m_stock;
	}
	Portfolio::operator char() const {
		return m_type;
	}
	Portfolio::operator bool() const {

		if (m_type == 'G' || m_type == 'V' || m_type == 'I')
			return true;
		return false;
	}
	Portfolio& Portfolio::operator +=(const double value) {
		if (value >= 0 && Portfolio::operator bool()) {

			m_value += value;
			
		}
		return *this;
	}
	Portfolio& Portfolio::operator -=(const double value) {

		if (value >= 0 && Portfolio::operator bool()) {

			m_value -=  value ;
		}
		return *this;

	}
	bool Portfolio::operator~() const {

		if (m_value < 0)
			return true;
		return false;
	}

	Portfolio& Portfolio::operator << (Portfolio& portfolio)
	{

		if (portfolio.operator bool() && Portfolio::operator bool()) {
			m_value += portfolio.m_value;
			portfolio.m_value = 0;
			portfolio.m_stock[0] = 0;
			portfolio.m_type = 'E';
		}
		return *this;
	}


	Portfolio& Portfolio::operator >>(Portfolio& portfolio)
	{
		if (portfolio.operator bool() && Portfolio::operator bool()) {
			portfolio.m_value += m_value;
			emptyPortfolio();
		}
		return *this;
	}

	 double operator+(const Portfolio& p1, const Portfolio& p2)
	{
		if (!p1.operator bool() && !p2.operator bool())
			return 0;

		return p1.operator double() + p2.operator double();
	}
	 double operator+=(double& value, const Portfolio& portfolio1)
	{

		return value += portfolio1.operator double();
	}


}