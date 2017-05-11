//
//  DataStructureController.hpp
//  MegaDatas
//
//  Created by Gallup, Tyler on 2/8/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//
#ifndef DataStructureController_hpp
#define DataStructureController_hpp

#include "../Model/Node.hpp"
#include "../Model/Array.hpp"
#include "../Model/CircularList.hpp"
#include "../Model/Queue.hpp"
#include "../Model/Stack.hpp"
#include "../Model/DoubleList.hpp"
#include "../Model/DoublyLinkedList.hpp"
#include "../Model/BiDirectionalNode.hpp"
#include "../Model/Timer.hpp"

#include <string>

using namespace std;

class DataStructureController
{
private:
    void testIntArray();
    Node<int> numberNode;
    Node<string> wordNode;
    void testAdvancedFeatures();
    void testList();
    void testListTiming();
    void testNodes();
    void testIntStack();
    void testFoodQueue();
    void testBinarySearchTreeOperations();
    void testAVLData();
    void testAVLTreeOperation();
    void testHashTable();
    void testGraph();
public:
    DataStructureController();
    void start();
    
};

#endif /*DataStructureController*/
