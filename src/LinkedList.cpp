#include "../include/Bill.h"
#include "../include/LinkedList.h"

#include <iomanip>
#include <fstream>

LinkedList::LinkedList() {
    this->head = nullptr;
    this->tail = nullptr;
}

void LinkedList::Append(LinkedListNode* node) {
    if (this->head == nullptr) {
        this->head = node;
        this->tail = this->head;
    } else {
        this->tail->SetNext(node);
        this->tail = this->tail->GetNext();
    }
}

void LinkedList::RemoveAfter(LinkedListNode* node) {
    if (node->GetNext() == nullptr) {
        return;
    } else {
        LinkedListNode* toBeRemoved = node->GetNext();
        LinkedListNode* successor = node->GetNext()->GetNext();
        node->SetNext(successor);
        delete toBeRemoved;
    }
}

void LinkedList::DisplayList() const {
    LinkedListNode* current = this->head;
    unsigned int i = 0;
    while (current != nullptr) {
        std::cout << std::setw(16) << std::setfill('-') << "" << std::endl;
        current->GetData()->Print();
        current = current->GetNext();
        i++;
    }
}

void LinkedList::PrintList(std::ofstream& outFS) const {
    LinkedListNode* current = this->head;
    while (current) {
        current->GetData()->Print(outFS);
        current = current->GetNext();
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
