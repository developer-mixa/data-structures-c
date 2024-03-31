#ifndef DATA_STRUCTURES_C_LINKEDLIST_H
#define DATA_STRUCTURES_C_LINKEDLIST_H

#include "iostream"
#include "stddef.h"

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T data, Node* next) : data(data), next(next) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int length;

public:
    LinkedList() : head(NULL), length(0) {}
    ~LinkedList() {
        Node<T>* current = head;
        Node<T>* nextNode;

        while (current != NULL) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = NULL;
        length = 0;
    }

    void insertAtBeginning(T data) {
        Node<T>* newNode = new Node<T>(data, head);
        head = newNode;
        length++;
    }

    void insertAtEnd(T data){
        Node<T>* newNode = new Node<T>(data, NULL);

        if(this->head == NULL){
            insertAtBeginning(data);
            return;
        }

        Node<T>* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        length++;

    }

    void insertAt(T data, int position){

        if(position < 0 || position > getLength()){
            return;
        }

        if(position == 0){
            insertAtBeginning(data);
        }

        Node<T>* current = head;
        int count = 0;
        while (true) {
            if(count == position - 1){
                Node<T>* newNode = new Node<T>(data, current->next);
                current->next = newNode;
                break;
            }
            current = current->next;
            count++;
        }
        length++;
    }

    void insertValues(T data[], int size){
        for (int i = 0; i < size; i++) {
            insertAtEnd(data[i]);
        }
    }

    void removeAt(int position){

        if(position < 0 || position > getLength() - 1){
            return;
        }

        Node<T>* current = head;
        int count = 0;
        while (true) {
            if(count == position - 1){
                Node<T>* newNode = current->next->next;
                current->next = newNode;
                break;
            }
            current = current->next;
            count++;
        }
        length--;
    }

    void swap(int firstIndex, int secondIndex){
        int needLength = getLength() - 1;
        if(firstIndex < 0 || firstIndex > needLength || secondIndex < 0 || secondIndex > needLength){
            return;
        }

        if(firstIndex == secondIndex) return;

        int maxIndex = max(firstIndex, secondIndex);

        Node<T>* firstItem = head;
        Node<T>* secondItem = head;
        int count = 0;
        while (true) {

            if(count < firstIndex){
                firstItem = firstItem->next;
            }

            if(count < secondIndex){
                secondItem = secondItem->next;
            }

            if(count == maxIndex){
                T tempFirstData = firstItem->data;
                firstItem->data = secondItem->data;
                secondItem->data = tempFirstData;
                break;
            }

            count++;
        }
    }

    void reverse() {
        Node<T>* previousNode = NULL;
        Node<T>* currentNode = head;
        Node<T>* nextNode = NULL;

        while (currentNode != NULL) {
            nextNode = currentNode->next;
            currentNode->next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }

        head = previousNode;
    }

    void removeLast(){
        removeAt(getLength()-1);
    }

    int getLength(){
        return this->length;
    }

    void print() {
        Node<T>* current = head;
        while (current != NULL) {
            cout << current->data;
            if (current->next != NULL) {
                cout << " --> ";
            }
            current = current->next;
        }
        cout << endl;
    }
};


#endif //DATA_STRUCTURES_C_LINKEDLIST_H
