/* ------------------------------------------------------
Workshop 7 part 1
Module: N/A
Filename: Container.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       03/18/2022
-----------------------------------------------------------*/

#include "Container.h"

using namespace std;

namespace sdds {
	void Container::setEmpty() {

		m_content[0] = '\0';
	}
	int Container::getCapacity()
	{
		return m_capacity;
	}
	int Container::getVolume() {
		return m_contentVolunme;
	}
	Container::Container(const char* content, int capacity, int contentVolume) {
		if (content == NULL || contentVolume > capacity) {
			setEmpty();
		}
		else {
			strcpy(m_content, content);
			m_capacity = capacity;
			m_contentVolunme = contentVolume;


		}

	}

	int Container::operator += (int capacity) {
		if (m_contentVolunme + capacity <= m_capacity) {
			m_contentVolunme += capacity;
		}
		else {
			capacity = m_capacity - m_contentVolunme;
			m_contentVolunme = m_capacity;
		}

		return capacity;
	}



	int Container::operator -= (int capacity) {
		if (m_contentVolunme - capacity >= 0) {
			m_contentVolunme -= capacity;
		}
		else {
			capacity = m_contentVolunme;
			m_contentVolunme = 0;
		}

		return capacity;
	}

	Container::operator bool() const {
		if (m_content[0] != '\0')
			return true;
		return false;
	}

	void Container::clear(int capacity, const char* content) {
		if (capacity > 0 && content != NULL) {
			m_capacity = capacity;
			strcpy(m_content, content);
			m_contentVolunme = 0;
		}
	}

	std::ostream& Container::print(std::ostream& ostr) const {
		if (operator bool()) {
			ostr << m_content;
			ostr << ": (" << m_contentVolunme;
			ostr << "cc/" << m_capacity << ")";
		}
		else {
			ostr << "****: (**cc/***)";
		}

		return ostr;
	}
	std::istream& Container::read(std::istream& istr) {

		int number;

		if (!operator bool()) {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
			istr.ignore();

		}
		else {
			cout << "Add to ";
			print(cout);

			do {
				cout << endl << "> ";
				istr >> number;

				if (number > m_capacity) {
					cout << "Invalid Integer, retry:";
				}

				else if (number < 1 || number > 999) {
					cout << "Value out of range [1<=val<=999]:";
				}

			} while (number > m_capacity || (number < 1 || number > 999));


			number = *this += number;
			cout << "Added " << number << " CCs" << endl;
		}

		return istr;
	}

	std::ostream& operator<<(std::ostream& istr, const Container& container) {
		container.print(istr);
		return istr;
	}
	std::istream& operator>>(std::istream& ostr, Container& container) {
		container.read(ostr);
		return ostr;
	}
}