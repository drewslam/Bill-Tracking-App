#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include "Bill.h"

class LinkedListNode {
    public:
        LinkedListNode(Bill* bill);
        LinkedListNode();
        void SetData(Bill* bill);
        Bill* GetData() const;
        void SetNext(LinkedListNode* node);
        void SetPrevious(LinkedListNode* node);
        LinkedListNode* GetNext() const;
        LinkedListNode* GetPrevious() const;
    private:
        Bill* data;
        LinkedListNode* next;
        LinkedListNode* previous;
};

#endif
