/*
Name:
Student ID:
Email:
OOP244ZAA
*/

#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>
using namespace std;
namespace sdds
{
    class Name
    {
        char *firstName{};
        char *middleName{};
        char *lastName{};
        public:
            Name();
            Name(const char* fname);
            Name(const char* fname, const char* lname);
            Name(const char* fname, const char* mname, const char* lname);
            Name(const Name& other);
            ~Name();
            Name& operator=(const Name& other);
            Name& operator+=(const char* cstr);
            operator bool() const;
            void setShort(bool abr);
            void set(const char* fname);
            void set(const char* fname, const char* lname);
            void set(const char* fname, const char*mname, const char*lname);
            friend istream& operator>>(istream& istr, Name& n);
            friend ostream& operator<<(ostream& ostr, const Name& n);
        private:
            void setEmpty();
            bool valid(const char* str);
            bool valid(const char* str1, const char* str2);
            bool valid(const char* str1, const char* str2, const char* str3);
            void allocateAndCopy(const char *fname);
            void allocateAndCopy(const char* fname, const char* lname);
            void allocateAndCopy(const char* fname, const char* mname, const char* lname);
    };  
}
#endif // !SDDS_Name_H
