/*
     * Grant Poquiz
     * gep160230
     * 1337.007
     * Jason Smith
     * 4/28/2018
     * This program is intended to convert Project 3 into a doubly linked list with classes
*/
#include "BaseNode.h"

// outputs a term in the desired format
std::ostream& operator<<(std::ostream& os, const BaseNode& node)
{
    os << std::setw(16) << std::left << node.getRoman() << " " << std::setw(4) << node.getArabic() << std::endl;
    return os;
}

// inputs a term from an inpus stream
std::istream& operator>>(std::istream& is, BaseNode*& node)
{
    // REGRADE, Valid numerals in numbers spot and vice versa should not be considered valid
    // for holding the output/input data
    std::string newRoman;
    std::string newArabic;
    // input the whole roman field into
    char romanString [18];
    is.get(romanString, 18);
    newRoman = romanString;
    getline(is, newArabic);
    std::string inputCopy = "";

    // removes all spaces from the roman field
    for (unsigned int i = 0; i < newRoman.length(); i++)
        if (newRoman.at(i) != ' ')
            inputCopy += newRoman.at(i);

    bool isArabic = false;
    // removes all spaces from the arabic field if the roman field was empty
    if (inputCopy == "")
    {
        isArabic = true;
        for (unsigned int i = 0; i < newArabic.length(); i++)
            if (newArabic.at(i) != ' ')
                inputCopy += newArabic.at(i);
    }

    // decide whether the input was roman or arabic
    switch (node->validateInput(inputCopy))
    {
        case 1:
            if (!isArabic)
            {
                node->setRoman(inputCopy);
                node->setArabic(node->romanToArabic(inputCopy));
            }
            break;
        case 2:
            if (isArabic)
            {
                node->setArabic(stoi(inputCopy));
                node->setRoman(node->arabicToRoman(stoi(inputCopy)));
            }
            break;
    }
    return is;
}
// ensure the given string is either a valid number or a valid numeral
int BaseNode::validateInput(std::string input)
{
    bool hasChar = false;
    bool hasInt = false;

    // a character or int is in the string (valid strings will have only one or the other)
    for (unsigned int i = 0; i < input.length(); i++)
        isdigit(input.at(i)) ? (hasInt = true) : (hasChar = true);

    if (hasChar && hasInt)
        return 0;
    else if (!hasInt && (input == arabicToRoman(romanToArabic(input)))) // a valid numeral will convert to and back perfectly
        return 1;
    else if (!hasChar && stoi(input) < 4999 && stoi(input) > 0)
        return 2;

    return 0;
}

// converts a number into its roman numeral equivalent
char BaseNode::arabicToRomanChar(int arabic)
{
    switch (arabic)
    {
    case 1000:
        return 'M';
    case 500:
        return 'D';
    case 100:
        return 'C';
    case 50:
        return 'L';
    case 10:
        return 'X';
    case 5:
        return 'V';
    case 1:
        return 'I';
    }
    return 'Z';
}// end arabicToRomanChar

// returns a roman character for a arabic number
int BaseNode::romanToArabicNum(char roman)
{
    // case for each numeral
    switch(roman)
    {
    case 'M':
        return  1000;
    case 'D':
        return  500;
    case 'C':
        return  100;
    case 'L':
        return  50;
    case 'X':
        return  10;
    case 'V':
        return  5;
    case 'I':
        return  1;
    } // end case

    return 999999;
}// end romanToArabicNum

// converts numeral string to integer
int BaseNode::romanToArabic(std::string numeral)
{
    // convert the string to an vector of integers
   // vector<int> arabicNum(numeral.length());
    int * arabicNum = new int[numeral.length()];

    // sum to total numeral
    int sum = 0;

    // iterates through each letter
    for (size_t i = 0; i < numeral.length(); i++)
    {
        arabicNum[i] = romanToArabicNum(numeral.at(i));
    } // end for

    // adds each number in the numeral
    for (size_t i = 0; i < numeral.length(); i++)
    {
        // if the number after the current index is greater than the current index, the current index must be subtracted (in addition to an out of bounds catch)
        if ((i < numeral.length() - 1) && (arabicNum[i] < arabicNum[i + 1]))
        {
            sum -= arabicNum[i];
            continue;
        }

        sum += arabicNum[i];
    }
    delete [] arabicNum;

    // return total value of numeral
    return sum;
}// end romanToArabic

// converts an arabic number into a roman number string
std::string BaseNode::arabicToRoman(int arabicNum)
{
    std::string numeral = "";
    // base roman numeral, decrease from 1000 -> 1
    int numeralEquivalent = 1000;
    int count = 0;

    // will be used to decrease numeralEquivalent to its next step
    bool divisorToggle = true;

    // loop will continue until numeralEquivalent == 0
    while (numeralEquivalent)
    {

        // how many multiples of numeralEquivalent are there in the number
        count = (arabicNum - (arabicNum % numeralEquivalent)) / numeralEquivalent;

        // if there is a multiple of 4, a special case occurs
        if (count == 4 && numeralEquivalent != 1000)
        {
            // this is the multiplier to find the previous numeralEquivalent of the iteration
            int multiplier = divisorToggle ? 5: 2;

            // concatenate the characters of the next set
            std::string result =  "";

            result += arabicToRomanChar(numeralEquivalent);

            if (numeral.back() == arabicToRomanChar(numeralEquivalent * multiplier))
            {
                // the last number set was the previous numeralEquivalent and must be removed (the decimal was 9)
                result += arabicToRomanChar(numeralEquivalent * 10);
                numeral.pop_back();
            }
            else
            {
                // the last number set was beyond the previous numeral Equivalent (the decimal was 4)
                result += arabicToRomanChar(numeralEquivalent * 5);
            } // end if else for 9 vs 4 decision

            // append the result to the string
            numeral.append(result);
        }
        else
        {
            numeral.append(count, arabicToRomanChar(numeralEquivalent));
        } // end if else for special case

        // reduce arabicNum by one roman numeral "place" e.g.(500 ->100)
        arabicNum %=  numeralEquivalent;

        // divide by a number dependent on the toggle, then toggle it
        numeralEquivalent /= (divisorToggle = !divisorToggle) ? (5) : (2);
    }

    // return the end result
    return numeral;
}// end arabicToRoman
