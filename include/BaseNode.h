/*
     * Grant Poquiz
     * gep160230
     * 1337.007
     * Jason Smith
     * 4/28/2018
     * This program is intended to convert Project 3 into a doubly linked list with classes
*/
#ifndef BASENODE_H
#define BASENODE_H
#include <string>
#include <iostream>
#include <iomanip>

// base node that holds data and functions related to roman and arabic calculations
class BaseNode
{
    protected:
        std::string roman;
        int arabic;

        int validateInput(std::string);

        int romanToArabicNum(char roman);
        char arabicToRomanChar(int arabic);

        int romanToArabic(std::string);
        std::string arabicToRoman(int);
    public:
        // constructors
        BaseNode(){arabic = 0; roman = "";}
        BaseNode(std::string newRoman, int newArabic){roman = newRoman; arabic = newArabic;}
        BaseNode(BaseNode*& cpyNode){arabic = cpyNode->getArabic(); roman = cpyNode->getRoman();}

        // define this as an abstract base class
        virtual std::string getRoman() const = 0;
        // various getters/setters
        int getArabic() const {return arabic;}
        void setRoman(std::string newRoman){roman = newRoman;}
        void setArabic(int newArabic){arabic = newArabic;}

        // overloaded operators
        friend std::ostream& operator<<(std::ostream&, const BaseNode&);
        friend std::istream& operator>>(std::istream&, BaseNode*&);
};

#endif // BASENODE_H
