/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.cpp
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/

/* ------------------------------------------------------
Workshop 5 part 1
Module: N/A
Filename: CarInventory.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       02/17/2022
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {
	void Flight::emptyPlane() {
		m_passengers = 0;
		m_fuel = 0;
		strcpy(m_title, "EmptyPlane");
	}

	// New Flight
	Flight::Flight() {
		emptyPlane();
	}
	Flight::Flight(int passengers, double fuel, const char* title) {
		emptyPlane();
		if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
			fuel <= FuelTankCapacity) {
			m_passengers = passengers;
			m_fuel = fuel;
			strcpy(m_title, title);
		}
	}
	std::ostream& Flight::display() const {

		if (*this) {
			cout << " Flight  |  Ready to Depart";
			cout << " ";
			cout.width(10);
			cout << std::string(*this);
			cout << " | ";
			cout << "Pass: ";
			cout.width(10);
			cout << int(*this);
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << double(*this);
			cout.unsetf(ios::right);
			cout << " Liters";
		}
		else if (~*this) {
			cout << " Flight  |  Empty Plane    ";
		}
		else {
			cout << " Flight  |  Low Fuel       ";
			cout << " ";
			cout.width(10);
			cout << (const char*)(*this);
			cout << " | ";
			cout << "Pass: ";
			cout.width(10);
			cout << int(*this);
			cout << " | ";
			cout.width(12);
			cout.precision(2);
			cout.setf(ios::right);
			cout.setf(ios::fixed);
			cout << double(*this);
			cout.unsetf(ios::right);
			cout << " Liters";
		}
		return cout;
	}
	Flight::operator bool() const {

		if (m_passengers > 0 && m_fuel >= (600 * m_passengers))
			return true;
		return false;
	}

	Flight::operator int() const {


		return m_passengers;
	}
	Flight::operator double() const {


		return m_fuel;
	}
	Flight::operator char* () const {

		
		return (char*) m_title;
	}

	bool Flight::operator~() const {
		
		if (m_passengers == 0)
			return true;
		return false;
	}

	Flight& Flight::operator =(Flight& f1) {

		m_passengers = f1.m_passengers;
		m_fuel = f1.m_fuel;
		strcpy(m_title, f1.m_title);



		f1.m_passengers = 0;
		f1.m_fuel = 0.00;
		strcpy(f1.m_title, "EmptyPlane");

		return *this;
	}
	Flight& Flight::operator =(int passenger) {

		if (passenger > 0 && passenger <= Boen747Capacity)
			m_passengers = passenger;


		return *this;
	}
	Flight& Flight::operator =(double fuel) {

		if (fuel > 0 && fuel <= FuelTankCapacity)
			m_fuel = fuel;


		return *this;
	}
	Flight& Flight::operator +=(double fuel) {
		
		if (fuel > 0 && fuel <= FuelTankCapacity)
			m_fuel += fuel;

		return *this;
	}

	Flight& Flight::operator +=(int passenger) {
		
		if (passenger > 0 && passenger <= Boen747Capacity)
			m_passengers += passenger;


		return *this;
	}

	Flight& Flight::operator -=(double fuel) {
		
		if (fuel > 0 && fuel <= FuelTankCapacity)
			m_fuel -= fuel;
		else m_fuel = 0;

		return *this;
	}
	Flight& Flight::operator -=(int passenger) {
	
		if (passenger > 0 && passenger <= Boen747Capacity)
			m_passengers -= passenger;
		else m_fuel = 0;

		return *this;
	}
	int operator+(const Flight& f1, const Flight& f2)
	{
		return f1.operator int() + f2.operator int();
	}


	int operator+=(int& returnValue, const Flight& f1)
	{
		return returnValue += f1.operator int();
	}


	Flight& Flight::operator << (Flight& f1)
	{
		m_passengers += f1.m_passengers;

		if (m_passengers > Boen747Capacity)
		{
			f1.m_passengers = 0;
		}

		return *this;
	}


	Flight& Flight::operator >>(Flight& f1)
	{
		f1.m_passengers += m_passengers;
		m_passengers = 0;

		if (f1.m_passengers > Boen747Capacity)
		{
			m_passengers = f1.m_passengers - Boen747Capacity;
			f1.m_passengers = Boen747Capacity;
		}

		return *this;
	}

}