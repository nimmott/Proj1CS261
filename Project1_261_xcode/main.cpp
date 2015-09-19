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
const int numInts = 10;

void createDataFile(string filename, int count);
void printForwards ( DOLinkedList<int> intList);
void printBackwards ( DOLinkedList<int> intList);

DOLinkedList<int> readfile(string file);


int main(int argc, char** argv) {
   
    
    createDataFile(fileAddition, numInts);
    createDataFile(fileDeletion, numInts);
    DOLinkedList<int> intList = readfile(fileAddition);
  //  printBackwards(intList);
 //   intList = readfile(fileAddition);
    printBackwards(intList);

    DOLinkedList<int> deletionList = readfile(fileDeletion);
    Iterator<int> deletionIterator = deletionList.beginF();
    
    intList.printList();
 for ( ; deletionIterator !=deletionList.endF(); deletionIterator++){
        
    intList.deleteElement(*deletionIterator);
        
    }
   intList.printList();
 //    printBackwards(intList);
    
   // printForwards(intList);
   // printBackwards(intList);
   
    
    
   
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

void printForwards( DOLinkedList<int> intList){
    // DOLinkedList<int> intList = readfile(fileAddition);
    
    if (intList.getSize() == 0){
        cout <<"Attempting to print an empty list"<<endl;
        return;
    }
    
    Iterator<int> myIterator = intList.beginF();
    
    cout <<"Printing a list forwards that contains " <<intList.getSize()<<" elements"<<endl;
    
    for ( ; myIterator != intList.endF(); myIterator++){
        
        cout << *myIterator<< endl;
        
    }
}

void printBackwards ( DOLinkedList<int> intList){
    
   // DOLinkedList<int> intList = readfile(fileAddition);
    if (intList.getSize() == 0){
        cout <<"Attempting to print an empty list"<<endl;
        return;
    }
    Iterator<int> myIterator = intList.endB();
    cout <<"Printing a list backwards that contains " <<intList.getSize()<<" elements"<<endl;
    
    for ( ; myIterator != intList.beginB(); myIterator--){
        
        cout << *myIterator<< endl;
        
    }


}
