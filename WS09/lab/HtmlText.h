/* ------------------------------------------------------
Workshop 9 part 1
Module: N/A
Filename: HtmlText.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       03/31/2022
-----------------------------------------------------------*/
#ifndef HTMLTEXT_H
#define HTMLTEXT_H
#include <iostream>
#include "Text.h"
using namespace std;
namespace sdds {
	class HtmlText : public Text {
		char* m_title{};
	public:
		HtmlText(const char* title=nullptr);
		HtmlText(const HtmlText& html);
		virtual ~HtmlText();
		virtual std::ostream& write(std::ostream& os) const;

		HtmlText& operator=(const HtmlText& text);
	
	};

}
#endif