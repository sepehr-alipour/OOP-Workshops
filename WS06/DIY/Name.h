#include <string.h>
#include <string>

/* ------------------------------------------------------
Workshop 6 part 2
Module: N/A
Filename: Name.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       06/03/2022
-----------------------------------------------------------*/

#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>

namespace sdds {

	class Name {

		char* firstName{};
		char* middleName{};
		char* lastName{};
		bool isShort=false;
	public:
		Name();
		~Name();
		Name(const char* firstName) ;
		Name(const char* firstName, const char* lastName);
		Name(const char* firstName, const char* middleName, const char* lastName);
		Name(const Name& name);

		bool validName(const char* fistName, const char* middleName, const char* lastName) const;
		operator bool() const;

		void setEmpty();
		void set(const char* firstName, const char* middleName, const char* lastName);
		void setShort(bool isShort);
		std::ostream& print(std::ostream& ostr) const;
		std::istream& read(std::istream& istr);
	
		Name& operator=(const Name& name);
		Name& operator +=(const char* name);

	};

		 std::ostream& operator<<(std::ostream& ostr, const Name& name);
		 std::istream& operator>>(std::istream& istr, Name& name);

}
#endif // !SDDS_NAME_H

