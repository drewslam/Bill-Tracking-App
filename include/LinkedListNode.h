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
        LinkedListNode* GetNext() const;
    private:
        Bill* data;
        LinkedListNode* next;
};

#endif
