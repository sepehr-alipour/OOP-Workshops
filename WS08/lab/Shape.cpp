/* ------------------------------------------------------
Workshop 8 part 1
Module: N/A
Filename: Shape.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       03/24/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include "Shape.h"

using namespace std;
namespace sdds {

	Shape::~Shape() {}
	std::istream& operator>>(std::istream& istr, Shape& shape) {
		shape.getSpecs(istr);
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Shape& shape) {
		shape.draw(ostr);
		return ostr;
	}
}