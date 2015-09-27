/*
 * File:   main.cpp
 * Author: Harrison Brace
 * CS261 Assignment 1
 * Created on September 10, 2015, 4:37 PM
 
 Certification of Authenticity: 
 I certify that this solution to the assignment is entirely my own work, but I received some assistance from professor James 
 Etheredge. The assistance consisted of tracking down a problem with the linker that resulted from having declared a
 destructor but not having implemented it.
 */

#include <cstdlib>
#include "DOLinkedList.h"
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>



using namespace std;
/*
Constants for project. File name of data files.
*/
const string fileAddition = "proj1adds.data";
const string fileDeletion = "proj1deletes.data";
const int numInts = 100;




/*Print a linked list in order (starting a first node, ending at last node).
 Function uses an Iterator object and obtains the value of each element in the
 list by using the Iterator's user-defined dereferencing operator.
 Parameters:
    intList: A linked list specialized with type int. If list is empty, function outputs
    a comment that the list is empty and returns.
*/
void printForwards ( DOLinkedList<int> intList);

/*Print a linked list in reverse order (starting with the last node, ending with the first node).
 Function uses an Iterator object and obtains the value of each element in the
 list by using the Iterator's user-defined dereferencing operator.
 Parameters:
 intList: A linked list specialized with type int. If list is empty, function outputs
 a comment that the list is empty and returns.
 */
void printBackwards ( DOLinkedList<int> intList);

/*Reads the specified data file containing a list of integers (much be in correct format).
 Returns a ordered, double-linked DOLinkedList <int> object. Used for reading both the 
 addition and deletion file
 Parameters:
    file: The name of the file to be read. 
 Return Value:
    A DOLinkedList object containing the values read from the file specified by the file
    parameter.
*/
DOLinkedList<int> readfile(string file);


/* The create data file function is for testing and, as per instructions in class,
 is commented out but left in the file.
 Creates a list of random integers (number specified by count parameter).
 Parameters:
 filename: the name of the file created by this function
 count: the number of random integers to be contained in the file
 */
void createDataFile(string filename, int count);


int main(int argc, char** argv) {
//createDataFile(fileAddition, numInts);
//createDataFile(fileDeletion, numInts);
    
    
    DOLinkedList<int> intList = readfile(fileAddition);
    
    cout <<intList.getSize()<<" elements have been loaded from "<<fileAddition<<" into the linked list."<<endl;
    printForwards(intList);
    
    
    /* Read the proj1deletes.data file and create a linked list with the elements from that file,
     using the readfile() method. In the for loop, create an Iterator and iterates through the
     deletion linked list, calling DOLinkedList::remove() with each element in the deletion list.
     */
    DOLinkedList<int> deletionList = readfile(fileDeletion);
    
  //  int checkLoop = 0;
    
        for (Iterator<int> deletionIterator = deletionList.beginF(); deletionIterator !=deletionList.endF(); deletionIterator++){
            
            intList.remove(*deletionIterator);
   //         checkLoop++;
        
            }
    //cout <<"The deletion loop has iterated "<< checkLoop<<" times."<<endl;
    //print the list backwards now, after the items from the proj1deletes.data file have been removed
    
    cout <<"The linked list now contains "<<intList.getSize() <<" elements after reading deletion file"<<endl;
   
    printForwards(intList);
    printBackwards(intList);
    
}

void createDataFile(string filename, int count){
    ofstream myfile (filename);
    
    int random_integer = 0;
    // srand (time(NULL));
    
    for(int index=0; index<count; index++)
    {
        random_integer = (rand()%1000)+1;
        myfile << random_integer << "\n";
    }
}

DOLinkedList<int> readfile(string file){
    DOLinkedList<int> mylist;
    ifstream myFile (file);
    int number = 0;
    
    if (!myFile){
        cout <<"Must create file " <<file<<" first"<<endl;
        exit (EXIT_FAILURE);
    }
    
    while (myFile>>number){
        mylist.add(number);
    }
    
    return mylist;
}

void printForwards( DOLinkedList<int> intList){
    if (intList.getSize() == 0){
        cout <<"Attempting to print an empty list"<<endl;
        return;
    }
    
    Iterator<int> myIterator = intList.beginF();
    cout <<"Printing a list forwards that contains " <<intList.getSize()<<" elements"<<endl;
    
    for ( ; myIterator != intList.endF(); myIterator++){
        
        cout << *myIterator<< endl;
        
    }
    
     cout <<"-----------------------------------"<<endl;
}

void printBackwards ( DOLinkedList<int> intList){
    
    if (intList.getSize() == 0){
        cout <<"Attempting to print an empty list"<<endl;
        return;
    }
    Iterator<int> myIterator = intList.beginB();
    cout <<"Printing a list backwards that contains " <<intList.getSize()<<" elements"<<endl;
    
    for ( ; myIterator != intList.endB(); myIterator--){
        
        cout << *myIterator<< endl;
        
    }
    
    cout <<"-----------------------------------"<<endl;


}
