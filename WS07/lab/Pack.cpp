/* ------------------------------------------------------
Workshop 7 part 1
Module: N/A
Filename: Pack.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       03/18/2022
-----------------------------------------------------------*/

#include "Pack.h"
using namespace std;

namespace sdds {
	Pack::Pack(const char* content, int size, int unitSize, int numberOfUnits)
		:Container(content, size* unitSize, unitSize* numberOfUnits) {
		m_unitSize = size;
		m_sizeOfPack = unitSize;
		m_numberOfUnits = numberOfUnits;
	}



	int Pack::operator += (int value) {

		int result = Container::operator+=(value * m_sizeOfPack) / m_sizeOfPack;
		m_numberOfUnits += result;
		return result;
	}


	int Pack::operator -= (int units) {
		int result = Container::operator-=(units * m_sizeOfPack) / m_sizeOfPack;
		m_numberOfUnits -= result;
		return result;
	}


	int Pack::unit() {
		return m_sizeOfPack;
	}


	int Pack::noOfUnits() {
		return m_numberOfUnits;
	}


	int Pack::size() {
		return m_unitSize;
	}



	void Pack::clear(int packSize, int unitSize, const char* content) {
		if (unitSize > 0) {
			int unit = packSize * unitSize;
			m_unitSize = packSize;

			Container::clear(unit, content);
			m_sizeOfPack = unitSize;
			m_numberOfUnits = 0;
		}
	}


	std::ostream& Pack::print(std::ostream& ostr) const {
		Container::print(ostr);
		if (operator bool()) {
			ostr << ", " << m_numberOfUnits << " in a pack of " << m_unitSize;
		}

		return ostr;
	}



	std::istream& Pack::read(std::istream& istr) {

		int number;

		if (!operator bool()) {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.ignore();

		}
		else if (m_numberOfUnits == m_unitSize) {
			istr.ignore();
			cout << "Pack is full!, press <ENTER> to continue..." << endl;

		}
		else {
			cout << "Add to ";
			print(cout);

			int max = m_unitSize - m_numberOfUnits;
			do  {
				cout << endl << "> ";
				istr>> number;

				if (number > m_unitSize) {
					cout << "Invalid Integer, retry: ";
				}

				else if (number < 1 || number > max) {
					cout << "Value out of range [1<=val<=" << max << "]: ";
					istr >> number;
				}

			} while ((number > m_unitSize) || number < 1 || number > max);

			number = *this += number;
			cout << "Added " << number << endl;
		}

		return istr;
	}

	std::istream& operator>>(std::istream& istr, Pack& pack) {
		pack.read(istr);
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Pack& pack) {
		pack.print(ostr);
		return ostr;
	}
}