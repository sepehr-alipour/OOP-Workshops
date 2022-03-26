/* ------------------------------------------------------
Workshop 8 part 1
Module: N/A
Filename: Line.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       03/24/2022
-----------------------------------------------------------*/
#ifndef LINE_H
#define LINE_H
#include "LblShape.h"
using namespace std;
namespace sdds {
	class Line : public LblShape {
		int m_length;
	public:

		void draw(std::ostream& os) const;
		void getSpecs(std::istream& is) ;

		Line();
		Line(const char* label,int length);


	};

}
#endif