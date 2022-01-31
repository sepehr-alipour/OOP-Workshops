/*Module: N / A
Filename : Car.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
---------------------------------------------------------- -
Date       01 / 27 / 2022
---------------------------------------------------------- - */
#include "Car.h"
#include "cStrTools.h"
#include <iostream>
#include <string>

using namespace std;
namespace sdds {


	Car* ptrStrCars = nullptr;
	int allocationSize;
	int numberOfCars;
	int carArraySize;


	void VBPLE_Title() {
		cout << "Vehicle Border Passing Log Entry"
			<< endl
			<< "Enter the data in the following format:"
			<< endl
			<< "Make and model,LicensePlate,MilitaryTime<ENTER>"
			<< endl
			<< "Exit the program by entering the following:"
			<< endl
			<< "X,<ENTER>"
			<< endl;

	}
	void initialize(int allocSize) {
		numberOfCars = 0;
		carArraySize = allocSize;
		allocationSize = allocSize;
		ptrStrCars = new Car[allocationSize];

	}
	void deallocate(Car& C) {
		delete[] C.makeModel;
		C.makeModel = nullptr;
	}
	bool read(Car& C) {
		char time[6];
		bool isValide = false;
		char makeModel[61];

		read(makeModel, 60, ',');
		if (strCmp(makeModel, "X") != 0) {
			isValide = true;
			C.makeModel = new char[strLen(makeModel) + 1];
			strCpy(C.makeModel, makeModel);
			read(C.licensePlate, 8, ',');
			read(time, 6);
			C.time = stoi(time);
		}

		return isValide;
	}

	void print(const Car& C) {

		cout << C.time << ": " << C.makeModel << "," << C.licensePlate << endl;
	}
	void record(const Car& C) {
		if (numberOfCars == carArraySize) {
			Car* tempPtrCar = nullptr;
			tempPtrCar = new Car[carArraySize + allocationSize];
			for (int i = 0; i < carArraySize; i++)
			{
				strCpy(tempPtrCar[i].licensePlate, ptrStrCars[i].licensePlate);
				tempPtrCar[i].makeModel = ptrStrCars[i].makeModel;
				tempPtrCar[i].time = ptrStrCars[i].time;
			}

			delete[] ptrStrCars;

			ptrStrCars = tempPtrCar;

			carArraySize += allocationSize;

		}
		ptrStrCars[numberOfCars] = C;
		numberOfCars++;
	}

	void endOfDay() {
		for (int i = 0; i < numberOfCars; i++)
		{
			print(ptrStrCars[i]);
			deallocate(ptrStrCars[i]);

		}
		delete[] ptrStrCars;
		ptrStrCars = nullptr;
	}




}
