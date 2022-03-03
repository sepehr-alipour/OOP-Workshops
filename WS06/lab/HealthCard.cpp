
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
	std::ostream& HealthCard::printIDInfo(std::ostream& ostr)const {

		ostr << m_number << '-' << m_vCode << ", " << m_sNumber;;
		return ostr;
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

	HealthCard::operator bool() const {
		if (m_name != nullptr)
			return true;
		return false;
	}

	std::ostream& HealthCard::print(std::ostream& ostr, bool toFile) const {
		if (validID(m_name, m_number, m_vCode, m_sNumber)) {
			if (toFile)
			{
				ostr << m_name << ","; printIDInfo(ostr) << endl;
			}
			else {
				ostr << m_name;
				ostr.width(60 - strlen(m_name));
				ostr.fill('.');

				printIDInfo(ostr);
			}
		}
		return ostr;
	}
	std::istream& HealthCard::read(std::istream& istr) {
		char name[MaxNameLength];
		//char* m_name{};
		long long number;
		char vCode[3];
		char sNumber[10];


		istr.get(name, MaxNameLength, ',');
		extractChar(istr, ',');
		istr >> number;
		extractChar(istr, '-');
		istr.get(vCode, 3, ',');
		extractChar(istr, ',');
		istr.get(sNumber, 10, '\n');

		if (!istr.fail())
			set(name, number, vCode, sNumber);
		istr.clear();
		istr.ignore(1000, '\n');
		return istr;
	}







}
