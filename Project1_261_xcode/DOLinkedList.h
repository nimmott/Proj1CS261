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


template<typename T>
class Iterator{
public:
    Iterator(Node <T>* p): current (p){}
    
    Iterator operator++(int){
        current = current->next;
        return *this;
    }
    
    Iterator operator-- (int){
        current=current->previous;
        return *this;
    }
    
    T& operator * (){
        return current->data;
    }
    
    bool operator == (const Iterator<T>& iterator){
        return current = iterator.current;
    }
    
    bool operator != (const Iterator<T> & iterator){
        return current != iterator.current;
    }
    
    
private:
    Node<T> * current;
};


template <typename T>
class DOLinkedList{
public:
    
    DOLinkedList (): head (NULL), tail (NULL), size (0){}
    virtual ~DOLinkedList();
    
    int getSize(){return size;}
    void add(T element);
    void deleteElement (T element);
    void printList();
    
    Iterator < T > beginF()
    {
        return Iterator < T > (head);
    };
    
    Iterator < T > beginB()
    {
        return Iterator < T > (tail);
    };

    
    Iterator < T > endF()
    {
        return Iterator < T > (tail->next);
    };
    
    Iterator < T > endB(){
        
        return Iterator<T> (tail);
        
    }
    
private:
    Node <T> * head;
    Node <T> * tail;
    int size;
    
};

template <typename T>
void DOLinkedList<T>::printList(){
    
    Node<T> * current = head;
    if (head == NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    cout << "Printing a list of "<< size <<" elements"<<endl;
    
    int checkListSize = 0;
    
    while (current!=NULL){
        checkListSize++;
        cout<< current->data<<endl;
        current = current->next;
    }
    cout << checkListSize<<" elements"<<endl;
    cout <<"-----------------End of list--------------"<<endl;
}



template<typename T>
void DOLinkedList<T>::deleteElement(T element){
    Node<T> * current = head;
    Node<T> * temp = NULL;
    
    if (head == NULL){
        cout <<"Deleting from empty list"<<endl;
        return;
    }

    while (current != NULL){
        
        if (head->next == NULL && head->data == element){ //deleting head when it's the only element
            delete head;
            head = tail = current = NULL;
            cout <<"List is now empty"<<endl;
            size--;
            return;
        }

    if (head->data == element && head->next != NULL){ //deleting first element it's not the only element
        head = head->next;
        head->previous = NULL;
        temp = current->next;
        delete current;
        current = temp;
        size --;
        continue;
    }
    
    if (current->data == element && current->next == NULL){ //deleting last element
            current->previous->next = NULL;                //we know last element != head
            tail = current->previous;
            delete current;
            current = NULL;
            size--;
            return;
        }
        
    if (current->data == element){ //deleting element in the middle of list
        current->previous->next = current->next;
        current->next->previous = current->previous;
        temp = current->next;
        delete current;
        current = temp;
        size --;
        continue;
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
    
    if (head != NULL && element <= head->data) //inserting item before head
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
       // cout << "entering while loop"<<endl;
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

