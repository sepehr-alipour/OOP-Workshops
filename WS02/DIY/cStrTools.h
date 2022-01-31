
/* ------------------------------------------------------
Workshop 2 part 2
Module: N/A
Filename: cStrTools.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       01/30/2022
-----------------------------------------------------------*/
#ifndef _CSTRTOOLS_H
#define _CSTRTOOLS_H
namespace sdds {

	char toLower(char ch);
	int strCmp(const char* s1, const char* s2);
	int strnCmp(const char* s1, const char* s2, int len);
	void strCpy(char* des, const char* src);
	int strLen(const char* str);
	const char* strStr(const char* str, const char* find);
	int isAlpha(char ch);
	int isSpace(char ch);
	void trim(char word[]);
	void toLowerCaseAndCopy(char des[], const char source[]);
	void read(char* cString, unsigned int maxSize, char delimiter = '\n');

}
#endif
