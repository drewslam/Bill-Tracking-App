#include "../include/LinkedListNode.h"

LinkedListNode::LinkedListNode(Bill* bill) {
    this->data = bill;
    this->next = nullptr;
    this->previous = nullptr;
}

LinkedListNode::LinkedListNode() {
    this->data = nullptr;
    this->next = nullptr;
    this->previous = nullptr;
}

void LinkedListNode::SetData(Bill* bill) {
    this->data = bill;
}

Bill* LinkedListNode::GetData() const {
    return this->data;
}

void LinkedListNode::SetNext(LinkedListNode* node) {
    this->next = node;
}

void LinkedListNode::SetPrevious(LinkedListNode* node) {
    this->previous = node;
}

LinkedListNode* LinkedListNode::GetNext() const {
    return this->next;
}

LinkedListNode* LinkedListNode::GetPrevious() const {
    return this->previous;
}
