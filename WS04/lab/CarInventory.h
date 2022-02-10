
/* ------------------------------------------------------
Workshop 4 part 1
Module: N/A
Filename: CarInventory.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       02/10/2022
-----------------------------------------------------------*/


#define DEFAULT_YEAR 2022
#define DEFAULT_CODE 100
#define DEFAULT_PRICE 1
#ifndef _CARINVENTORY_
#define _CARINVENTORY_


namespace sdds {

	class CarInventory
	{

		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;

		void resetInfo();

	public:
		CarInventory();
		~CarInventory();
		CarInventory(const char* type, const char* brand, const char* model, int year = DEFAULT_YEAR, int code = DEFAULT_CODE, double price = DEFAULT_PRICE);
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory& car) const;

	};
	bool find_similar(CarInventory car[], const int num_cars);

}
#endif
