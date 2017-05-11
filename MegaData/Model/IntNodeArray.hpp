//
//  IntNodeArray.hpp
//  ArrayProject
//
//  Created by Gallup, Tyler on 2/8/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef IntNodeArray_hpp
#define IntNodeArray_hpp
#include "IntNode.hpp"

class IntNodeArray
{
private:
    IntNode * front;
    int size;
    
public:
    IntNodeArray(int size);
    void setAtIndex(int index, int value);
    int getFromIndex(int index);
    int getSize();
};

#endif /* IntNodeArray_hpp */
