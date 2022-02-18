/* ------------------------------------------------------
Workshop 4 part 1
Module: N/A
Filename: CarInventory.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       02/10/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS


#include "CarInventory.h"
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {


	CarInventory::CarInventory() {

		resetInfo();

	}

	CarInventory::CarInventory(const char* type, const char* brand
		, const char* model
		, int year
		, int code
		, double price) {
		m_type = new (nothrow) char[strlen(type) + 1];
		m_brand = new (nothrow) char[strlen(brand) + 1];
		m_model = new (nothrow) char[strlen(model) + 1];
		strcpy(m_type, type);
		strcpy(m_brand, brand);
		strcpy(m_model, model);
		m_year = year;
		m_code = code;
		m_price = price;
		if (!isValid())
		{
			resetInfo();
		}

	}
	void CarInventory::resetInfo() {
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;
		m_year = 0;
		m_code = 0;
		m_price = 0;
	}


	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {

		this->~CarInventory();
		m_type = new (nothrow) char[strlen(type) + 1];
		m_brand = new (nothrow) char[strlen(brand) + 1];
		m_model = new (nothrow) char[strlen(model) + 1];
		strcpy(m_type, type);
		strcpy(m_brand, brand);
		strcpy(m_model, model);
		m_year = year;
		m_code = code;
		m_price = price;
		return *this;
	}
	CarInventory::~CarInventory()
	{

		delete[] m_type;
		delete[] m_brand;
		delete[] m_model;
		m_type = nullptr;
		m_brand = nullptr;
		m_model = nullptr;

	}

	void CarInventory::printInfo() const {
		cout << "| " << left << setw(11) << setfill(' ') << m_type
			<< "| " << left << setw(17) << setfill(' ') << m_brand
			<< "| " << left << setw(17) << setfill(' ') << m_model
			<< "| " << m_year
			<< " |  " << m_code
			<< " |  " << fixed << setprecision(2) << right << setw(8) << m_price << " |"
			<< endl;

	}
	bool CarInventory::isValid() const
	{
		if (m_type == nullptr || m_brand == nullptr || m_model == nullptr
			|| m_year < 1990 || (m_code < 100 && m_code>999) || m_price <= 0)
		{
			return false;
		}
		return true;
	}
	bool CarInventory::isSimilarTo(const CarInventory& car) const {
		if (this->m_brand != nullptr && strcmp(car.m_brand, CarInventory::m_brand) == 0 &&
			this->m_model != nullptr && strcmp(car.m_model, CarInventory::m_model) == 0 &&
			this->m_type != nullptr && strcmp(car.m_type, CarInventory::m_type) == 0) {
			return true;
		}
		return false;
	}
	bool find_similar(CarInventory car[], const int num_cars) {


		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					return true;
				}
			}
		}
		return false;
	}





}