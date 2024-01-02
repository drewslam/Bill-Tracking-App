#include "../include/Bill.h"
#include "../include/LinkedList.h"

LinkedListNode::LinkedListNode(Bill* bill) {
    this->data = bill;
    this->next = nullptr;
}

LinkedListNode::LinkedListNode() {
    this->data = nullptr;
    this->next = nullptr;
}

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
} 

void LinkedList::append(Bill* bill) {
    LinkedListNode* newNode = new LinkedListNode(bill);
    if (head == nullptr) {
        this->head = this->tail;
        this->tail = newNode;
    } else {
        this->tail->next = newNode;
        this->tail = newNode;
    }
}

void LinkedList::Display() const {
    LinkedListNode* current = this->head;
    unsigned int i = 0;
    while (current != nullptr) {
        current->data->Print();
        current = current->next;
        i++;
    }
    std::cout << i << std::endl;
}

LinkedList::~LinkedList() {
    LinkedListNode* current = head;
    while (current != nullptr) {
        LinkedListNode* temp = current;
        current = current->next;
        delete temp->data;
        delete temp;
    }
}
