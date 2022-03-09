

/* ------------------------------------------------------
Workshop 6 part 2
Module: N/A
Filename: Name.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       06/03/2022
-----------------------------------------------------------*/

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Name.h"
#include <string.h>
using namespace std;
namespace sdds {

	Name::Name()
	{
		set(nullptr, nullptr, nullptr);
	}
	Name::Name(const char* firstName) {
		set(firstName, nullptr, nullptr);
	}
	Name::Name(const char* firstName, const char* lastName) {
		set(firstName, nullptr, lastName);
	}
	Name::Name(const char* firstName, const char* middleName, const char* lastName) {
		if (validName(firstName, middleName, lastName))
			set(firstName, middleName, lastName);

		else {

			setEmpty();
		}
	}

	Name::Name(const Name& name) {
		if (name.operator bool()) {
			setEmpty();
			*this = name;
		}


	}

	void Name::setEmpty() {

		this->firstName = nullptr;
		this->middleName = nullptr;
		this->lastName = nullptr;
	}
	void Name::set(const char* firstName, const char* middleName, const char* lastName) {
		if (firstName) {
			delete[] this->firstName;
			this->firstName = new char[strlen(firstName) + 1];
			strcpy(this->firstName, firstName);

		}
		else {
			delete[] this->firstName;
			this->firstName = nullptr;

		}
		if (middleName) {
			delete[] this->middleName;
			this->middleName = new char[strlen(middleName) + 1];
			strcpy(this->middleName, middleName);

		}
		else {
			delete[] this->middleName;
			this->middleName = nullptr;
		}
		if (lastName) {
			delete[] this->lastName;
			this->lastName = new char[strlen(lastName) + 1];
			strcpy(this->lastName, lastName);
		}
		else {
			delete[] this->lastName;
			this->lastName = nullptr;
		}

	}

	Name::~Name() {

		delete[] firstName;
		delete[] middleName;
		delete[] lastName;
		setEmpty();

	}

	void Name::setShort(bool isShort) {
		this->isShort = isShort;
	}
	std::ostream& Name::print(std::ostream& ostr) const {
		if (validName(firstName, middleName, lastName)) {


			if (isShort && middleName && lastName)
			{
				ostr << firstName << " " << middleName[0] << ". " << lastName;

			}
			else {

				if (middleName && lastName && firstName) {
					ostr << firstName;

					if (strcmp(middleName, "") == 0) ostr << ""; else ostr << " " << middleName << " " << lastName;
				}
				else if (!middleName && !lastName)

					ostr << firstName;

				else if (!middleName || !lastName) {
					if (middleName) {
						ostr << firstName;
						if (strcmp(middleName, "") == 0 || middleName[0] == ' ')
							ostr << ""; else ostr << " " << middleName;
					}
					if (lastName) {
						ostr << firstName;
						if (strcmp(firstName, "") == 0 || firstName[0] == ' ')
							ostr << ""; else ostr << " " << lastName;
					}
				}

			}
		}
		return ostr;

	}
	std::istream& Name::read(std::istream& istr) {
		delete[] firstName;
		delete[] middleName;
		delete[] lastName;
		setEmpty();

		string firstName;
		string middleName;
		string lastName;
		string tmp;

		istr >> firstName;
		if (istr.peek() != '\n')
			istr >> middleName;
		if (istr.peek() != '\n')
			istr >> lastName;
		if (istr.peek() != '\n')
			istr >> tmp;

		if (!tmp.empty())
			setEmpty();
		else if (!middleName.empty() && lastName.empty())
		{
			set(firstName.c_str(), middleName.c_str(), nullptr);
		}
		else if (!middleName.empty() && !lastName.empty())
		{
			set(firstName.c_str(), middleName.c_str(), lastName.c_str());
		}
		else
		{
			set(firstName.c_str(), nullptr, nullptr);
		}

		return istr;


	}
	std::istream& operator>>(std::istream& istr, Name& name) {

		name.read(istr);
		return istr;

	}


	Name& Name::operator=(const Name& name) {

		if (&name != this) {

			set(name.firstName, name.middleName, name.lastName);
		}

		return *this;
	}
	std::ostream& operator<<(std::ostream& ostr, const Name& name) {
		if (!name.operator bool())
			ostr << "Bad Name";
		else name.print(ostr);
		return ostr;
	}

	Name& Name::operator +=(const char* name) {


		if (strcmp(name, "") == 0 || strchr(name, ' ') != NULL)
			name = "";
		if (!this->firstName) {

			delete[] this->firstName;
			this->firstName = new char[strlen(name) + 1];
			strcpy(this->firstName, name);

		}
		else if (!this->middleName || strcmp(middleName, "") == 0) {

			delete[] this->middleName;
			this->middleName = new char[strlen(name) + 1];
			strcpy(this->middleName, name);
		}
		else if (!this->lastName || strcmp(lastName, "") == 0) {

			delete[] this->lastName;
			this->lastName = new char[strlen(name) + 1];
			strcpy(this->lastName, name);
		}
		else {
			delete[] firstName;
			delete[] middleName;
			delete[] lastName;
			setEmpty();
		}
		return *this;
	}
	bool Name::validName(const char* fistName, const char* middleName, const char* lastName) const {
		if (fistName || middleName || lastName)
			return true;
		return false;
	}

	Name::operator bool() const {
		if (firstName != nullptr)
			return true;
		return false;
	}
}
