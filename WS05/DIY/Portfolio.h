/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.h
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
Filename: Portfolio.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       02/19/2022
-----------------------------------------------------------*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>


namespace sdds {

	class Portfolio {
		double m_value = 0;
		char m_stock[16];
		char m_type;

	public:
		void emptyPortfolio();
		void dispPortfolio() const;
		Portfolio(double value, const char* stock, char type);

		Portfolio();
		std::ostream& display() const;

		operator double() const;
		operator char* () const;
		operator char() const;
		operator bool() const;
		Portfolio& operator +=(const double value);
		Portfolio& operator -=(const double value);
		bool operator ~() const;

		Portfolio& operator <<(Portfolio& portfolio);
		Portfolio& operator >>(Portfolio& portfolio);
		friend double operator+(const Portfolio& p1, const Portfolio& p2);
		friend double operator+=(double& returnValue, const Portfolio& portfolio);

	};


}
#endif // SDDS_Portfolio_H_