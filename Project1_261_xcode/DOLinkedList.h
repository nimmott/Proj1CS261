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
 //Default construcor. Sets current to p
    Iterator(Node <T>* p): current (p){}
 
//Allows forward iteration through list
    Iterator operator++(int){
        current = current->next;
        return *this;
    }
    
//Allows backwards iteration through list
    Iterator operator-- (int){
        current=current->previous;
        return *this;
    }
    
   
//returns the data (of type T) contained in the current node.
    T& operator * (){
        return current->data;
    }
    
 //compares iterators
    bool operator == (const Iterator<T>& iterator){
        return current == iterator.current;
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
    
    //Copy constructor. Default createsa a shallow copy.
    //This creates a "deep" copy of the linked list.
    //If list is empty, initializes object and then returns.
    DOLinkedList(const DOLinkedList& otherObject);
    
    //returns the number of elements contained in the linked list
    int getSize(){return size;}
    //Adds a new node to the list. Inserted in order according to the
    //value of element. Duplicate values result in multiple nodes
    //(i.e., multiple instances of the same value are allowed)
    void add(T element);
    
    //Removes all instances of the specified element from the linked list.
    void remove (T element);
    //testing functions, commented out as per instructions in class
    //void printList();
    //void printListBackwards();
    
    //Returns and iterator requried for forward iterations through the list.
    //Iterator "points to" head of list
    Iterator < T > beginF()
    {
        return Iterator < T > (head);
    };
    
    //Returns an iterator required for testing end of list conditions
    //when iterating backwards through a list
    
    Iterator < T > beginB()
    {
        return Iterator < T > (head->previous);
    };

    //Returns an iterator reqruied for testing for end of list when
    //iteration forwards through a list
    Iterator < T > endF()
    {
        return Iterator < T > (tail->next);
    };
    
    //returns and iterator requried for starting a backwards iteration
    //through a list. "Points to" last node in list.
    Iterator < T > endB(){
        
        return Iterator<T> (tail);
    }
    
private:
    Node <T> * head;
    Node <T> * tail;
    int size;
    
};


template<typename T>
void DOLinkedList<T>::remove(T element){
    Node<T> * current = head;
    Node<T> * temp = NULL;
    
    if (head == NULL){
        cout <<"Deleting from empty list"<<endl;
        return;
    }

    while (current != NULL){
        //deleting head when it's the only element
        //can return as there are no duplicates
        if (head->next == NULL && head->data == element){
            delete head;
            head = tail = current = NULL;
            cout <<"List is now empty"<<endl;
            size--;
            return;
        }
    //deleting first element it's not the only element. Because it's not the only element
    //loop must continue after this block to deal with possiblity of multiple values
    if (head->data == element && head->next != NULL){
        head = head->next;
        head->previous = NULL;
        temp = current->next;
        delete current;
        current = temp;
        size --;
        continue;
    }
    //deleting last element
    //we know last element != head
    //loop can terminate here because if we have hit the end, there
    //are no more duplicates
    if (current->data == element && current->next == NULL){
            current->previous->next = NULL;
            tail = current->previous;
            delete current;
            current = NULL;
            size--;
            return;
        }
    
    //deleting element in the middle of list
    //loop must continue after this block to deal with the possiblity
    // of multiple values
    if (current->data == element){
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
DOLinkedList<T>::DOLinkedList(const DOLinkedList& otherObject){
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
    
    if (otherObject.size == 0){
        return;
    }
    Node<T> *current = otherObject.head;
    
    while (current!= NULL){
        this->add(current->data);
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
    //inserting item in middle of list. 
    while (current != NULL){
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

//template <typename T>
//void DOLinkedList<T>::printListBackwards(){
//    Node<T> * current = tail;
//
//    if (tail == NULL){
//        cout <<"Attempting to print empty list"<<endl;
//    }
//    cout << "Printing a list backwards of "<< size <<" elements"<<endl;
//    while (current != NULL){
//        cout<< current->data<<endl;
//        current = current->previous;
//    }
//
//}

//template <typename T>
//void DOLinkedList<T>::printList(){
//
//    Node<T> * current = head;
//    if (head == NULL){
//        cout<<"Empty list"<<endl;
//        return;
//    }
//    cout << "Printing a list forwards of "<< size <<" elements"<<endl;
//
//    int checkListSize = 0;
//
//    while (current!=NULL){
//        checkListSize++;
//        cout<< current->data<<endl;
//        current = current->next;
//    }
//    cout << checkListSize<<" elements"<<endl;
//    cout <<"-----------------End of list--------------"<<endl;
//}
#endif	/* DOLINKEDLIST_H */

