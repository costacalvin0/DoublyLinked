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
DEFAULT CONSTRUCTOR
*/
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(): headPtr(nullptr), SizeCount(0)
{
}

/*
 @pre: a doubly linked list header
 @post: a new doubly linked list which is a copy of the one passed through header
 @return:N/A
 COPY CONSTRUCTOR
 */
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(DoubleNode<ItemType>* firstNode): headPtr(firstNode), SizeCount(1)
{
}


/*
 @pre: A doubly linked list
 @post: deletes doubly linked list
 @return: N/A
 DESTRUCTOR
 */
template<class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
    clear();
}

/*
 @pre:An item and position passed by reference
 @post:A new node is inserted at position with the item
 @return: returns true if successful
 INSERT FUNCTION
 */
template<class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType& item, const int& position)
{
    DoubleNode<ItemType>* nodePtr = new DoubleNode<ItemType>();
    nodePtr->setItem(item);
    nodePtr->setPrev(nullptr);
    nodePtr->setNext(nullptr);
    
    if (SizeCount == 0) {
        headPtr = nodePtr;
        SizeCount++;
        return true;
    }
    
    if (position == 1) {
        nodePtr->setNext(headPtr);
        headPtr->setPrev(nodePtr);
        headPtr = nodePtr;
        SizeCount++;
        return true;
    }
    
    DoubleNode<ItemType>* insertPtr = headPtr;
    
    for (int i = 1; i < position - 1; i++) {
        insertPtr = insertPtr->getNext();
    }
    nodePtr->setNext(insertPtr->getNext());
    nodePtr->setPrev(insertPtr);
    insertPtr->setNext(nodePtr);
    
    if (nodePtr->getNext() == nullptr) {
        SizeCount++;
        return true;
    }
    else{
        insertPtr = nodePtr->getNext();
        insertPtr->setPrev(nodePtr);
        SizeCount++;
        return true;
    }
}

/*
@pre:A position passed by reference
@post: A doublenode has been removed from the list at position
@return: returns true if successful
REMOVE FUNCTION
*/
template<class ItemType>
bool DoublyLinkedList<ItemType>:: remove(const int& position)
{
    if (position > SizeCount || position < 1) {
        return false;
    }

    DoubleNode<ItemType>* removePtr = headPtr->getNext();
    DoubleNode<ItemType>* currPtr = headPtr;
    int removePosition = 2;

    if (position == 1) {

        removePtr->setPrev(nullptr);
        headPtr->setNext(nullptr);
        headPtr->setPrev(nullptr);
        delete headPtr;
        headPtr = removePtr;
        SizeCount--;
    }
    
    else {
        //gets removePtr to position
        while (removePosition != position) {

            removePtr = removePtr->getNext();
            currPtr = currPtr->getNext();
            removePosition++;
        }
        //if position is the end node
        if (removePtr->getNext() == nullptr) {

            removePtr->setPrev(nullptr);
            delete removePtr;
            currPtr->setNext(nullptr);
            
            SizeCount--;
        }
        //if position is not the end node
        else if (removePtr->getNext() != nullptr) {

            DoubleNode<ItemType>* leadPtr = removePtr->getNext();
            removePtr->setNext(nullptr);
            removePtr->setPrev(nullptr);
            leadPtr->setPrev(currPtr);
            currPtr->setNext(leadPtr);
            delete removePtr;
            SizeCount--;
        }
    }
    
    //Outputs the rest of the list
    removePtr = headPtr;
    while (removePtr != nullptr) {
        std::cout<<removePtr->getItem();
        removePtr = removePtr->getNext();
        
        if (removePtr == nullptr) {
            cout<<" "<<endl;
        }
        
        else {
            cout<<' ';
        }
    }
    return true;
}

/*
@pre: Any doubly linked list
@post:size is counted and updated
@return:int size of the list
SIZE FUNCTION
*/
template<class ItemType>
int DoublyLinkedList<ItemType>::getSize() const
{
    return SizeCount;
    /*
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
    */
}

/*
@pre: Any Doubly Linked List
@post:HeadPtr is located and copied
@return:returns a pointer == headPtr
//NEED TO FIX!!!
HEAD POINTER FUNCTION
*/
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
POSITION POINTER FUNCTION
*/
template<class ItemType>
DoubleNode<ItemType>* DoublyLinkedList<ItemType>::getAtPos(const int& pos) const
{
    DoubleNode<ItemType>* posPtr = headPtr;
    int currentPosition = 1;

    while (currentPosition != pos) {
        posPtr = posPtr->getNext();
        currentPosition++;
    }
    return posPtr;
}

