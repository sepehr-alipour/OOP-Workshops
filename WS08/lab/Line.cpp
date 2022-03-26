/* ------------------------------------------------------
Workshop 8 part 1
Module: N/A
Filename: Line.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       03/24/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include "LblShape.h"
#include "Line.h"

using namespace std;

namespace sdds {
	Line::Line() : LblShape() {
		m_length = 0;
	}

	Line::Line(const char* lineCstring, int length) : LblShape(lineCstring) {
		m_length = length;
	}

	void Line::getSpecs(istream& is) {
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(1000, '\n');
	}

	void Line::draw(ostream& os) const {
		if (m_length > 0 && label()) {
			os << label() << endl;
			for (int i = 0; i < m_length; i++)
				os << "=";
		}
	}
}
