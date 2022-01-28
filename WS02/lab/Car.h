/* ------------------------------------------------------
Workshop 2 part 1
Module: N/A
Filename: Car.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       01/27/2022
-----------------------------------------------------------*/

#ifndef _CAR_H
#define _CAR_H
namespace sdds {
	struct Car {
		char licensePlate[9];
		char* makeModel;
		int time;
	};

	void VBPLE_Title();
	void initialize(int allocSize);
	void deallocate(Car& C);
	bool read(Car& C);
	void print(const Car& C);
	void record(const Car& C);
	void endOfDay();

}
#endif