/*
@pre:Any Doubly Linked List
@post: checks if List is empty
@return: returns true if empty
EMPTY FUNCTION
 */
template<class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
    return headPtr == nullptr;
}

/*
@pre: Any Doubly Linked List
@post:Empty Doubly Linked List
@return:N/A
CLEAR FUNCTION
*/
template<class ItemType>
void DoublyLinkedList<ItemType>::clear()
{
    DoubleNode<ItemType>* nodeToDeletePtr = headPtr;
    while (headPtr != nullptr)
    {
       headPtr = headPtr->getNext();

       // Return node to the system
       nodeToDeletePtr->setNext(nullptr);
       nodeToDeletePtr->setPrev(nullptr);
       delete nodeToDeletePtr;
       
       nodeToDeletePtr = headPtr;
    }  // end while
    // headPtr is nullptr; nodeToDeletePtr is nullptr
    SizeCount = 0;
}
/*
 DoubleNode<ItemType>* nodeToDeletePtr = headPtr->getNext();
 if (nodeToDeletePtr == nullptr) {
     DoubleNode<ItemType>* curr = headPtr;
     curr->setNext(nullptr);
     curr->setPrev(nullptr);
     curr->setItem(NULL);
     delete curr;
     headPtr = nullptr;
 }
 while (nodeToDeletePtr != nullptr)
 {
    DoubleNode<ItemType>* curr = headPtr;
    curr->setPrev(nullptr);
    curr->setNext(nullptr);
    curr->setItem(NULL);
    delete curr;
    headPtr = nodeToDeletePtr;
    nodeToDeletePtr = nodeToDeletePtr->getNext();
 }
 */

/*
@pre:A doubly linked list
@post:prints items of list in order
@return:N/A
DISPLAY FUNCTION
*/
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
DISPLAY BACKWARDS FUNCTION
*/
template<class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const
{
    DoubleNode<ItemType>* curPtr = headPtr;
    DoubleNode<ItemType>* endPtr;
    
    while (curPtr != nullptr) {
        endPtr = curPtr;
        curPtr = curPtr->getNext();
        
    }
    
    while (endPtr != nullptr) {
        std::cout << endPtr->getItem();
        endPtr = endPtr->getPrev();
        if (endPtr == nullptr) {
            std::cout << '\n';
        }
        else{
            std::cout <<' ';
        }
    }
}

/*
@pre: two doubly linked list with one being passed by reference
@post:combines both doubly linked list into one
@return:A doubly linked list
INTERLEAVE FUNCTION
*/
//NEED TO FIX!!!!
template<class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& a_list)
{
    /*
    DoubleNode<ItemType>* list1Ptr = headPtr;
    DoubleNode<ItemType>* list2Ptr = a_list.headPtr;
    DoublyLinkedList<ItemType>* newList = new DoublyLinkedList<ItemType>();
    newList.headPtr = headPtr;
    if (SizeCount == a_list.SizeCount) {
        for (int i = 1; ; i++) {
            
        }
    }
    if (SizeCount <= a_list.SizeCount) {
    
    }
    if (SizeCount >= a_list.SizeCount) {
        
    }
    SizeCount = SizeCount + a_list.SizeCount;
    */
}







/* COPY CONSTRUCTOR ALTERNATIVE
   DoubleNode<ItemType>* origChainPtr = aBag.headPtr;
   DoubleNode<ItemType>* newChainPtr = nullptr;
   DoubleNode<ItemType>* currPtr = nullptr;
   
   
   
   if (origChainPtr == nullptr) {
       headPtr = nullptr;
   }
   else {
       newChainPtr = new DoubleNode<ItemType>();
       newChainPtr->setItem(origChainPtr->getItem());
       newChainPtr->setNext(nullptr);
       newChainPtr->setPrev(nullptr);
       headPtr = newChainPtr;
       currPtr = headPtr;
       
       while (origChainPtr != nullptr)
             {
                 origChainPtr = origChainPtr->getNext();
                 newChainPtr = newChainPtr->getNext();
                 if (origChainPtr!=nullptr) {
                     newChainPtr = new DoubleNode<ItemType>();
                     newChainPtr->setItem(origChainPtr->getItem());
                     newChainPtr->setNext(nullptr);
                     newChainPtr->setPrev(currPtr);
                     currPtr->setNext(newChainPtr);
                     currPtr = currPtr->getNext();
                 }
             }
       }
   SizeCount = aBag.SizeCount;
    */
