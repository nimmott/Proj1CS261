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
const int numInts = 100;

void createDataFile(string filename, int count);
void printForwards ();
void printBackwards ();

DOLinkedList<int> readfile(string file);





/*
 *
 */
int main(int argc, char** argv) {
   
    
    createDataFile(fileAddition, numInts);
    createDataFile(fileDeletion, numInts);
    DOLinkedList<int> intList = readfile(fileAddition);
    
    DOLinkedList<int> deletionList = readfile(fileDeletion);
    Iterator<int> deletionIterator = deletionList.beginF();
    
   // intList.printList();
    for ( ; deletionIterator !=deletionList.endF(); deletionIterator++){
        
        intList.deleteElement(*deletionIterator);
        
    }
  //  intList.printList();
    
    
    printForwards();
    printBackwards();
   
    
    
    DOLinkedList<string> stringList;

    stringList.add("Rey");
    stringList.deleteElement("Rey");
 //   stringList.printList();
    stringList.add("Rey");
    stringList.add("Rey");
    stringList.add("Rey");
    stringList.add("Harrison");
    stringList.add("Sam");
    stringList.add("Cat");
    stringList.add("Cat");
    stringList.add("Juan");
    stringList.add("Juan");
    stringList.add("John");
//    stringList.printList();
    stringList.deleteElement("Sam");
    stringList.deleteElement("Cat");
    stringList.add("Homer");
    stringList.deleteElement("Krusty");
    stringList.deleteElement("Harrison");
    stringList.add("Krusty");
 //   stringList.printList();
    stringList.deleteElement("Juan");
    stringList.deleteElement("Sam");
    stringList.deleteElement("Rae");
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

void printForwards(){
    DOLinkedList<int> intList = readfile(fileAddition);
    Iterator<int> myIterator = intList.beginF();
    
    cout <<"Printing a list forwards that contains " <<intList.getSize()<<" elements"<<endl;
    
    for ( ; myIterator != intList.endF(); myIterator++){
        
        cout << *myIterator<< endl;
        
    }
}

void printBackwards (){
    
    DOLinkedList<int> intList = readfile(fileAddition);
    Iterator<int> myIterator = intList.endB();
    cout <<"Printing a list backwards that contains " <<intList.getSize()<<" elements"<<endl;
    
    for ( ; myIterator != intList.beginF(); myIterator--){
        
        cout << *myIterator<< endl;
        
    }

    
}
