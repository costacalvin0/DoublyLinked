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
 @pre: a doubly linked list passed through reference
 @post: a new doubly linked list which is a copy of the one passed through reference
 @return:N/A
 COPY CONSTRUCTOR
 //NEED TO FIX!!!!
 */
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(DoubleNode<ItemType>* firstNode): headPtr(firstNode), SizeCount(1)
{
    /*
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
    DoubleNode<ItemType>* insertPtr = nullptr;
    for (int i = 1; i < position - 1; i++) {
        insertPtr = headPtr;
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
@post: A doublenode has been removed from the list
@return: returns true if successful
REMOVE FUNCTION
*/
//DONE??
template<class ItemType>
bool DoublyLinkedList<ItemType>:: remove(const int& position)
{
    if (position > SizeCount || position < 1) {
        return false;
    }

    DoubleNode<ItemType>* currentPtr = headPtr->getNext();
    DoubleNode<ItemType>* trailingPtr = headPtr;
    int currentPosition = 2;

    if (position == 1) {

        currentPtr->setPrev(nullptr);
        delete headPtr;
        headPtr = currentPtr;
        SizeCount--;

    } else {
        while (currentPosition != position) {

            currentPtr = currentPtr->getNext();
            trailingPtr = trailingPtr->getNext();
            currentPosition++;
        }
        if (currentPtr->getNext() == nullptr) {

            currentPtr->setPrev(nullptr);
            trailingPtr->setNext(nullptr);
            delete currentPtr;
            SizeCount--;

        } else if (currentPtr->getNext() != nullptr) {

            DoubleNode<ItemType>* leadingPtr = currentPtr->getNext();
            currentPtr->setNext(nullptr);
            currentPtr->setPrev(nullptr);
            leadingPtr->setPrev(trailingPtr);
            trailingPtr->setNext(leadingPtr);
            delete currentPtr;
            SizeCount--;
            
        }
    }
    
    currentPtr = headPtr;
    while (currentPtr != nullptr) {
        cout<<currentPtr->getItem();
        currentPtr = currentPtr->getNext();
        if (currentPtr == nullptr) {
            cout<<" "<<endl;
        } else {
            cout<<' ';
        }
    }

    return true;
}
/*
template<class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int& position)
{
    if (position > SizeCount) {
        return true;
    }
    else{
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
        SizeCount--;
        return true;
    }
}
*/
/*
@pre: Any doubly linked list
@post:size is counted and updated
@return:int size of the list
*/
//DONE??
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
    while (nodeToDeletePtr != nullptr)
    {
       DoubleNode<ItemType>* curr = nodeToDeletePtr;
       nodeToDeletePtr = nodeToDeletePtr->getNext();
       curr->setPrev(nullptr);
       curr->setNext(nullptr);
       delete curr;
    }
     SizeCount = 0;
}

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
INTERLEAVE FUNCTION
*/
//NEED TO FIX!!!!
template<class ItemType>
DoublyLinkedList<ItemType> DoublyLinkedList<ItemType>::interleave(const DoublyLinkedList<ItemType>& a_list)
{
    //DoubleNode<ItemType>* list1Ptr = headPtr;
    //DoubleNode<ItemType>* list2Ptr = a_list.headPtr;
    
    //SizeCount = SizeCount + a_list.SizeCount;
}
