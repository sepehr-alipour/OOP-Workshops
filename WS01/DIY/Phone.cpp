/* ------------------------------------------------------
Workshop 1 part 2
Module: N/A
Filename: Phone.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       01/23/2022
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

#include "Phone.h"
#include "cStrTools.h"

#define MAX_SIZE 51

using namespace std;

namespace sdds

{
	void closefile(FILE* fptr) {

		fclose(fptr);
		fptr = nullptr;
	}
	void phoneDir(const char* programTitle, const char* fileName)

	{
		cout << programTitle << " phone direcotry search\n";
		cout << "-------------------------------------------------------\n";
		FILE* fptr = fopen(fileName, "r");
		char query[MAX_SIZE];
		if (!fptr) {

			cout << fileName << " file not found!" << endl;
		}
		else {
			do {

				char copyName[MAX_SIZE];
				char name[MAX_SIZE];
				char area[MAX_SIZE];
				char prefix[MAX_SIZE];
				char number[MAX_SIZE];

				cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
				cout << "> ";
				cin >> query;
				toLowerCaseAndCopy(query, query);

				rewind(fptr);
				while (!feof(fptr))

				{
					fscanf(fptr, "%[^\t]\t%s\t%s\t%s\n", name, area, prefix, number);


					toLowerCaseAndCopy(copyName, name);
					if (strStr(copyName, query))
					{
						cout << name << ": (" << area << ") " << prefix << "-" << number << endl;
					}


				}
				
			} while (strCmp(query, "!") != 0);
			closefile(fptr);
		}
		
		cout << "Thank you for using " << programTitle << " directory." << endl;
	
	}
	
}