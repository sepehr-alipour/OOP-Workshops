/*
Name: 
Student ID: 
Email: 
OOP244ZAA
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Name.h"
#include <cstring>
#include <string>
using namespace std;
namespace sdds
{
    Name::Name()
    {
        setEmpty();
    }

    Name::Name(const char *fname)
    {
        set(fname);
    }

    Name::Name(const char *fname, const char *lname)
    {
        set(fname, lname);
    }

    Name::Name(const char *fname, const char *mname, const char *lname)
    {
        set(fname, mname, lname);
    }

    Name::Name(const Name &other)
    {
        if (other.middleName == nullptr && other.lastName != nullptr)
            set(other.firstName, other.lastName);
        else if (other.middleName != nullptr && other.lastName != nullptr)
            set(other.firstName, other.middleName, other.lastName);
        else
            set(other.firstName);
    }

    Name::~Name()
    {
        delete[] firstName;
        delete[] middleName;
        delete[] lastName;
    }

    Name &Name::operator=(const Name &other)
    {
        if (this != &other)
        {
            if (other.middleName == nullptr && other.lastName != nullptr)
                set(other.firstName, other.lastName);
            else if (other.middleName != nullptr && other.lastName != nullptr)
                set(other.firstName, other.middleName, other.lastName);
            else
                set(other.firstName);
        }
        return *this;
    }

    Name &Name::operator+=(const char *cstr)
    {
        if (!valid(cstr))
            return *this;
        if (strchr(cstr, ' ') != NULL)
             return *this;
        if(valid(firstName, middleName, lastName))
        {
            delete [] firstName;
            delete [] middleName;
            delete [] lastName;
            setEmpty();
        }
        else if(firstName == nullptr)
            set(cstr);
        else if (middleName == nullptr)
        {
            delete[] middleName;
            middleName = new char[strlen(cstr) + 1];
            strcpy(middleName, cstr);
        }
        else if(lastName == nullptr)
        {
            delete[] lastName;
            lastName = new char[strlen(cstr) + 1];
            strcpy(lastName, cstr);            
        }
        else {}
        return *this;
    }

    void Name::set(const char *fname)
    {
        if (!valid(fname))
        {
            delete[] firstName;
            setEmpty();
        }
        else
            allocateAndCopy(fname);
    }

    void Name::set(const char *fname, const char *lname)
    {
        if (!valid(fname, lname))
        {
            delete [] firstName;
            delete [] lastName;

            setEmpty();
        }
        else
            allocateAndCopy(fname, lname);
    }

    void Name::set(const char *fname, const char *mname, const char *lname)
    {
        if (!valid(fname, mname, lname))
        {
            delete [] firstName;
            delete [] lastName;
            delete [] middleName;
            setEmpty();
        }
        else
            allocateAndCopy(fname, mname, lname);
    }

    istream &operator>>(istream &istr, Name &n)
    {
        delete[] n.firstName;
        delete[] n.middleName;
        delete[] n.lastName;
        n.setEmpty();
        string fname, mname, lname, tmp;
        istr >> fname;
        if (istr.peek() != '\n')
            istr >> mname;
        if (istr.peek() != '\n')
            istr >> lname;
        if (istr.peek() != '\n')
            istr >> tmp;

        if (!tmp.empty())
            n.setEmpty();
        else if (!mname.empty() && lname.empty())
        {
            n.set(fname.c_str(), mname.c_str());
        }
        else if (!mname.empty() && !lname.empty())
        {
            n.set(fname.c_str(), mname.c_str(), lname.c_str());
        }
        else
        {
            n.set(fname.c_str());
        }

        return istr;
    }

    ostream &operator<<(ostream &ostr, const Name &n)
    {
        if (n)
        {
            if (n.middleName != nullptr && n.lastName != nullptr)
                ostr << n.firstName << " " << n.middleName << " " << n.lastName;
            else if (n.middleName == nullptr && n.lastName != nullptr)
                ostr << n.firstName << " " << n.lastName;
            else if (n.middleName != nullptr && n.lastName == nullptr)
                ostr << n.firstName << " " << n.middleName;
            else
                ostr << n.firstName;
        }
        else
            ostr << "Bad Name";

        return ostr;
    }

    Name::operator bool() const
    {
        if (firstName != nullptr)
            return true;
        return false;
    }

    void Name::setShort(bool abr)
    {
        if (abr)
        {
            if (middleName != nullptr)
            {
                string s(middleName);
                string temp;
                temp.push_back(s[0]);
                temp += ".";
                strcpy(middleName, temp.c_str());
            }
        }
    }

    void Name::setEmpty()
    {
        firstName = nullptr;
        middleName = nullptr;
        lastName = nullptr;
    }

    bool Name::valid(const char *str)
    {
        if (str == nullptr || strlen(str) == 0 || strcmp(str, " ") == 0)
            return false;
        return true;
    }

    bool Name::valid(const char *str1, const char *str2)
    {
        if (!valid(str1) || str2 == nullptr || strlen(str2) == 0 || strcmp(str2, " ") == 0)
            return false;
        return true;
    }

    bool Name::valid(const char *str1, const char *str2, const char *str3)
    {
        if (!valid(str1, str2) || str3 == nullptr || strlen(str3) == 0 || strcmp(str3, " ") == 0)
            return false;
        return true;
    }

    void Name::allocateAndCopy(const char *fname)
    {
        delete[] firstName;
        firstName = new char[strlen(fname) + 1];
        strcpy(firstName, fname);
    }

    void Name::allocateAndCopy(const char *fname, const char *lname)
    {
        allocateAndCopy(fname);
        delete[] lastName;
        lastName = new char[strlen(lname) + 1];
        strcpy(lastName, lname);
    }

    void Name::allocateAndCopy(const char *fname, const char *mname, const char *lname)
    {
        allocateAndCopy(fname, lname);
        delete[] middleName;
        middleName = new char[strlen(mname) + 1];
        strcpy(middleName, mname);
    }
}