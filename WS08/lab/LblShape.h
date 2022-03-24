/* ------------------------------------------------------
Workshop 8 part 1
Module: N/A
Filename: LblShape.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       03/24/2022
-----------------------------------------------------------*/
#ifndef LBLSHAPE_H
#define LBLSHAPE_H
#include <iostream>
#include "Shape.h"
using namespace sdds;
namespace sdds {
	class LblShape : public Shape {
		char* m_label ;
	public:
		~LblShape();
		void getSpecs(std::istream& is) const;

		LblShape();
		LblShape(const char* label);

		LblShape& operator=(const LblShape& menu) = delete;
		LblShape(const LblShape& menu) = delete;

	
	protected:
		char* label()const;



	};

}
#endif