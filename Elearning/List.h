#ifndef LIST_H
#define LIST_H

/*
     * Grant Poquiz
     * gep160230
     * 1337.007
     * Jason Smith
     * 4/28/2018
     * This program is intended to convert Project 3 into a doubly linked list with classes
*/
#include "Node.h"

// main list class
class List: public Node
{
    // keeps track of both the head and the tail of the list
    protected:
        Node *head;
        Node *tail;
        void Sort();
    public:
        // constructors
        List(){head = tail = nullptr;}
        List(const List& newList) : Node() {head = newList.getHead(); tail = newList.getTail();}
        List(Node *newHead){head = tail = newHead;}
        List(std::istream&);
        // import
        ~List();

        // acc
        Node* getHead() const {return head;}
        Node* getTail() const {return tail;}

        // mut
        void setHead(Node *newHead){head = newHead;}
        void setTail(Node *newTail){tail = newTail;}

        // outputs the list from a pointer's position to the tail
        void getList(std::ostream&, Node*);

        // adds nodes with either a string or an int
        void addNode(std::string);
        void addNode(int);

        // overloaded operators
        void operator+=(Node*);
        virtual void operator--();
        virtual void operator--(int);
        virtual void operator-(int);

        // searches the list from either a string or an int
        int searchList(std::string);
        int searchList(int);

};

#endif // LIST_H
