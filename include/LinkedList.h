#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Bill.h"

class LinkedListNode {
    public:
        LinkedListNode(Bill* bill);
        LinkedListNode();
        void SetData(Bill* bill);
        Bill* GetData() const;
        void SetNext(LinkedListNode* node);
        LinkedListNode* GetNext() const;
    private:
        Bill* data;
        LinkedListNode* next;
};

class LinkedList {
    public:
        LinkedList();
        void Append(LinkedListNode* node);
        void Display() const;
        ~LinkedList();
    private:
        LinkedListNode* head;
        LinkedListNode* tail;
};

#endif
