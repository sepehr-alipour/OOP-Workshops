/* ------------------------------------------------------
Workshop 7 part 1
Module: N/A
Filename: Pack.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       03/18/2022
-----------------------------------------------------------*/

#ifndef PACK_H
#define PACK_H

#include "Container.h"
using namespace sdds;
namespace sdds {
	class Pack : public Container {
		int m_unitSize;
		int m_sizeOfPack;
		int m_numberOfUnits;

	public:
		Pack(const char* content, int size, int unitSize = 330, int numberOfUnits = 0);
		int operator+= (int value);
		int operator -= (int value);
		int unit();
		int noOfUnits();
		int size();
		void clear(int packSize, int unitSize, const char* content);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);


	};
	std::istream& operator>>(std::istream& istr, Pack& pack);
	std::ostream& operator<<(std::ostream& istr, const Pack& pack);
}
#endif