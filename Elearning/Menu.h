/*
     * Grant Poquiz
     * gep160230
     * 1337.007
     * Jason Smith
     * 4/28/2018
     * This program is intended to convert Project 3 into a doubly linked list with classes
*/
#ifndef MENU_H
#define MENU_H

#include <List.h>

// class that outlines a menu using the list provided
class Menu : public List
{
    private:
        void outputCar();
        void searchSelection();
        void addSelection();
        void deleteSelection();
    public:
        // chaining constructors to List
        Menu() : List(){};
        Menu(List& newList) : List(newList){}
        Menu(Node* newHead) : List(newHead){}
        Menu(std::istream& is) : List(is) {Sort();}
        // outputs the menu
        void MainMenu();
};

#endif // MENU_H
