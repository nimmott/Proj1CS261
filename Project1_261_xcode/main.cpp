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
    stringList.add("Rae");
    stringList.add("Harrison");
    stringList.add("Sam");
    stringList.add("Cat");
    stringList.add("Juan");
    stringList.add("John");
}

