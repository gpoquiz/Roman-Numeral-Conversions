/*
     * Grant Poquiz
     * gep160230
     * 1337.007
     * Jason Smith
     * 4/28/2018
     * This program is intended to convert Project 3 into a doubly linked list with classes
     * Overloaded operators used in
     * Menu.cpp
     * 52, 55, 84, 87
     * List.cpp
     * 9, 13, 26, 91, 93, 102, 108, 113
     * EXTRA CREDIT ATTEMPTED
     * menu.cpp Line 69, List.cpp Line 80
*/
#include <iostream>
#include <fstream>
#include "Menu.h"
using namespace std;

int main()
{
    // open file
    string filename = "input.txt";
    ifstream inputFile(filename, ios::in);
    // error if file does not exist
    if (!inputFile.is_open())
        return 1;

    // create a new menu
    Menu newMenu(inputFile);
    // display the main menu and close the input
    inputFile.close();
    newMenu.MainMenu();
    // open the same file to output to
    ofstream outputFile(filename);
    newMenu.getList(outputFile, newMenu.getHead());
    outputFile.close();
    return 0;
}
