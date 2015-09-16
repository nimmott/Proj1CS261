/*
 * File:   DOLinkedList.h
 * Author: Harrison Brace
 *
 * Created on September 10, 2015, 4:40 PM
 */

#ifndef DOLINKEDLIST_H
#define	DOLINKEDLIST_H
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node <T> * next;
    Node <T> * previous;
    
    Node (T element): data (element), next (NULL), previous (NULL){}
    
    Node(): next (NULL), previous (NULL) {}
};

template <typename T>
class DOLinkedList{
public:
    
    DOLinkedList (): head (NULL), tail (NULL), size (0){}
    virtual ~DOLinkedList();
    
    int getSize(){return size;}
    void add(T element);
    void deleteElement (T element);
    
private:
    Node <T> * head;
    Node <T> * tail;
    int size;
    
};

template<typename T>
void DOLinkedList<T>::deleteElement(T element){
   Node<T> * current = head;
    
    if (head == NULL){
        cout <<"Deleting from empty list"<<endl;
        return;
    }
    
    if (head->data == element && head->next != NULL){ //deleting first element it's not the only element
        head = head->next;
        head->previous = NULL;
        delete current;
        current = NULL;
        size --;
        return;
    }
    
    if (head!=NULL && head->next == NULL && head->data == element){ //deleting head when it's the only element
        delete head;
        head = NULL;
        tail = NULL;
        cout <<"List is now empty"<<endl;
        size--;
        return;
    }
    
    
    
    while (current != NULL){
        if (current->data == element && current->next == NULL){ //deleting last element
            current->previous->next = NULL;                     //we know last element != head
            tail = current->previous;
            delete current;
            current = NULL;
            size--;
            return;
        }
        
        if (current->data == element){ //deleting element in the middle of list
            current->previous->next = current->next;
            current->next->previous = current->previous;
            delete current;
            current = NULL;
            size --;
            return;
        }
        current = current->next;
    }
}

template <typename T>
DOLinkedList<T>::~DOLinkedList(){
    Node <T> * current = head;
    Node <T> * previous = NULL;
    while (current!= NULL){
        previous = current;
        current = current->next;
        delete previous;
        size--;
    }
}

template <typename T>
void DOLinkedList<T>::add (T element){
    Node <T> * current = head;
    Node <T> * newnode = new Node <T> (element);
    if (head == NULL){  //inserting first element
        head = newnode;
        tail = head;
        size++;
        return;
    }
    
    if (head != NULL && element <= head->data) //inserting item before head when head it not the only item
    {
        head = newnode;
        head->next = current;
        current->previous = head;
        size ++;
        if (current->next == NULL){
            tail = current;
        }
        
        return;
        
    }
    
    while (current != NULL){
        cout << "entering while loop"<<endl;
      //  system("pause");
                if (element <= current->data){
            current->previous->next = newnode;
            newnode->previous = current->previous;
            newnode->next = current;
            current->previous = newnode;
                    size++;
                    return;
        }
        
        if (current->next == NULL){  //adding to end of list
            current->next = newnode;
            newnode->previous = current;
            tail = newnode;
            size ++;
            return;
        }
        current = current->next;

    }
}
#endif	/* DOLINKEDLIST_H */

