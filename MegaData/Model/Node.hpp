//
//  Node.hpp
//  ArrayProject
//
//  Created by Gallup, Tyler on 2/13/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

template <class Type>
class Node
{
private:
    
    Type nodeData;
    Node<Type> * nextPointer;
    
    
    
public:
    
    Node();
    Node(Type nodeData);
    Node(Type data, Node<Type> * pointer);
    
    Type getNodeData();
    Node<Type> * getNodePointer();
    void setNodeData(Type data);
    void setNodePointer(Node<Type>* pointer);

    
};

/*
Implamentation section
*/

template<class Type>
Node<Type> :: Node()
{
    //Explicitly DO NOT instanciate the nodeData data member
    this->nextPointer = nullptr;
}
template<class Type>
Node<Type> ::Node(Type data)
{
    this->nodeData = data;
    this->nextPointer = nullptr;
}

template<class Type>
Node<Type> :: Node(Type nodeData, Node<Type> * nextPointer)
{
    this->nodeData = nodeData;
    this->nextPointer = nextPointer;
}

template<class Type>
void Node<Type> :: setNodeData(Type data)
{
    this->nodeData = data;
}

template<class Type>
void Node<Type> :: setNodePointer(Node * nextPointer)
{
    this->nextPointer = nextPointer;
}

template<class Type>
Type Node<Type> :: getNodeData()
{
    return this->nodeData;
}

template<class Type>
Node<Type> * Node<Type> :: getNodePointer()
{
    return this -> nextPointer;
}












#endif /* Node_hpp */
