//
// Created by Guglielmo Menchetti on 14/11/2018.
//

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() {
    head = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    Node* current = head;
    while(current != nullptr){
        Node* next = current->next;
        delete current;
        current = next;
    }
}

LinkedList::Node* LinkedList::getAt(int index) {
    if((index >= size) or (index < 0)) {
        std::cout << "Invalid index" << std::endl;
        return nullptr;
    }
    else{
        Node *current = head;
        int count = 0;
        while (count < index) {
            current = current->next;
            count++;
        }
        return current;
    }
}

void LinkedList::insertLast() {
    if( head == nullptr ){
        Node* newNode = new Node(size);
        head = newNode;
    }
    else {
        Node* curr = getAt(size - 1);
        Node* newNode = new Node(size);
        curr->next = newNode;
    }
    size++;
}

int LinkedList::getSize() {
    return size;
}

void LinkedList::deleteFirst() {
    if( size == 0 ) {
        std::cout << "Empty list" << std::endl;
    }
    else {
        Node* toDelete = head;
        head = head->next;
        delete(toDelete);
        size--;
    }
}

void LinkedList::printList() {
    std::cout << "Printing list" << std::endl;
    Node* current = head;
    std::cout << "ID: " << (*(current->musicPtr))->getId() << std::endl;
    while(current->next != nullptr){
        current = current->next;
        std::cout << "ID: " << (*(current->musicPtr))->getId() << std::endl;
    }
    std::cout << std::endl;
}

MusicClipPtr* LinkedList::getMusicPtr(int index) {
    if(getAt(index)->musicPtr != nullptr) {
        return getAt(index)->musicPtr;
    }
    else {
        return nullptr;
    }
}

void LinkedList::removeFromMemory(int index) {
    Node* toRemove = getAt(index);
    (toRemove->musicPtr)->saveToFile();
    (toRemove->musicPtr)->deleteClip();
}