//============================================================================
// Name        : LinkedListProject1.cpp
// Author      : Naweeda
// Version     : Windows
// Copyright   : Your copyright notice
// Description : LinkedList With Different Functions
//============================================================================

#include <iostream>
#include "LinkedList.hpp"
using namespace std;


int main() {

	LinkedList list;
try {
cout << "First value is: " << list.first() << endl;
}//try
catch (const char* e) {
cout << e << endl;
}//catch
cout << "Inserting five values at the back of the list" << endl;
list.push_back(10);
list.push_back(20);
list.push_back(30);
list.push_back(40);
list.push_back(50);
list.print_list();

cout << endl << "Insertiing five values at the front of the list" << endl;
list.push_front(5);
list.push_front(4);
list.push_front(3);
list.push_front(2);
list.push_front(1);
list.print_list();

cout << endl << "Getting the first value in the list" << endl;
try {
cout << "First value is: " << list.first() << endl;
}//try
catch (const char* e) {
cout << e << endl;
}//catch

cout << endl << "Getting the last value in the list" << endl;
try {
cout << "Last value is: " << list.last() << endl;
}//try
catch (const char* e) {
cout << e << endl;
}//catch


cout << endl << "Testing the getAt function" << endl;
cout << "Item at position 0 is: " << list.getAt(0) << endl;
cout << "Item at position 5 is: " << list.getAt(5) << endl;
cout << "Item at position 9 is: " << list.getAt(9) << endl;
try {
cout << "Item at position 22 is: " << list.getAt(22); }//try
catch (const char*e) {
cout << e << endl;
}//catch

cout << endl << "Inserting, sorted, six values" << endl;
list.insertSorted(120);
list.insertSorted(43);
list.insertSorted(-10);
list.insertSorted(-30);
list.insertSorted(120);
list.insertSorted(130);
list.print_list();


cout << endl << "Deleting the node at position 0" << endl;
list.deleteAt(0);
list.print_list();
cout << endl << "Trying to deleteAt a node past the end of the list" << endl;
try {
list.deleteAt(list.size());
}//tru
catch (const char* e) {
cout << e << endl;
}//catch
cout << endl << "Trying to deleteAt the node at end of the list" << endl;
list.deleteAt(list.size()-1);
list.print_list();
cout << endl << "Trying to deleteAt a node in the middle of the list" << endl;
list.deleteAt((list.size()-1)/2);
list.print_list();


cout << endl << "Testing insertAt function before position 0 with value of 5000" << endl;
list.insertAt(0, 5000);
list.print_list();
cout << endl << "Testing insertAt function before the last position with value of 5000" << endl;
list.insertAt(list.size()-1, 5000);
list.print_list();


cout << endl << "Testing a for loop with overided [] operator" << endl;
for (int i=0; i<list.size(); i++) {
cout << list[i] << endl;
}//for

cout << endl << "Testing pop_front in a for loop to clear out the list" << endl;
int theSize = list.size();
for (int i=0; i<theSize; i++) {
cout << "Deleting: " << list.first() << endl;
list.pop_front();
list.print_list();
}//for

cout << endl << "Program ending, have a nice day" << endl;
return 0;
}
