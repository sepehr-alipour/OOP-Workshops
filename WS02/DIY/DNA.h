
/* ------------------------------------------------------
Workshop 2 part 2
Module: N/A
Filename: DNA.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       01/30/2022
-----------------------------------------------------------*/
#ifndef _DNA_H
#define _DNA_H
namespace sdds {
	struct DNA {
		int id;
		char* records;
	};
	bool beginSearch(const char* filename);
	bool read(const char* subDNA);
	void sort();
	void displayMatches();
	void deallocate();
	void endSearch();
	void record(const DNA& dna);
}
#endif
