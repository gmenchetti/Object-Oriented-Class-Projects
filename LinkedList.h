//
// Created by Guglielmo Menchetti on 14/11/2018.
//

#ifndef HW4_LINKEDLIST_H
#define HW4_LINKEDLIST_H

#include "MusicClipPtr.h"

class LinkedList {

    class Node {
    friend class LinkedList;

    private:
        MusicClipPtr *musicPtr;
        Node *next;

        Node(int index){
            this->musicPtr = new MusicClipPtr(index);
            this->next = nullptr;
        }
    };

private:
    Node* head;
    int size;
    Node* getAt(int index);

public:
    LinkedList();
    ~LinkedList();
    void printList();
    void insertLast();
    void deleteFirst();
    int getSize();

    MusicClipPtr* getMusicPtr(int index);
    void removeFromMemory(int index);
};


#endif //HW4_LINKEDLIST_H
