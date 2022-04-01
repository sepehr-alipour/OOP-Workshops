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
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include "HtmlText.h"

using namespace std;
namespace sdds {

	std::ostream& HtmlText::write(std::ostream& os) const {
		bool MS = false;
		os << "<html><head><title>";
		if (!m_title)
		{
			os << "No Title";
		}
		os << m_title;
		os << "</title></head>\n<body>\n";
		if (m_title)
		{
			os << "<h1>" << m_title << "</h1>\n";
		}
		int i = 0;

		while (this->operator[](i) != '\0') {
			char character = (*this)[i];

			if (character == ' ' && MS == true) {
				os << "&nbsp;";
			}
			else if ((*this)[i] == ' ' && MS != true)
			{
				MS = true;
				os << ' ';
			}
			else if (character == '<') {
				MS = false;
				os << "&lt;";
			}
			else if (character == '>') {
				MS = false;
				os << "&gt;";
			}
			else if (character == '\n') {
				MS = false;
				os << "<br />\n";
			}
			else {
				MS = false;
				os << character;
			}
			i++;

		}
		os << "</body>\n</html>";
		return os;
	}
	HtmlText::HtmlText(const char* title) :Text() {
		delete[] m_title;
		m_title = nullptr;

		if (title) {
			m_title = new (nothrow) char[strlen(title) + 1];
			strcpy(m_title, title);
		}

	}
	HtmlText::HtmlText(const HtmlText& html) :Text(html) {
		(*this) = (html);
	}
	HtmlText& HtmlText::operator=(const HtmlText& htmlText) {
		if (&htmlText != this) {
			delete[] m_title;
			m_title = nullptr;
			if (htmlText.m_title != nullptr) {

				m_title = new (nothrow) char[strlen(htmlText.m_title) + 1];
				strcpy(m_title, htmlText.m_title);
			}
			Text::operator=(htmlText);

		}
		return *this;
	}
	HtmlText::~HtmlText() {
		delete[] m_title;
		m_title = nullptr;

	}


}