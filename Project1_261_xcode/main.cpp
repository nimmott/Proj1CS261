/*
 * File:   main.cpp
 * Author: Harrison Brace
 *
 * Created on September 10, 2015, 4:37 PM
 */

#include <cstdlib>
#include "DOLinkedList.h"
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>



using namespace std;

const string fileAddition = "proj1adds.data";
const string fileDeletion = "proj1deletes.data";
const int numInts = 900;

void createDataFile(string filename, int count);
void printForwards ( DOLinkedList<int> &intList);
void printBackwards ( DOLinkedList<int> &intList);

DOLinkedList<int> readfile(string file);


int main(int argc, char** argv) {
   
    
    createDataFile(fileAddition, numInts);
    createDataFile(fileDeletion, numInts);
    
    
    DOLinkedList<int> intList = readfile(fileAddition);
    printForwards(intList);
    
    
    /* Delete items from the intList by means of  another
     linked list (deletion list) by using an iterator to go through
     the deletion list
     */
    DOLinkedList<int> deletionList = readfile(fileDeletion);
    
        for ( Iterator<int> deletionIterator = deletionList.beginF(); deletionIterator !=deletionList.endF(); deletionIterator++){
            
            intList.deleteElement(*deletionIterator);
        
            }
    printBackwards(intList);
    
   
}

void createDataFile(string filename, int count){
    ofstream myfile (filename);
    
    int random_integer = 0;
    
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
        createDataFile(file, numInts);
    }
    
    while (myFile>>number){
        mylist.add(number);
    }
    
    return mylist;
}

void printForwards( DOLinkedList<int> &intList){
    if (intList.getSize() == 0){
        cout <<"Attempting to print an empty list"<<endl;
        return;
    }
    
    Iterator<int> myIterator = intList.beginF();
    cout <<"With Iterator. Printing a list forwards that contains " <<intList.getSize()<<" elements"<<endl;
    
    for ( ; myIterator != intList.endF(); myIterator++){
        
        cout << *myIterator<< endl;
        
    }
}

void printBackwards ( DOLinkedList<int> &intList){
    
    if (intList.getSize() == 0){
        cout <<"Attempting to print an empty list"<<endl;
        return;
    }
    Iterator<int> myIterator = intList.endB();
    cout <<"With Iterator. Printing a list backwards that contains " <<intList.getSize()<<" elements"<<endl;
    
    for ( ; myIterator != intList.beginB(); myIterator--){
        
        cout << *myIterator<< endl;
        
    }


}
