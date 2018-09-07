/*
     * Grant Poquiz
     * gep160230
     * 1337.007
     * Jason Smith
     * 4/28/2018
     * This program is intended to convert Project 3 into a doubly linked list with classes
*/
#include "Menu.h"

// still a 'fun'ction
void Menu::outputCar()
{
    std::cout << "1. Search|~--__                      __--~~~~---__" << '\n'
     << "2. Add   |~~~~~\\\\                    //~~~~~~~~---/'  " << '\n'
     << "3. Delete First\\||                  ||/~~~~~~~~~\\/ " << '\n'
     << "4. Delete Last  `\\\\               //'" << '\n'
     << "5. Exit          `\\\\            //'" << '\n'
     << "6. Delete Specific Node        ||              " << '\n'
     << "         ______--~~~~~~~~~~~~~~~~~~--______              " << '\n'
     << "    ___ // _-~                        ~-_ \\ ___  " << '\n'
     << "   `\\__)\\/~                              ~\\/(__/'          " << '\n'
     << "    _--`-___                            ___-'--_        " << '\n'
     << "  /~     `\\ ~~~~~~~~------------~~~~~~~~ /'     ~\\        " << '\n'
     << " /|        `\\         ________         /'        |\\     " << '\n'
     << "| `\\   ______`\\_      \\------/      _/'______   /' |          " << '\n'
     << "|   `\\_~-_____\\ ~-________________-~ /_____-~_/'   |  " << '\n'
     << "`.     ~-__________________________________-~     .'       " << '\n'
     << " `.      [_______/------|~~|------\\_______]      .'" << '\n'
     << "  `\\--___((____)(________\\/________)(____))___--/'           " << '\n'
     << "   |>>>>>>||                            ||<<<<<<|" << '\n'
     << "   `\\<<<<</'                            `\\>>>>>/' " << '\n'
     << "credit to http://flipmytext.com/ascii/cars.php" << '\n';
}

// outputs a main menu and calls desired functions
void Menu::MainMenu()
{
    std::string userInput;
    do
    {
        std::cout << "" << std::flush;
        outputCar();

        do
        {
            std::cout << "Select an Option: ";
            std::cin >> userInput;
        } while (userInput != "1" && userInput != "2" && userInput != "3" && userInput != "4" && userInput != "5" && userInput != "6");

        switch (std::stoi(userInput))
        {
            case 1:
                searchSelection();
                break;
            case 2:
                addSelection();
               break;
            case 3:
                --*this; // delete head
                break;
            case 4:
                (*this)--; // delete tail
                break;
            case 6:
                deleteSelection();

        }
        // prompt for input and then clear the screen
        system("pause");
        system("CLS");
        void addNode(std::string);
    } while (userInput != "5");
}

// deletes based on input from user
void Menu::deleteSelection()
{
    std::string search;
    // REGRADE checking for a string literal means we don't need to reset the stream on bad input.
    do
    {
        std::cout << "Enter a term to delete: ";
        std::cin >> search;
    } while (!validateInput(search));

    int itemFound = 0;
    // if the input is valid arabic or numeral, then search
    switch (validateInput(search))
    {
        case 1:
             (*this) - (itemFound = searchList(search));
            break;
        case 2:
            (*this) - (itemFound = searchList(stoi(search)));
            break;
    }
    // i really shouldn't use ternary this much
    std::cout <<"'" << search << "' " << ((itemFound) ? ("deleted.\n") : ("not found.\n"));
}

// adds a node based on the user's input
void Menu::addSelection()
{
    std::string add;
    // REGRADE checking for a string literal means we don't need to reset the stream on bad input.
    do
    {
        std::cout << "Enter a term to add: ";
        std::cin >> add;
    } while (!validateInput(add));

    // if the input is valid arabic or numeral, then search
    switch (validateInput(add))
    {
        case 1:
            addNode(add);
            Sort();
            break;
        case 2:
            addNode(stoi(add));
            Sort();
            break;
    }
}
// prompts for a search term
void Menu::searchSelection()
{
    std::string search;

    // REGRADE checking for a string literal means we don't need to reset the stream on bad input.
    do
    {
        std::cout << "Enter a term to search for: ";
        std::cin >> search;
    } while (!validateInput(search));

    int itemFound = false;
    // if the input is valid arabic or numeral, then search
    switch (validateInput(search))
    {
        case 1:
            itemFound = searchList(search);
            break;
        case 2:
            itemFound = searchList(stoi(search));
            break;
    }
    // i really shouldn't use ternary this much
    std::cout <<"'" << search << "' " << ((itemFound) ? ("found.\n") : ("not found.\n"));
}
