#ifndef DOUBLY_NODE_
#define DOUBLY_NODE_

#include <cstddef>
#include <cstdlib>
#include <iostream>

template<class ItemType>
class DoubleNode
{
private:
   ItemType        item; // A data item
   DoubleNode<ItemType>* next; // Pointer to next node
   DoubleNode<ItemType>* prev; // Pointer to the previous node
   
public:
   DoubleNode();// Default constructor
   DoubleNode(const ItemType& anItem); // Item constructor
   DoubleNode(const ItemType& anItem, DoubleNode<ItemType>* nextNodePtr, DoubleNode<ItemType>* prevNodePtr); //Full constructor
   void setItem(const ItemType& anItem); //sets item to anItem
   void setNext(DoubleNode<ItemType>* nextNodePtr); //sets next node to nextNodePtr
   void setPrev(DoubleNode<ItemType>* prevNodePtr); // sets prev node to prevNodePtr
   ItemType getItem() const; //returns item
   DoubleNode<ItemType>* getNext() const; //returns next pointer
   DoubleNode<ItemType>* getPrev() const; //returns prev pointer
}; // end Node

#include "DoubleNode.cpp"
#endif
