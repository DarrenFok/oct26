/*
 * D105+D106
 * DataCollection.cpp
 *
 * Description: Implementation of a linked list-based Data Collection ADT class - SHSL list
 * Class Invariant: There are no class invariant!
 *
 * Author: AL
 * Date: Oct. 2022
 */
 
#include <iostream>
#include <cmath>   // ceil()
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
#include "DataCollection.h"

using std::cout;
using std::cin;
using std::endl;


// Description: Default constructor. Constructs a DataCollection object.
DataCollection::DataCollection(){
   // cout << "DataCollection Default constructor called!" << endl; // For testing purposes!
}

// Description: Copy constructor creates a new DataCollection object as a copy of an existing DataCollection object.
DataCollection::DataCollection(const DataCollection & DC){
   // cout << "DataCollection Copy constructor called!" << endl; // For testing purposes!

   head = nullptr;
   if (DC.head != nullptr){
      Node *current = DC.head;
      while (current != nullptr){
         this->append(current->data); 
         current = current->next; 
      }
   }
}

// Description: Destructs a DataCollection object, releasing all heap-allocated memory.
DataCollection::~DataCollection(){
   // cout << "DataCollection Destructor called!" << endl; // For testing purposes!

   Node * temp = nullptr;
   for (Node * toBeDeleted = head; toBeDeleted != nullptr;) {
      temp = toBeDeleted->next;
      delete toBeDeleted;
      toBeDeleted = temp;
   }
   head = nullptr;
}

// Description: Appends an element (newElement) to the DataCollection.
// Exception Handling: Throws UnableToInsertException.
void DataCollection::append(int newElement){
   // cout << "DataCollection append called!" << endl; // For testing purposes!
   
   Node * newNode = new Node(newElement); 
   if (newNode == nullptr)  
      throw UnableToInsertException("In DataCollection::append(): new failed, newNode cannot be allocated heap memory."); 

   if (head == nullptr){
      head = newNode;
   }else{
      Node * current = head;
      while (current->next != nullptr){
         current = current->next;
      }
      current->next = newNode;
   }
   return;
}

// Description: Prepends an element (newElement) to the DataCollection.
// Exception Handling: Throws UnableToInsertException.
void DataCollection::prepend(int newElement){
   // cout << "DataCollection prepend called!" << endl; // For testing purposes!

   Node * newNode = new Node(newElement); 
   if ( newNode == nullptr )  
      throw UnableToInsertException("in DataCollection::prepend(): new failed, newNode cannot be allocated heap memory."); 
  
   if (head != nullptr) newNode->next = head;
   head = newNode;

   return;
}
 
  
// Description: Computes the sum of all elements (i.e., their value) in the DataCollection (before any removals have taken place). 
//              If this sum is even, this method removes and returns the last element, i.e., the element at position 
//              "total number of elements" in the DataCollection. 
//              Otherwise, this method removes the last element, i.e., the element at position 
//              "total number of elements" in the DataCollection and returns the sum itself.
//              The position of the elements in DataCollection ranges from [1 .. "total number of elements"]. 
// Exception Handling: Throws EmptyDataCollectionException.
int DataCollection::removeLastorSum() {

   // Put your code here!
   if(head == nullptr){ //if head is nullptr, then datacollection empty
      throw EmptyDataCollectionException("in DataCollection::removeLastorSum(): DataCollection is empty, removal cannot be performed");
   }
   else{
      Node *current = head;
      int sum = 0;
      while(current != nullptr){ 
         sum += current->data; //adds data to sum as long as current is not nullptr
         current = current->next;
      }

      if(sum % 2 == 0){ //if even, remove and return the last element
      //traverse and keep track of previous
         Node *end = head;
         Node *prev = nullptr;

         while(end->next != nullptr){
            prev = end; //keeps track of previous element
            end = end->next;
         }
         int evenReturn = end->data; //retrieve last element's data value to return
         prev->next = nullptr;
         delete end;
         return evenReturn;
      }
      else{ //if odd, returns sum, and removes last element
         Node *end = head;
         Node *prev = nullptr;

         while(end->next != nullptr){
            prev = end;
            end = end->next;
         }
         prev->next = nullptr; //set last element to nullptr
         delete end; //delete last element
         return sum;
      }
   }
   
   return -1; //if reaches here, then unable to do either action 1 (even, remove last element
   // and return its value) or action 2 (odd, remove last element, return sum)
}      
	  
// Bonus Method: Will be marked only if you have implemented and submitted the above two methods.
// Description: Finds and returns the last element in the DataCollection that has an even value (e.g., 2,4,6...).
//              If there are no elements with an even value in the DataCollection, "1" is returned.
// Exception Handling: Throws EmptyDataCollectionException.
int DataCollection::lastEven() {
	
   // Put your code here
   int lastEven;
   bool isAdded;
   if(head == nullptr){
      throw EmptyDataCollectionException("in DataCollection::lastEven(): DataCollection is empty, the last even cannot be found");
   }

   else{
      Node *current = head;
      while(current != nullptr){
         if(current->data % 2 == 0){
            lastEven = current->data;
            isAdded = true; //if even number is added, then true, if not then lastEven will be 0
         }
         current = current->next;
      }
   }
   if(isAdded == true){
      return lastEven;
   }
   
   return 1; // You can change this statement!
}
 
// Description: Prints the content of this DataCollection "thisDC"
//              using this format: {element1, element2, ..., elementn}.
ostream & operator<<(ostream & os, const DataCollection & thisDC) {

   DataCollection::Node *current = thisDC.head;
   cout << "{"; 
   
   // Traverse the DataCollection
   while (current != nullptr){
      cout << current -> data;   
      current = current -> next; 
      if (current != nullptr){
         cout << ",";
      }
   }
   cout << "}"; // Don't print a newline - it might not be needed.

   return os;
} 