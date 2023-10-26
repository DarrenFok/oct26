/* 
 * D105+D106
 * DataCollection.h
 *
 * Description: Implementation of a linked list-based Data Collection ADT class - SHSL list.
 * Class Invariant: There are no class invariant!
 *
 * Author: AL
 * Date: Oct. 2023
 */
 
#ifndef DATA_COLLECTION_H
#define DATA_COLLECTION_H

using std::ostream;

class DataCollection {

   private:

      // Description:  Nodes for a singly-headed singly-linked list (SHSL list)
      class Node {
         public:
            int data;  // Note: "data" can be assigned any integral values (negative, positive or zero).              
            Node * next = nullptr;
         
            Node(int theData): data(theData) {}
      };
     
      
      // Data member: 
      Node * head = nullptr;  // head is the pointer to the first node


   public:

      // Description: Default constructor. Constructs a DataCollection object.
      DataCollection();

      // Description: Copy constructor creates a new DataCollection object as a copy of an existing DataCollection object.
      DataCollection(const DataCollection & DC);

      // Description: Destructs a DataCollection object, releasing all heap-allocated memory.
      ~DataCollection();
      
      // Description: Appends an element (newElement) to the DataCollection.
      // Exception Handling: Throws UnableToInsertException.
      void append(int newElement);

      // Description: Prepends an element (newElement) to the DataCollection.
      // Exception Handling: Throws UnableToInsertException.
      void prepend(int newElement);
            
      // Description: Computes the sum of all elements (i.e., their value) in the DataCollection (before any removals have taken place). 
	  //              If this sum is even, this method removes and returns the last element, i.e., the element at position 
	  //              "total number of elements" in the DataCollection. 
	  //              Otherwise, this method removes the last element, i.e., the element at position 
	  //              "total number of elements" in the DataCollection and returns the sum itself.
	  //              The position of the elements in DataCollection ranges from [1 .. "total number of elements"]. 
      // Exception Handling: Throws EmptyDataCollectionException.
      int removeLastorSum();
  
      // Bonus Method: Will be marked only if you have implemented and submitted the above two methods.
      // Description: Finds and returns the last element in the DataCollection that has an even value (e.g., 2,4,6...).
      //              If there are no elements with an even value in the DataCollection, "1" is returned.
      // Exception Handling: Throws EmptyDataCollectionException.
      int lastEven();
      
      // Description: Prints the content of this DataCollection "thisDC"
      //              using this format: {element1, element2, ..., elementn}.
      friend ostream & operator<<(ostream & os, const DataCollection & thisDC); 
      
};
#endif
