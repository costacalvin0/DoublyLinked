//Calvin Costa
//Project 3

#include "DoubleNode.hpp"
#include <cstddef>
#include <cstdlib>

/*
@pre:N/A
@post:Empty Doubly Linked list
@return:N/A
DEFAULT CONSTRUCTOR
*/
template<class ItemType>
DoubleNode<ItemType>::DoubleNode(): next(nullptr), prev(nullptr)
{
    
}

/*
@pre:N/A
@post:Empty Doubly Linked list
@return:N/A
DEFAULT CONSTRUCTOR
*/
template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& anItem): item(anItem), next(nullptr), prev(nullptr)
{
    
}

/*
@pre:N/A
@post:Empty Doubly Linked list
@return:N/A
DEFAULT CONSTRUCTOR
*/
template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& anItem, DoubleNode<ItemType>* nextNodePtr, DoubleNode<ItemType>* prevNodePtr): item(anItem), next(nextNodePtr), prev(prevNodePtr)
{
    
}

/*
@pre:N/A
@post:Empty Doubly Linked list
@return:N/A
DEFAULT CONSTRUCTOR
*/
template<class ItemType>
void DoubleNode<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}

/*
@pre:N/A
@post:Empty Doubly Linked list
@return:N/A
DEFAULT CONSTRUCTOR
*/
template<class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType>* nextNodePtr)
{
    next = nextNodePtr;
}

/*
@pre:N/A
@post:Empty Doubly Linked list
@return:N/A
DEFAULT CONSTRUCTOR
*/
template<class ItemType>
void DoubleNode<ItemType>::setPrev(DoubleNode<ItemType>* prevNodePtr)
{
    prev = prevNodePtr;
}

/*
@pre:N/A
@post:Empty Doubly Linked list
@return:N/A
DEFAULT CONSTRUCTOR
*/
template<class ItemType>
ItemType DoubleNode<ItemType>::getItem() const
{
    return item;
}

/*
@pre:N/A
@post:Empty Doubly Linked list
@return:N/A
DEFAULT CONSTRUCTOR
*/
template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const
{
    return next;
}

/*
@pre:N/A
@post:Empty Doubly Linked list
@return:N/A
DEFAULT CONSTRUCTOR
*/
template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrev() const
{
    return prev;
}
