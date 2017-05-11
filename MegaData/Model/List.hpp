//
//  List.hpp
//  ArrayProject
//
//  Created by Gallup, Tyler on 2/21/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef List_h
#define List_h

#include "assert.h"
#include "Node.hpp"

template <class Type>
class List
{
private:
    int size;
    Node<Type> * end;
    Node<Type> * front;
    
public:
    List();
    List(const List<Type> & source);
    //Deconstructor
    ~List<Type>();
  
    //Helper Methods
    void addAtIndex(int index, Type value);
    Type setAtIndex(int index, Type data);
    Type getFromIndex(int index);
    void addFront(Type value);
    void addEnd(Type data);
    bool contains(Type findMe);
    Node<Type> * getFront() const;
    Node<Type> * getEnd() const;
    Node<Type> * getFrontIndex() const;
    Type remove(int index);
    int getSize() const;
    Type getFrontIndex();
};

template <class Type>
List<Type> :: List()
{
    this->size = 0;
    this-> front = nullptr;
    this-> end = nullptr;
}

template <class Type>
void List<Type> :: addFront(Type value)
{
    if(size == 0)
    {
        Node<Type> * first = new Node<Type>(value);
        this->front = first;
        this->end = first;
    }
    else
    {
        Node<Type> * newFirst = new Node<Type>();
        newFirst -> setNodeData(value);
        newFirst -> setNodePointer(front);
        this->front = newFirst;
        
    }
    size++;
}

template <class Type>
List<Type> :: ~List<Type>() {
    Node<Type> * destruction = front;
    while(front != nullptr){
        front = front->getNodePointer();
        delete destruction;
        destruction = front;
    }
}

template <class Type>
int List<Type> :: getSize() const {
    return this->size;
}

template <class Type>
Node<Type> * List<Type> :: getFront() const {
    return this->front;
}

template <class Type>
Node<Type> * List<Type> :: getEnd() const {
    return this->end;
}


template <class Type>
void List<Type> :: addEnd(Type data)
{
    Node<Type> * added = new Node<Type>(data);
    if(size == 0)
    {
        this->front = added;
        this->end = added;
        
    }
    else
    {
        end->setNodePointer(added);
        this->end = added;
    }
    size++;
}

template <class Type>
void List<Type> :: addAtIndex(int index, Type value)
{
    assert(index >= 0 && index <= size);
    if(index == 0)
    {
        addFront(value);
    }
    else if(index == size)
    {
        addEnd(value);
    }
    else
    {
        Node<Type> * insertNode = new Node<Type>(value);
        Node<Type> * current = front;
        Node<Type> * previous = nullptr;
        
        for(int position = 0; position < index; position++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        previous-> setNodePointer(insertNode);
        insertNode-> setNodePointer(current);
        
        size++;
    }
}

template <class Type>
Type List<Type> :: setAtIndex(int index, Type data){
    assert(index >= 0 && index < size);
    Type removeData;
    
    Node<Type> * current = front;
    
    for(int spot = 0; spot < index; spot++){
        current = current->getNodePointer();
    }
    
    removeData = current->getNodeData();
    current->setNodeData(data);
    
    return removeData;
}


template <class Type>
Type List<Type> :: remove(int index)
{
    assert(index >= 0 && index <= size);
    Type removed;
    
    Node<Type> * current = front;
    Node<Type> * previous = nullptr;
    Node<Type> * toBeRemoved = nullptr;
    
    
    if(index == 0)
    {
        toBeRemoved = front;
        this->front = front->getNodePointer();
    }
    else if(index == size - 1)
    {
        for(int spot = 0; spot < index; spot++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        
        toBeRemoved = current;
        previous->setNodePointer(nullptr);
        this->end = previous;
        
    }
    else
    {
        for(int spot = 0; spot < index; spot++)
        {
            previous = current;
            current = current->getNodePointer();
        }
        
        toBeRemoved = current;
        current  = toBeRemoved->getNodePointer();
        previous-> setNodePointer(current);
    }
    removed = toBeRemoved->getNodeData();
    delete toBeRemoved;
    
    
    size--;
    return removed;
    
}

template <class Type>
Type List<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index<size);
    Type information;
    Node<Type> * current = front;
    for(int position = 0; position< index; position++)
    {
        current = current->getNodePointer();
    }
    information = current -> getNodeData();
    
    return information;
}


template <class Type>
bool List<Type> :: contains(Type findMe)
{
   
    bool isInList = false;
    
    Node<Type> * current = front;
    for(int index = 0; index < size; index++)
    {
        if(current->getNodeData() == findMe)
        {
            isInList = true;
            return isInList;
        }
    }
    
    
    return isInList;
}





#endif /* List_h */
