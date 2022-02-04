/* ------------------------------------------------------
Workshop 3 part 1
Module: N/A
Filename: Train.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       02/03/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include "Train.h"
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;
 namespace sdds {


	void Train::set(const char* newNAme, int newPeople, double newSpeed) {
		if (newNAme != nullptr && strlen(newNAme) > 0
			&& newSpeed >= 0 && newSpeed < MAX_SPEED
			&& newPeople > 0 && newPeople < MAX_PEOPLE) {
			strcpy(name, newNAme);
			speed = newSpeed;
			people = newPeople;
			isValid = false;

		}
		else {
			isValid = true;
		}


	}

	int Train::getNumberOfPeople() const {

		return people;
	}
	const char* Train::getName() const {

		return name;
	}
	double Train::getSpeed() const {
		return speed;
	}

	bool Train::isSafeEmpty() const {
		return isValid;
	}
	void Train::display() const {
		if (isValid)cout << "Safe Empty State!" << endl;
		else {
			cout << "NAME OF THE TRAIN " << setw(1) << ": " << name << endl;
			cout << "NUMBER OF PEOPLE " << setw(3) << ": " << people << endl;
			cout << "SPEED " << setw(14) << ": " << speed << " km/h" << endl;
		}
	}
}