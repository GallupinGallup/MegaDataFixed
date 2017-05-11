//
//  Stack.hpp
//  ArrayProject
//
//  Created by Gallup, Tyler on 3/3/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

template <class Type>
class Stack : public DoublyLinkedList<Type>
{
private:
    
    
public:
    Stack();
    ~Stack();
    void add(Type value);
    Type remove(int index);
    Type pop();
    Type peek();
    void push(Type data);
    
};

template <class Type>
Stack<Type> :: Stack() : DoublyLinkedList<Type>()
{
    
}

template <class Type>
Stack<Type>:: ~Stack()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove= this->getFront();
        
        
        
    }
}

template <class Type>
void Stack<Type> :: push(Type addedThing)
{
    BiDirectionalNode<Type> * addToStack = new BiDirectionalNode<Type>(addedThing);
    if(this->getSize() == 0 || this->getFront() == nullptr || this->getEnd() == nullptr)
    {
        this->setFront(addToStack);
    }
    else
    {
        this->getEnd()->setNextPointer(addToStack);
        addToStack -> setPreviousPointer(this->getEnd());
    }
    this->setEnd(addToStack);
    this->setSize(this->getSize() + 1);
}

template <class Type>
Type Stack<Type> :: pop()
{
    assert(this->getSize() > 0);
    Type removed = this->getEnd()->getNodeData();
    
    BiDirectionalNode<Type> * update = this->getEnd();
    update = update->getPreviousPointer();
    
    if(update != nullptr)
    {
        update->setNextPointer(nullptr);
    }
    
    delete this->getEnd();
    this->setEnd(update);
    this->setSize(this->getSize() - 1);
    return removed;
}

template <class Type>
Type Stack<Type> ::peek()
{
    assert(this->getSize() > 0);
    return this->getEnd()->getNodeData();
}

template <class Type>
void Stack<Type> :: add(Type add){
    push(add);
}

template <class Type>
Type Stack<Type> :: remove(int index){
    assert(index == this->getSize() - 1);
    return pop();
}
#endif /* Stack_h */
