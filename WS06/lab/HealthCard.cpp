
/* ------------------------------------------------------
Workshop 6 part 1
Module: N/A
Filename: HealthCard.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       03/03/2022
-----------------------------------------------------------*/

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HealthCard.h"
#include <string.h>
using namespace std;
namespace sdds {


	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {

		if (name != nullptr
			&& (number > 999999999 && number < 9999999999)
			&& strlen(vCode) == 2
			&& strlen(sNumber) == 9)
			return true;
		return false;
	}
	void HealthCard::setEmpty() {
		m_name = nullptr;
	}

	void HealthCard::allocateAndCopy(const char* name) {
		delete[] m_name;
		m_name = nullptr;
		m_name = new (nothrow) char[strlen(name) + 1];
		strcpy(m_name, name);

	}
	void HealthCard::extractChar(std::istream& istr, char ch) const {

		if (istr.peek() == ch)
			istr.ignore();
		else {
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}

	}
	

	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
		if (validID(name, number, vCode, sNumber))
		{

			allocateAndCopy(name);
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
			m_number = number;

		}
		else {
			delete[] m_name;
			setEmpty();
		}
	}
	HealthCard::HealthCard()
	{
		HealthCard(nullptr, 0, {}, {});
	}

	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
		set(name, number, vCode, sNumber);
	}
	HealthCard::HealthCard(const HealthCard& hc) {
		if (validID(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber)) {
			setEmpty();
			*this = hc;
		}

	}

	HealthCard& HealthCard::operator=(const HealthCard& hc) {

		if (&hc != this) {

			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}

		return *this;
	}

	HealthCard::~HealthCard() {

		delete[] m_name;
		m_name = nullptr;

	}

	
	









}
