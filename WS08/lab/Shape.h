/* ------------------------------------------------------
Workshop 8 part 1
Module: N/A
Filename: Shape.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       03/24/2022
-----------------------------------------------------------*/
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

using namespace std;
namespace sdds {
	class Shape {

	public:
		virtual void getSpecs(std::istream& is) = 0;
		virtual void draw(std::ostream& os)  const = 0;
		virtual ~Shape();


	};
	std::istream& operator>>(std::istream& istr, Shape& shape);
	std::ostream& operator<<(std::ostream& istr, const Shape& shape);

}
#endif