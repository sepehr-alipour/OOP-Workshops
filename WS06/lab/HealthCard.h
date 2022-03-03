
/* ------------------------------------------------------
Workshop 6 part 1
Module: N/A
Filename: HealthCard.h
Version 1
Author	Sepehr Alipour
Email   salipour2@myseneca.ca
StudentID 107296212
Revision History
-----------------------------------------------------------
Date       03/03/2022
-----------------------------------------------------------*/

#ifndef SDDS_HEALTHCARD_H
#define SDDS_HEALTHCARD_H

namespace sdds {
   const int MaxNameLength = 55;
   class HealthCard {
      char* m_name{};
      long long m_number;
      char m_vCode[3];
      char m_sNumber[10];
   public:
       HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]);
       ~HealthCard();
       HealthCard();
       bool validID(const char* name, long long number, const char vCode[], const char sNumber[]) const;
       void setEmpty();
       void allocateAndCopy(const char* name);
       void set(const char* name, long long number, const char vCode[], const char sNumber[]);
       


       HealthCard(const HealthCard& hc);

    
      
      



   };

  
}
#endif // !SDDS_HealthCard_H


