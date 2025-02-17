

/* ------------------------------------------------------
Workshop 3 part 2
Module: N/A
Filename: Train.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       02/06/2022
-----------------------------------------------------------*/
const int MAX_NAME_LEN = 20;
const int MAX_PEOPLE = 1000;
const int MAX_SPEED = 320;
namespace sdds {



	class Train
	{


		char name[MAX_NAME_LEN];
		int people;
		double speed;
		bool isValid = false;
		int state;

	public:
		void set(const char*, int, double);
		int getNumberOfPeople() const;
		const char* getName() const;
		double getSpeed() const;
		bool isSafeEmpty() const;
		void display() const;
		bool loadPeople(int) ;
		bool changeSpeed(double) ;
		void setEmpty() ;


	};
	int transfer(Train& second, Train& first);


}