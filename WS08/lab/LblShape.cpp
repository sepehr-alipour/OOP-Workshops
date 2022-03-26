/* ------------------------------------------------------
Workshop 8 part 1
Module: N/A
Filename: LblShape.cpp
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
using namespace std;
namespace sdds {
	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	}
	void LblShape::getSpecs(std::istream& is) {
		char label[51];
		is.get(label, 51, ',');
		if (is.peek() == ',')
			is.ignore();
		else {
			is.ignore(2000, ',');
			is.setstate(ios::failbit);
		}
		if (!is.fail()) {
			if (m_label)
				delete[] m_label;
			m_label = new (nothrow) char[strlen(label) + 1];
			strcpy(m_label, label);
		}

	}

	LblShape::LblShape() {
		m_label = nullptr;
	}
	LblShape::LblShape(const char* label) {
		if (label) {
			m_label = new (nothrow) char[strlen(label) + 1];
			strcpy(m_label, label);
		}
		else
			m_label = nullptr;
	}
	char* LblShape::label()const {

		return m_label;
	}

}