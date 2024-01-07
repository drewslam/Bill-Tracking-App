#include "../include/Bill.h"
#include "../include/LinkedList.h"

#include <iomanip>

LinkedListNode::LinkedListNode(Bill* bill) {
    this->data = bill;
    this->next = nullptr;
}

LinkedListNode::LinkedListNode() {
    this->data = nullptr;
    this->next = nullptr;
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

LinkedListNode* LinkedListNode::GetNext() const {
    return this->next;
}

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

void LinkedList::Append(LinkedListNode* node) {
    if (this->head == nullptr) {
        this->head = node;
        this->tail = this->head;
        std::cout << "head appended" << std::endl;
    } else {
        this->tail->SetNext(node);
        this->tail = this->tail->GetNext();
        std::cout << "tail appended" << std::endl;
    }
}

void LinkedList::Display() const {
    LinkedListNode* current = this->head;
    unsigned int i = 0;
    while (current != nullptr) {
        std::cout << std::setw(16) << std::setfill('-') << "" << std::endl;
        current->GetData()->Print();
        current = current->GetNext();
        i++;
    }
}

LinkedList::~LinkedList() {
    LinkedListNode* current = this->head;
    while (current != nullptr) { 
        LinkedListNode* temp = current;
        current = current->GetNext();
        delete temp->GetData();
        delete temp;
    }
}
