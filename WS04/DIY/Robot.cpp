
/* ------------------------------------------------------
Workshop 4 part 2
Module: N/A
Filename: Robot.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       02/13/2022
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS


#include "Robot.h"
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {


	Robot::Robot()
	{
		resetInfo();
	}


	void Robot::resetInfo()
	{
		name = nullptr;
		location = nullptr;
		weight = 0;
		width = 0;
		height = 0;
		speed = 0;
	}


	Robot::Robot(const char* name
		, const char* location
		, const double weight
		, const double width
		, const double height
		, const double speed
		, const bool deployed)
	{
		set(name, location, weight, width, height, speed, deployed);
	}


	Robot& Robot::set(const char* name
		, const char* location
		, const double weight
		, const double width
		, const double height
		, const double speed
		, const bool deployed)
	{

		Robot::name = new char[strlen(name) + 1];
		Robot::location = new char[strlen(location) + 1];
		strcpy(Robot::name, name);
		strcpy(Robot::location, location);
		Robot::weight = weight;
		Robot::width = width;
		Robot::height = height;
		Robot::speed = speed;
		Robot::deployed = deployed;


		if (!isValid())
		{
			resetInfo();
		}
		return *this;
	}



	void Robot::display() const
	{

		cout << left
			<< "| " << setw(11) << name
			<< "| " << setw(16) << location
			<< "| " << fixed << right << setprecision(1) << setw(6) << weight
			<< " | " << fixed << right << setprecision(1) << setw(6) << width
			<< " | " << fixed << right << setprecision(1) << setw(6) << height
			<< " | " << fixed << right << setprecision(1) << setw(6) << speed
			<< " | " << left << setw(8) << (deployed == 1 ? "YES" : "NO")
			<< " |" << endl;

	}
	int conrtolRooomReport(const Robot robot[], int size)
	{

		int deployed = 0;
		int fastIndex = 0;

		cout << right << setw(50) << "------Robot Control Room-----" << endl
			<< right << setw(55) << "---------------------------------------" << endl
			<< "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl
			<< "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;

		for (int i = 0; i < size; i++)
		{
			if (robot[i].isValid())
			{
				robot[i].display();
			}
			else
			{
				return i;
			}
		}

		cout << "|=============================================================================|" << endl;



		for (int i = 0; i < size; i++)
		{
			if (robot[i].getSpeed() > robot[fastIndex].getSpeed())
			{
				fastIndex = i;
			}
			if (robot[i].isDeployed())
			{
				deployed++;
			}
		}

		cout << setw(78) << "| SUMMARY:" << "|" << endl
			<< "| " << deployed << setw(75) << "  robots are deployed." << "|" << endl
			<< setw(78) << "| The fastest robot is : " << "|" << endl
			<< "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl
			<< "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;

		robot[fastIndex].display();

		cout << "|=============================================================================|" << endl;


		return -1;
	}

	char* Robot::getName() const {
		return name;
	}


	double Robot::getSpeed() const {
		return speed;
	}

	char* Robot::getLocation() const {
		return location;
	}

	Robot& Robot::setLocation(const char* location) {

		if (location != nullptr)
		{
			Robot::location = new char[strlen(location) + 1];
			strcpy(Robot::location, location);
		}

		return *this;
	}


	bool Robot::isDeployed() const {
		return deployed;
	}

	Robot& Robot::setDeployed(bool deployed) {

		Robot::deployed = deployed;

		return *this;
	}


	bool Robot::isValid() const
	{
		if (this->name != nullptr
			&& this->location != nullptr
			&& this->weight > 0 && this->width > 0
			&& this->height > 0 && this->speed > 0)
			return true;
		return false;

	}


	Robot::~Robot()
	{
		delete[] this->name;
		delete[] this->location;

		this->name = nullptr;
		this->location = nullptr;
	}

}