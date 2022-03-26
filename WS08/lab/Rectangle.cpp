/* ------------------------------------------------------
Workshop 8 part 1
Module: N/A
Filename: Rectangle.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       03/24/2022
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include "Rectangle.h"

using namespace std;
namespace sdds {
	Rectangle::Rectangle() :LblShape() {
		m_height = 0;
		m_width = 0;
	}

	Rectangle::Rectangle(const char* Cstringlabel, int width, int height) : LblShape(Cstringlabel) {
		int lableLength = strlen(label());
		if (height < 3 || width < lableLength + 2) {
			m_height = 0;
			m_width = 0;
		}
		else {
			m_width = width;
			m_height = height;
		}
	}

	void Rectangle::getSpecs(istream& is) {
		LblShape::getSpecs(is);

		is >> m_width;
		if (is.peek() == ',')
			is.ignore();
		else {
			is.ignore(2000, ',');
			is.setstate(ios::failbit);
		}
		is >> m_height;
		is.ignore(1000, '\n');
	}

	void Rectangle::draw(ostream& ostr) const {
		if (m_height > 0 && m_width > 0) {

			ostr << "+";
			for (int i = 0; i < m_width - 2; i++)
				ostr << "-";
			ostr << "+";
			ostr << endl;

			ostr << "|";
			ostr.width(m_width - 2);
			ostr.flags(ios::left);
			ostr << label() << "|" << endl;

			for (int j = 0; j < m_height - 3; j++) {
				ostr << "|";
				ostr.width(m_width - 2);
				ostr << " " << "|" << endl;
			}

			ostr << "+";
			for (int i = 0; i < m_width - 2; i++) {
				ostr << "-";
			}
			ostr << "+";
		}
	}



}