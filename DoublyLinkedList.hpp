//Calvin Costa
//Project 3

#ifndef DOUBLY_LIST_
#define DOUBLY_LIST_

#include "DoubleNode.hpp"

template<class ItemType>
class DoublyLinkedList: public DoubleNode<ItemType>
{
private:
   DoubleNode<ItemType>* headPtr; // Pointer to first node
   int SizeCount;           // Current count of bag items

   
public:
   DoublyLinkedList(); // Default Constructor
   DoublyLinkedList(const DoublyLinkedList<ItemType>& aBag); // Copy constructor
   virtual ~DoublyLinkedList(); // Destructor
   bool insert(const ItemType& item, const int& position); //inserts a new node at the given position with the item
   bool remove(const int& position); //removes node at the given position
   int getSize() const; //returns size
   DoubleNode<ItemType> *getHeadPtr() const; // returns copy of the headPtr
   DoubleNode<ItemType> *getAtPos(const int& pos) const; //returns a pointer to the node located at pos
   bool isEmpty() const; //checks if is empty
   void clear(); //clears linked list
   void display() const; //prints list in order
   void displayBackwards() const; // prints list backwards
   DoublyLinkedList<ItemType> interleave(const DoublyLinkedList<ItemType>& a_list); //interleaves 2 lists
}; // end DoublyLinkedList

#include "DoublyLinkedList.cpp"
#endif
