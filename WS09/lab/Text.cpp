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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Text.h"
using namespace std;
namespace sdds {

	Text::Text() {
		m_content = nullptr;
	}
	Text::Text(const Text& text) {
		(*this) = (text);
	}

	std::istream& Text::read(std::istream& is) {
		delete[] m_content;
		m_content = new char[getFileLength(is) + 1];
		char ch;
		int i = 0;
		if (getFileLength(is) != 0) {
			while (is.get(ch)) {
				m_content[i] = ch;
				i++;
			}
		}

		is.clear();
		m_content[i] = '\0';
		return is;

	}
	Text::~Text() {
		delete[] m_content;
		m_content = nullptr;
	}
	std::ostream& Text::write(std::ostream& os)  const {

		if (m_content) {
			os << m_content;
		}
		return os;
	}

	Text& Text::operator=(const Text& text) {
		delete[] m_content;
		m_content = nullptr;
		if (text.m_content != nullptr) {

			m_content = new (nothrow) char[strlen(text.m_content) + 1];
			strcpy(m_content, text.m_content);
		}

		return *this;
	}
	int Text::getFileLength(std::istream& is) {
		int len{};
		if (is) {
			// save the current read position
			std::streampos cur = is.tellg();
			// go to the end
			is.seekg(0, ios::end);
			// let what is the positions (end position = size)
			len = is.tellg();
			// now go back to where you were.
			is.seekg(cur);
		}
		return len;
	}


	std::istream& operator>>(std::istream& istr, Text& text) {
		text.read(istr);
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Text& text) {
		text.write(ostr);
		return ostr;
	}

	const char& Text::operator[](int index)const {
		return m_content[index];

	}


}