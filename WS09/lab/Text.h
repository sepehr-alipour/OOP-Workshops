/* ------------------------------------------------------
Workshop 9 part 1
Module: N/A
Filename: Text.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       03/31/2022
-----------------------------------------------------------*/
#ifndef TEXT_H
#define TEXT_H
#include <iostream>

using namespace std;
namespace sdds {
	class Text {
		char* m_content{};
	public:

		Text();
		~Text();
		Text(const Text& text);

		std::istream& read(std::istream& is);
		virtual std::ostream& write(std::ostream& os)  const;
		Text& operator=(const Text& text) ;
		int getFileLength(std::istream& is);

	protected:
		const char& operator[](int index)const;


	};
	std::istream& operator>>(std::istream& istr, Text& text);
	std::ostream& operator<<(std::ostream& ostr, const Text& text);
}
#endif