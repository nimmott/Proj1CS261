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



using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    
    //DOLinkedList <string> * mylist = new DOLinkedList<string>;
    //mylist->add ("Rae");
    //  DOLinkedList <int> myList2;
    DOLinkedList<string> stringList;
    //  DOLinkedList<int> stringList;return 0;
    stringList.add("Rey");
    stringList.deleteElement("Rey");
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
    stringList.deleteElement("Sam");
    stringList.deleteElement("Cat");
    stringList.add("Homer");
    stringList.deleteElement("Krusty");
    stringList.deleteElement("Harrison");
    stringList.add("Krusty");
    stringList.deleteElement("Juan");
    stringList.deleteElement("Sam");
    stringList.deleteElement("Rae");
}

