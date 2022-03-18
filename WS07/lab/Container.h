/* ------------------------------------------------------
Workshop 7 part 1
Module: N/A
Filename: Container.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       03/18/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {

	class Container {

		char m_content[50];
		int m_capacity;
		int m_contentVolunme;
	protected:
		void setEmpty();
		int getCapacity();
		int getVolume();
	public:
		Container(const char* content, int capacity, int contentVolume = 0);
		int operator += (int capacity);
		int operator -= (int capacity);
		operator bool() const;
		void clear(int capacity, const char* content);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);


	};

	std::istream& operator>>(std::istream& istr, Container& container);
	std::ostream& operator<<(std::ostream& istr, const Container& container);
}
#endif