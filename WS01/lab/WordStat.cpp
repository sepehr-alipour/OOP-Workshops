/* ------------------------------------------------------
Workshop 1 part 1
Module: N/A
Filename: WordStat.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       01/18/2022
-----------------------------------------------------------*/
#include <iostream>
#include "Word.h"
using namespace sdds;
using namespace std;


int main() {
	char filename[256];
	programTitle();
	cout << "Enter filename: ";
	cin >> filename;
	wordStats(filename);
	return 0;
}
