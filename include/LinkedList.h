#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Bill.h"

class LinkedListNode {
    public:
        LinkedListNode(Bill* bill);
        LinkedListNode();
        Bill* data;
        LinkedListNode* next;
};

class LinkedList {
    public:
        LinkedList();
        void append(Bill* bill);
        void Display() const;
        ~LinkedList();
    private:
        LinkedListNode* head;
        LinkedListNode* tail;
};

#endif
