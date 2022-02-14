
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

	void Robot::deallocate()
	{ 
		delete[] m_name;
		delete[] m_location;

		m_name = nullptr;
		m_location = nullptr;
	}

	Robot::Robot()
	{
		resetInfo();
	}


	void Robot::resetInfo()
	{
		m_name = nullptr;
		m_location = nullptr;
		m_weight = 0;
		m_width = 0;
		m_height = 0;
		m_speed = 0;
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

		if (name != nullptr 
			&& weight > 0 
			&& width > 0 
			&& height > 0 
			&& speed > 0)
		{


			m_name = new char[strlen(name) + 1];
			m_location= new char[strlen(location) + 1];
			strcpy(m_name, name);
			strcpy(m_location, location);
			m_weight = weight;
			m_width = width;
			m_height = height;
			m_speed = speed;
			m_deployed = deployed;
		}
		else
			resetInfo();

		return *this;
		
	}



	void Robot::display() const
	{

		cout << left
			<< "| " << setw(11) << m_name
			<< "| " << setw(16) << m_location
			<< "| " << fixed << right << setprecision(1) << setw(6) << m_weight
			<< " | " << fixed << right << setprecision(1) << setw(6) << m_width
			<< " | " << fixed << right << setprecision(1) << setw(6) << m_height
			<< " | " << fixed << right << setprecision(1) << setw(6) << m_speed
			<< " | " << left << setw(8) << (m_deployed == 1 ? "YES" : "NO")
			<< " |" << endl;

	}
	int conrtolRooomReport(const Robot robot[], int size)
	{

		int deployed = 0;
		int fastIndex = 0;

		cout << right << setw(55) << "------ Robot Control Room -----" << endl
			<< right << setw(59) << "---------------------------------------" << endl
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
			<< setw(78) << "| The fastest robot is: " << "|" << endl
			<< "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl
			<< "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;

		robot[fastIndex].display();

		cout << "|=============================================================================|" << endl;


		return -1;
	}

	char* Robot::getName() const {
		return m_name;
	}


	double Robot::getSpeed() const {
		return m_speed;
	}

	char* Robot::getLocation() const {
		return m_location;
	}

	Robot& Robot::setLocation(const char* location) {

		if (location != nullptr)
		{
			m_location = new char[strlen(location) + 1];
			strcpy(m_location, location);
		}

		return *this;
	}


	bool Robot::isDeployed() const {
		return m_deployed;
	}

	Robot& Robot::setDeployed(bool deployed) {

		m_deployed = deployed;

		return *this;
	}


	bool Robot::isValid() const
	{
		if (m_name == nullptr
			|| m_location == nullptr
			|| m_weight <= 0 || m_width <= 0
			|| m_height <= 0 || m_speed <= 0)
			return false;
		return true;

	}


	Robot::~Robot()
	{
		deallocate();
	}

}