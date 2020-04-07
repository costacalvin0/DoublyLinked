//Calvin Costa
//Project 3

#include "DoubleNode.hpp"
#include <cstddef>
#include <cstdlib>

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(): next(nullptr), prev(nullptr)
{
    
}

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& anItem): item(anItem), next(nullptr), prev(nullptr)
{
    
}

template<class ItemType>
DoubleNode<ItemType>::DoubleNode(const ItemType& anItem, DoubleNode<ItemType>* nextNodePtr, DoubleNode<ItemType>* prevNodePtr): item(anItem), next(nextNodePtr), prev(prevNodePtr)
{
    
}

template<class ItemType>
void DoubleNode<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}

template<class ItemType>
void DoubleNode<ItemType>::setNext(DoubleNode<ItemType>* nextNodePtr)
{
    next = nextNodePtr;
}

template<class ItemType>
void DoubleNode<ItemType>::setPrev(DoubleNode<ItemType>* prevNodePtr)
{
    prev = prevNodePtr;
}

template<class ItemType>
ItemType DoubleNode<ItemType>::getItem() const
{
    return item;
}

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getNext() const
{
    return next;
}

template<class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>::getPrev() const
{
    return prev;
}
