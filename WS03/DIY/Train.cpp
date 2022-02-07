/* ------------------------------------------------------
Workshop 3 part 2
Module: N/A
Filename: Train.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       02/06/2022
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
			cout << "SPEED " << setw(14) << ": " << fixed << setprecision(2) << speed << " km/h" << endl;
		}
	}
	bool Train::loadPeople(int peopleCount) {
		if (isSafeEmpty())
			return false;
		if (peopleCount + people > MAX_PEOPLE) {
			people = MAX_PEOPLE;
			return false;

		}
		else if (people + peopleCount < 0)
		{

			people = 0;
			return false;

		}
		else {
			people += peopleCount;
			return true;

		}
	}
	bool Train::changeSpeed(double speedNumebr) {
		if (isSafeEmpty())
			return false;
		if (speedNumebr + speed > MAX_SPEED)
		{
			speed = MAX_SPEED;
			return false;

		}
		else if (speed + speedNumebr < 0)
		{
			speed = 0;
			return false;

		}
		else {
			speed += speedNumebr;
			return true;
		}


		return true;
	}
	int transfer(Train& firstTrain, Train& secondTrain) {
		int count ;
		if (firstTrain.isSafeEmpty() || secondTrain.isSafeEmpty())
			return -1;

		for (count = 0; firstTrain.loadPeople(1); count++) {
		}
		secondTrain.loadPeople(-count);

		return count;

	}
}