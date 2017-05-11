//
//  DoublyLinkedList.hpp
//  ArrayProject
//
//  Created by Gallup, Tyler on 3/1/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "BiDirectionalNode.hpp"
template <class Type>
class DoublyLinkedList
{
private:
    BiDirectionalNode<Type> * front;
    BiDirectionalNode<Type> * end;
    int size;
    
public:
    DoublyLinkedList();
    virtual ~DoublyLinkedList() = 0;
    virtual void add(Type data) = 0;
    virtual Type remove(int index) = 0;
    
    int getSize() const;
    BiDirectionalNode<Type> * getFront() const;
    BiDirectionalNode<Type> * getEnd() const;
    
    void setFront(BiDirectionalNode<Type> * front);
    void setSize(int updated);
    void setEnd(BiDirectionalNode<Type> * end);
    
    
};
template <class Type>
DoublyLinkedList<Type> :: DoublyLinkedList()
{
    size = 0;
    front =nullptr;
    end = nullptr;
}

template <class Type>
DoublyLinkedList<Type> :: ~DoublyLinkedList()
{
   
}

template <class Type>
int DoublyLinkedList<Type> :: getSize() const
{
    return this->size;
}

template <class Type>
BiDirectionalNode<Type> * DoublyLinkedList<Type>  :: getFront() const
{
    return this->front;
}

template <class Type>
BiDirectionalNode<Type> * DoublyLinkedList<Type>  :: getEnd() const
{
    return this->end;
}

template <class Type>
void DoublyLinkedList<Type>  :: setEnd(BiDirectionalNode<Type>  * end)
{
    this->end = end;
}

template <class Type>
void DoublyLinkedList<Type>  :: setFront(BiDirectionalNode<Type>  * front)
{
    this->front = front;
}

template <class Type>
void DoublyLinkedList<Type>  :: setSize(int size)
{
    this->size = size;
}
#endif /* DoublyLinkedList_h */
