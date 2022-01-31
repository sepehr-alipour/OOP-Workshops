/* ------------------------------------------------------
Workshop 2 part 2
Module: N/A
Filename: DNA.cpp
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       01/30/2022
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "cStrTools.h"
#include "DNA.h"
using namespace std;
namespace sdds {
	FILE* file;
	DNA* dnaList;
	int allocationSize;
	int numberOfMatches;
	int dnaArraySize;

	bool beginSearch(const char* filename) {
		cout << "DNA search program" << endl;

		file = fopen(filename, "r");
		numberOfMatches = 0;
		dnaArraySize = 2;
		allocationSize = 2;
		dnaList = new DNA[allocationSize];

		if (file)
			return true;
		return false;

	}
	bool read(const char* subDNA) {
		int id;
		char records[1001];
		string mytext;
		bool isMatched = false;
		while (fgetc(file) != EOF) {
			fscanf(file, "%d,%s", &id, records);
			if (strStr(records, subDNA)) {
				isMatched = true;
				DNA newDna = { 0 };
				newDna.id = id;
				newDna.records = new char[strLen(records) + 1];

				strCpy(newDna.records, records);
				record(newDna);
			}
		}
		return isMatched;
	}
	void record(const DNA& dna) {
		if (numberOfMatches == dnaArraySize) {
			DNA* tempPtrDNA = nullptr;
			tempPtrDNA = new DNA[dnaArraySize + allocationSize];
			for (int i = 0; i < dnaArraySize; i++)
			{
				tempPtrDNA[i].records = dnaList[i].records;
				tempPtrDNA[i].id = dnaList[i].id;
			}

			delete[] dnaList;

			dnaList = tempPtrDNA;

			dnaArraySize += allocationSize;

		}
		dnaList[numberOfMatches] = dna;
		numberOfMatches++;
	}
	void sort() {

		int i, j;
		struct DNA swap;
		for (i = 0; i < (numberOfMatches - 1); i++)
		{
			for (j = 0; j < numberOfMatches - i - 1; j++)
			{
				if (dnaList[j].id > dnaList[j + 1].id)
				{
					swap = dnaList[j];
					dnaList[j] = dnaList[j + 1];
					dnaList[j + 1] = swap;
				}
			}
		}

	}
	void displayMatches() {
		cout << numberOfMatches << " matches found:" << endl;
		for (int i = 0; i < numberOfMatches; i++)
		{
			cout << i + 1
				<< ") "
				<< dnaList[i].id
				<< ":"
				<< endl
				<< dnaList[i].records
				<< endl
				<< "======================================================================"
				<< endl;

		}

	}
	void deallocate() {
		for (int i = 0; i < numberOfMatches; i++)
		{
			delete[] dnaList[i].records;
			dnaList[i].records = nullptr;
		}
		delete[] dnaList;
		dnaList = nullptr;

	}
	void endSearch() {
		cout << "DNA Search Program Closed." << endl;
		fclose(file);
	}

}