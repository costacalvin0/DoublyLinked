//Calvin Costa
//Project 3 Part 2

#include "DoublyLinkedList.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>

using namespace std;

/*
@pre
@post
@
*/
//DONE
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(): headPtr(nullptr), SizeCount(0)
{
}

//NEED TO FIX!!!!
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType>& aBag): SizeCount(aBag.SizeCount)
{
    DoubleNode<ItemType>* origChainPtr = aBag.headPtr;
    
    if (origChainPtr == nullptr) {
        headPtr = nullptr;
    }
    else {
        headPtr = new DoubleNode<ItemType>();
        headPtr->setItem(origChainPtr->getItem());
        
        DoubleNode<ItemType>* newChainPtr = headPtr;
        origChainPtr = origChainPtr->getNext();
        
        while (origChainPtr != nullptr)
              {
                 // Get next item from original chain
                 ItemType nextItem = origChainPtr->getItem();
                      
                 // Create a new node containing the next item
                 DoubleNode<ItemType>* newNodePtr = new DoubleNode<ItemType>(nextItem);
                 
                 // Link new node to end of new chain
                 newChainPtr->setNext(newNodePtr);
                  
                 //
                 newNodePtr->setPrev(newChainPtr);
                 
                 // Advance pointer to new last node
                 newChainPtr = newChainPtr->getNext();

                 // Advance original-chain pointer
                 origChainPtr = origChainPtr->getNext();
              }  // end while
              
              newChainPtr->setNext(nullptr);              // Flag end of chain
        }  // end if
}  // end copy constructor

//DONE
template<class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
    clear();
}

//NEED TO FIX
template<class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType& item, const int& position)
{
    DoubleNode<ItemType>* insertPtr = headPtr;
    
    for (int i = 1; i <= position; i++) {
        if (headPtr == nullptr)
            DoubleNode<ItemType>* placeholderPtr = new DoubleNode<ItemType>();
        headPtr = headPtr->getNext();
        insertPtr = headPtr;
    }
    
    DoubleNode<ItemType>* insertNode = new DoubleNode<ItemType>(item);
    insertNode->setNext(insertPtr->getNext());
    insertNode->setPrev(insertPtr->getPrev());
    
    return true;
}

//DONE??
template<class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int& position)
{
    DoubleNode<ItemType>* removePtr = headPtr;
    for (int i = 1; i <= position; i++) {
        headPtr = headPtr->getNext();
        removePtr = headPtr;
    }
    DoubleNode<ItemType>* nextPtr = removePtr->getNext();
    DoubleNode<ItemType>* prevPtr = removePtr->getPrev();
    removePtr->setNext(nullptr);
    removePtr->setPrev(nullptr);
    prevPtr->setNext(nextPtr);
    nextPtr->setPrev(prevPtr);
    delete removePtr;
    return true;
 
}

//DONE??
template<class ItemType>
int DoublyLinkedList<ItemType>::getSize() const
{
    DoubleNode<ItemType>* countPtr = headPtr;
    int count = 0;
    if (countPtr == nullptr) {
        return 0;
    }
    else{
        while (countPtr!=nullptr) {
            countPtr=countPtr->getNext();
            count++;
        }
        return count;
    }
}

//NEED TO FIX!!!
template<class ItemType>
DoubleNode<ItemType> * DoublyLinkedList<ItemType>::getHeadPtr() const
{
    DoubleNode<ItemType>* copyHeadPtr = headPtr;
    return copyHeadPtr;
}

//DONE??
template<class ItemType>
DoubleNode<ItemType> * DoublyLinkedList<ItemType>::getAtPos(const int& pos) const
{
    DoubleNode<ItemType>* posPtr = headPtr;
    
    if (pos == 1) {
        return headPtr;
    }
    
    else{
        for (int i = 1; i <= pos; i++) {
            posPtr = posPtr->getNext();
        }
        return posPtr;
    }
}

//DONE
template<class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
    return SizeCount == 0;
}

//DONE??
template<class ItemType>
void DoublyLinkedList<ItemType>::clear()
{
    DoubleNode<ItemType>* nodeToDeletePtr = headPtr;
    while (headPtr != nullptr)
    {
       headPtr = headPtr->getNext();
       headPtr->setPrev(nullptr);

       // Return node to the system
       nodeToDeletePtr->setNext(nullptr);
       delete nodeToDeletePtr;
       
       nodeToDeletePtr = headPtr;
    }
    
     SizeCount = 0;
}

//DONE??
template<class ItemType>
void DoublyLinkedList<ItemType>::display() const
{
    DoubleNode<ItemType>* displayPtr = headPtr;
    while (displayPtr != nullptr) {
        std::cout << displayPtr->getItem();
        displayPtr = displayPtr->getNext();
        
        if (displayPtr == nullptr) {
            std::cout << '\n';
        }
        else{
            std::cout << ' ';
        }
    }
    
}

//DONE??
template<class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const
{
    DoubleNode<ItemType>* curPtr = headPtr;
    DoubleNode<ItemType>* endPtr;
    
    while (curPtr != nullptr) {
        curPtr = curPtr->getNext();
        endPtr = curPtr;
    }
    
    while (endPtr != nullptr) {
        std::cout << endPtr->getItem();
        endPtr = endPtr->getPrev();
        if (endPtr == nullptr) {
            std::cout << ' ';
        }
        else{
            std::cout <<'\n';
        }
    }
    
}

//NEED TO FIX!!!!
template<class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& a_list)
{
    //DoubleNode<ItemType>* list1Ptr = headPtr;
    //DoubleNode<ItemType>* list2Ptr = a_list->getHeadPtr();
    
    //SizeCount = SizeCount + a_list.SizeCount;
}
