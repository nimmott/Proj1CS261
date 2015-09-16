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
    
    DOLinkedList (): head (NULL), size (0){}
    virtual ~DOLinkedList();
    
    int getSize(){return size;}
    void add(T element);
    
private:
    Node <T> * head;
    int size;
    
};

template <typename T>
DOLinkedList<T>::~DOLinkedList(){
    Node <T> * current = head;
    Node <T> * previous = NULL;
    while (current!= NULL){
        previous = current;
        current = current->next;
        delete previous;
    }
}

template <typename T>
void DOLinkedList<T>::add (T element){
    Node <T> * current = head;
    Node <T> * newnode = new Node <T> (element);
    if (head == NULL){
        head = newnode;
        size++;
        return;
    }
    
    if (head != NULL && element <= head->data)
    {
        head = newnode;
        head->next = current;
        current->previous = head;
        size ++;
        return;
        
    }
    
    
    if (current->previous == NULL){
        
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
            size ++;
            return;
        }
        current = current->next;

    }
}
#endif	/* DOLINKEDLIST_H */

