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
void printForwards (Iterator<int> front);
void printBackwards (Iterator<int> end);

DOLinkedList<int> readfile(string file);





/*
 *
 */
int main(int argc, char** argv) {
    
    //DOLinkedList <string> * mylist = new DOLinkedList<string>;
    //mylist->add ("Rae");
    //  DOLinkedList <int> myList2;
    DOLinkedList<string> stringList;
    //  DOLinkedList<int> stringList;return 0;
    
    createDataFile(fileAddition, numInts);
    DOLinkedList<int> intList = readfile(fileAddition);
    
    intList.printList();
    
    Iterator<int> myIterator = intList.begin();
    
    for ( ; myIterator != intList.end(); myIterator++){
        
        cout << (*myIterator)<< endl;
        
    }
    
    stringList.add("Rey");
    stringList.deleteElement("Rey");
    stringList.printList();
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
    stringList.printList();
    stringList.deleteElement("Sam");
    stringList.deleteElement("Cat");
    stringList.add("Homer");
    stringList.deleteElement("Krusty");
    stringList.deleteElement("Harrison");
    stringList.add("Krusty");
    stringList.printList();
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
    }
    
    while (myFile>>number){
        mylist.add(number);
    }
    
    return mylist;
}
