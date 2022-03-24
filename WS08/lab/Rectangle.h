/* ------------------------------------------------------
Workshop 8 part 1
Module: N/A
Filename: Rectangle.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       03/24/2022
-----------------------------------------------------------*/
#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include "LblShape.h"
using namespace sdds;
namespace sdds {
	class Rectangle : public LblShape {
		int m_height;
		int m_width;
	public:
		void draw(std::ostream& os) const;
		void getSpecs(std::istream& is) const;

		Rectangle();
		Rectangle(const char* label, int width,int height);
		~Rectangle();

	};

}
#endif