/*
     * Grant Poquiz
     * gep160230
     * 1337.007
     * Jason Smith
     * 4/28/2018
     * This program is intended to convert Project 3 into a doubly linked list with classes
*/
#include "List.h"
// input constructor, uses an input stream to create the class
List::List(std::istream& is) : Node()
{
    head = tail = nullptr;
    while (!is.eof())
    {
        BaseNode* newBase = new Node;
        is >> (newBase);
        if (newBase->getArabic())
        {
            Node* newNode = new Node(newBase);
            *this+=newNode;
        }
    }
}

// outputs the list from a node's position to the end (recursive)
void List::getList(std::ostream& os, Node* currentNode)
{
    if (!head)
        return;
    if (!currentNode)
        return;
    // BaseNode* cpyBase = currentNode;
    os << *currentNode;
    getList(os, currentNode->getNext());
}

// adds a node to the list and connects relevant nodes
void List::operator+=(Node* add)
{
    if (!head)
    {
        head = add;
        head->setPrev(nullptr);
        head->setNext(nullptr);
        tail = add;
        tail->setPrev(nullptr);
        tail->setNext(nullptr);
    }
    else
    {
        tail->setNext(add);
        tail->getNext()->setPrev(tail);
        tail = add;
        tail->setNext(nullptr);
    }
}

// removes the head of the list
void List::operator--()
{
    if (!head)
        return;
    Node *hold = head;
    head = head->getNext();

    if (head)
        head->setPrev(nullptr);

    delete hold;
}

// removes the tail of the list
void List::operator--(int)
{
    if (!head)
        return;
    Node *hold = tail;
    tail = tail->getPrev();

    if (tail)
        tail->setNext(nullptr);

    delete hold;
}

// removes an object from the list based on an index(index starts at one for this context)
void List::operator-(int index)
{
    if (!index)
        return;

    --index;
    Node *cpyNode = head;
    for(int i = 0; i < index; i++)
        cpyNode = cpyNode->getNext();

    if (cpyNode == head)
        --*this;
    else if (cpyNode == tail)
        (*this)--;
    else
        delete cpyNode;
}

// deleted the list by calling the prefix decrement until deletion
List::~List()
{
    while (head)
        --*this;
}
// adds a node based on either a string or an int
void List::addNode(std::string add)
{
    Node *newNode = new Node(add, romanToArabic(add));
    *this+=newNode;
}
void List::addNode(int add)
{
    Node *newNode = new Node(arabicToRoman(add), add);
    *this+=newNode;
}

// linearly search the Roman values
int List::searchList(std::string search)
{
    if (!head)
        return 0;
    Node *cpy = head;
    int index = 1;
    if (cpy->getRoman() == search)
        return index;


    while (cpy->getNext())
    {
        index++;
        cpy = cpy->getNext();
        if (cpy->getRoman() == search)
            return index;
    }
    return 0;
}

// linearly search the Arabic values
int List::searchList(int search)
{
    if (!head)
        return 0;
    Node *cpy = head;
    int index = 1;
    if (cpy->getArabic() == search)
        return index;

    while (cpy->getNext())
    {
        index++;
        cpy = cpy->getNext();
        if (cpy->getArabic() == search)
            return index;
    }
    return 0;
}

// sorts the list with a bubble sort
void List::Sort()
{
        if (!head)
            return;
    bool unsorted = true;
    while (unsorted)
    {
        Node* cpyHead = head;
        unsorted = false;
        while (cpyHead->getNext())
        {
            if (cpyHead->getNext()->getArabic() < cpyHead->getArabic())
            {
                // an exception for swapping the head
                if (cpyHead->getPrev())
                    cpyHead->getPrev()->setNext(cpyHead->getNext());
                else
                    head = cpyHead->getNext();

                cpyHead->getNext()->setPrev(cpyHead->getPrev());
                cpyHead->setPrev(cpyHead->getNext());
                cpyHead->setNext(cpyHead->getNext()->getNext());

                // an exception for swapping the tail
                if (cpyHead->getNext())
                    cpyHead->getNext()->setPrev(cpyHead);
                else
                    tail = cpyHead;

                cpyHead->getPrev()->setNext(cpyHead);

                unsorted = true;
            }
            else
            {
                cpyHead = cpyHead->getNext();
            }
        }

    }
}
