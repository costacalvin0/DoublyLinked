//Calvin Costa
//Project 3 Part 2

#include "DoublyLinkedList.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>

using namespace std;

/*
@pre:N/A
@post:Empty Doubly Linked list
@return:N/A
*/
//DONE
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(): headPtr(nullptr), SizeCount(0)
{
}

/*
 @pre: a doubly linked list passed through reference
 @post: a new doubly linked list which is a copy of the one passed through reference
 @return:N/A
 */
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

/*
 @pre: A doubly linked list
 @post: deletes doubly linked list
 @return: N/A
 */
//DONE
template<class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
    clear();
}

/*
 @pre:An item and position passed by reference
 @post:A new node is inserted at position with the item
 @return: returns true if successful
 */
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

/*
@pre:A position passed by reference
@post: A doublenode has been removed from the list
@return: returns true if successful
*/
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

/*
@pre: Any doubly linked list
@post:size is counted and updated
@return:int size of the list
*/
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

/*
@pre: Any Doubly Linked List
@post:HeadPtr is located and copied
@return:returns a pointer == headPtr
*/
//NEED TO FIX!!!
template<class ItemType>
DoubleNode<ItemType> * DoublyLinkedList<ItemType>::getHeadPtr() const
{
    DoubleNode<ItemType>* copyHeadPtr = headPtr;
    return copyHeadPtr;
}

/*
@pre: A position passed by reference
@post:a pointer is created pointing at the node in position
@return:a double node pointer is returned
*/
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

/*
@pre:Any Doubly Linked List
@post: checks if List is empty
@return: returns true if empty
*/
//DONE
template<class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
    return headPtr == nullptr;
}

/*
@pre: Any Doubly Linked List
@post:Empty Doubly Linked List
@return:N/A
*/
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

/*
@pre:A doubly linked list
@post:prints items of list in order
@return:N/A
*/
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

/*
@pre:A doubly linked list
@post:printed items of doubly linked list backwards
@return:N/A
*/
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

/*
@pre: two doubly linked list with one being passed by reference
@post:combines both doubly linked list into one
@return:A doubly linked list
*/
//NEED TO FIX!!!!
template<class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& a_list)
{
    //DoubleNode<ItemType>* list1Ptr = headPtr;
    //DoubleNode<ItemType>* list2Ptr = a_list->getHeadPtr();
    
    //SizeCount = SizeCount + a_list.SizeCount;
}
