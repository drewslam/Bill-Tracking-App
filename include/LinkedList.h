#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <fstream>
#include "Bill.h"
#include "LinkedListNode.h"

class LinkedList {
    public:
        LinkedList();
        void Append(LinkedListNode* node);
        void RemoveAfter(LinkedListNode* node);
        void DisplayList() const;
        void PrintList(std::ofstream& outFS) const;
        ~LinkedList();
    private:
        LinkedListNode* head;
        LinkedListNode* tail;
};

#endif
