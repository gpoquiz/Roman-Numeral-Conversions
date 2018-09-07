/*
     * Grant Poquiz
     * gep160230
     * 1337.007
     * Jason Smith
     * 4/28/2018
     * This program is intended to convert Project 3 into a doubly linked list with classes
*/
#ifndef NODE_H
#define NODE_H

#include <BaseNode.h>

// derived from basenode, contains information for next and previous nodes for a double link
class Node : public BaseNode
{
    protected:
        Node *next;
        Node *prev;
    public:
        // constructors define next and previous as null
        Node() : BaseNode() {next = prev = nullptr;}
        // calls basenode constructor
        Node(std::string newRoman, int newArabic) : BaseNode(newRoman, newArabic){next = prev = nullptr;}
        // copy constructor
        Node(BaseNode*& cpyNode) : BaseNode(cpyNode){};
        std::string getRoman() const{return roman;}

        Node* getNext(){return next;}
        Node* getPrev(){return prev;}
        void setNext(Node *newNext){next = newNext;}
        void setPrev(Node *newPrev){prev = newPrev;}

        // when a node is deleted, connect the previous next pointers together
        virtual ~Node() {if (prev) prev->setNext(next); if (next) next->setPrev(prev);}

};

#endif // NODE_H
