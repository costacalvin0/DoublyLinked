//
//  Main.cpp
//  
//
//  Created by Calvin Costa on 4/6/20.
//
#include "DoublyLinkedList.hpp"
#include "DoubleNode.hpp"
#include <stdio.h>
int main(){
    
    DoublyLinkedList<ItemType> L1;
    int insertItem = 2;
    int* reference = &insertItem;
    
    int positionInt = 1;
    int* positionR = &positionInt;
    
    L1.insert(reference, positionR);
    L1.remove(positionR);
    std::cout << L1.isEmpty();
    
    
    
    
    
    return 0;
}
