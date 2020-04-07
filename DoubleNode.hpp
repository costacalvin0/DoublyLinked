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
   DoubleNode();
   DoubleNode(const ItemType& anItem);
   DoubleNode(const ItemType& anItem, DoubleNode<ItemType>* nextNodePtr, DoubleNode<ItemType>* prevNodePtr);
   void setItem(const ItemType& anItem);
   void setNext(DoubleNode<ItemType>* nextNodePtr);
   void setPrev(DoubleNode<ItemType>* prevNodePtr);
   ItemType getItem() const;
   DoubleNode<ItemType>* getNext() const;
   DoubleNode<ItemType>* getPrev() const;
}; // end Node

#include "DoubleNode.cpp"
#endif
