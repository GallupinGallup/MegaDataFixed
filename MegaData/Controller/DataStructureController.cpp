//
//  DataStructureController.cpp
//  MegaDatas
//
//  Created by Gallup, Tyler on 2/8/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#include "DataStructureController.hpp"
#include <iostream>
#include "../Model/IntNode.hpp"
#include "../Model/IntNodeArray.hpp"
#include "../Model/List.hpp"
#include "../Model/Queue.hpp"
#include "../Model/FoodItem.hpp"
#include "../Model/Stack.hpp"
#include "../Model/CircularList.hpp"
#include "../Model/DoubleList.hpp"
#include "../Model/BinarySearchTree.h"
#include "../Model/AVLTree.h"
#include "../Model/CrimeData.hpp"
#include "../Model/HashTable.h"
#include "FileController.hpp"
#include "../Model/Graph.h"

using namespace std;

DataStructureController :: DataStructureController(){
    wordNode = Node<string>();
    numberNode = Node<int>();
}

void DataStructureController :: start(){
    testGraph();
}

void DataStructureController:: testAdvancedFeatures(){
    int showDestructor = 0;
    
    if(showDestructor < 1){
        Array<string> words = Array<string>(5);
        cout << "There should be message about destructor next" << endl;
    }
    Array<string> words = Array<string>(4);
    words.setAtIndex(0, "at zero");
    words.setAtIndex(3, "Int the last spot");
    Array<string> copiedWords = Array<string>(words);
    
    cout << "These should match: " << endl;
    cout << words.getFromIndex(0) << " Should be the same as " << copiedWords.getFromIndex(0) << endl;
}

void DataStructureController :: testIntArray(){
    cout << "Testing the array" << endl;
    
    IntNodeArray temp = IntNodeArray(3);
    
    for(int index = 0; index < 3; index++){
        cout << temp.getFromIndex(index) << " is at spot " << index << endl;
    }
}

void DataStructureController:: testList(){
    List<string> taco;
    taco.addFront("Welcome to disneyland");
    taco.addEnd("The end is nigh.");
    taco.addAtIndex(1, "This is the 2nd (3rd) pos");
    taco.addEnd("Conman");
    
    cout << "Contains \"Conman\"? " << taco.contains("Conman") << endl << endl;
    
    for(int index = 0; index < taco.getSize(); index++){
        cout << taco.getFromIndex(index) << " is at index: " << index << endl;
    }
    
    taco.remove(3);
    
    cout << "Size: " << taco.getSize() << endl << endl;
    cout << "Contains \"Conman\"? " << taco.contains("Conman") << endl << endl;
}

void DataStructureController:: testNodes(){
    cout << "The contentes of Node<stinrg>" << endl;
    cout << wordNode.getNodeData() << endl;
    cout << "Here is the Node<int>" << endl;
    cout << numberNode.getNodeData() << endl;
}

void DataStructureController :: testListTiming()
{
    DoubleList<int> timingList;
    Timer totalTimer;
    totalTimer.startTimer();
    for(int index = 0; index < 10000; index++)
    {
        
        timingList.add(rand());
        
    }
    long slowTime [1000];
    long fastTime [1000];
    double averageSlow = 0.00, averageFast = 0.00;
    Timer doubleTimer;
    
    for(int index = 0; index < 1000; index++)
    {
        
        int randomIndex = rand() % 10000;
        doubleTimer.startTimer();
        timingList.getFromIndex(randomIndex);
        doubleTimer.stopTimer();
        slowTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        
        doubleTimer.startTimer();
        timingList.getFromIndexFast(randomIndex);
        doubleTimer.stopTimer();
        fastTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        averageSlow += slowTime[index];
        averageFast += fastTime[index];
        
        
    }
    
    averageSlow += averageSlow/1000.00;
    averageFast += averageFast/1000.00;
    
    cout << "When you do it in one diretion searching you get an average of: "  << averageSlow<< endl;
    cout << "When you do the BiDirectional way you get: " << averageFast << endl;
}

void DataStructureController:: testIntStack(){
    Stack<int> numberStack;
    
    numberStack.push(811);
    numberStack.add(2315);
    
    cout << "Size of Stack: " << numberStack.getSize() << endl;
    
    numberStack.push(00);
    numberStack.push(5555);
    numberStack.push(9898);
    
    cout << "Size of Stack: " << numberStack.getSize() << endl;
    
    int testValue = numberStack.pop();
    cout << "Test value is " << testValue << " and should be 9898 " << endl;
    
    int otherTest = numberStack.remove(3);
    cout << "Other test value is " << otherTest << " and should be 5555 " << endl;
    
    cout << "Size of Stack: " << numberStack.getSize() << endl;
    
    cout << endl;
    
}

void DataStructureController:: testFoodQueue(){
    Queue<FoodItem> foods;
    
    FoodItem chickenTaco("Chicken taco with lettuce");
    chickenTaco.setCost(100);
    chickenTaco.setCalories(2000);
    chickenTaco.setDelicious(true);
    
    FoodItem steakTaco("Steak taco with cheese");
    steakTaco.setCost(200);
    steakTaco.setCalories(1000);
    steakTaco.setDelicious(true);
    
    FoodItem redBeets("Cooked red Beets");
    redBeets.setCost(1);
    redBeets.setCalories(60);
    redBeets.setDelicious(false);
    
    cout << "Size: " << foods.getSize() << endl;
    
    foods.enqueue(chickenTaco);
    foods.add(steakTaco);
    
    cout << "Size: " << foods.getSize() << endl;
    
    FoodItem firstItem = foods.peek();
    cout << "Item in queue: " << firstItem.getFoodName() << endl;
    
    foods.enqueue(redBeets);
    
    FoodItem dequeued = foods.dequeue();
    cout << "The Item dequeued from the queue was: " << dequeued.getFoodName() << endl;
    
    FoodItem removed = foods.dequeue();
    cout << "The Item removed from the queue was: " << removed.getFoodName() << endl << endl;
}

void DataStructureController :: testBinarySearchTreeOperations()

{
    
    BinarySearchTree<int> numbers;
    numbers.insert(9843);
    numbers.insert(10);
    numbers.insert(43);
    numbers.insert(-123);
    numbers.insert(23465);
    
    numbers.insert(10); // won't go in
    
    numbers.insert(43243);
    
    numbers.insert(-45677654);
    
    numbers.insert(92165);
    
    
    
    cout << "Size should be 8 and is: " << numbers.getSize() << endl;
    
    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;
    
    numbers.inOrderTraversal();
    
    
    
    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;
    
    cout << "Balanced should be false || 0 and is: " << numbers.isBalanced() << endl;
    
}

void DataStructureController:: testAVLTreeOperation(){
    AVLTree<int> numbers;
    
    numbers.insert(9843);
    
    numbers.insert(10);
    
    numbers.insert(43);
    
    numbers.insert(-123);
    
    numbers.insert(23465);
    
    numbers.insert(10); // won't go in
    
    numbers.insert(43243);
    
    numbers.insert(-45677654);
    
    numbers.insert(92165);
    
    
    
    cout << "Size should be 8 and is: " << numbers.getSize() << endl;
    
    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;
    
    numbers.inOrderTraversal();
    
    numbers.preOrderTraversal();
    
    numbers.postOrderTraversal();
    
    numbers.insert(92165); // won't go in
    
    numbers.insert(2);
    
    numbers.remove(10);
    
    numbers.remove(2);
    
    
    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;
    
    cout << "Balanced should be true || 1 and is: " << numbers.isBalanced() << endl;
}

void DataStructureController:: testAVLData(){
    FileController fileData;
    
    Timer treeTimer;
    
    treeTimer.startTimer();
    
    AVLTree<CrimeData> crimeTree = fileData.readCrimeDataToAVLTree("/Users/tgal3078/Documents/c++/MegaData/MegaData/Assets/crime.csv");
    
    treeTimer.stopTimer();
    
    
    
    int count = crimeTree.getSize();
    
    int height = crimeTree.getHeight();
    
    bool complete = crimeTree.isComplete();
    
    bool balanced = crimeTree.isBalanced();
    
    
    
    cout << "The count of the tree is: " << count << ", the height is " << height << ".\n The tree's balanced status is " << balanced << ", and its complete status is " << complete << endl;
    
    cout << "The time to read in the tree was: " << endl;
    
    treeTimer.displayTimerInformation();
}

void DataStructureController:: testHashTable(){
    HashTable<int> hashTable;
    hashTable.add(4);
    hashTable.add(5);
    hashTable.add(6);
    hashTable.add(14);
    hashTable.add(16);
    hashTable.add(19);
    hashTable.add(24);
    hashTable.add(35);
    hashTable.add(46);
    hashTable.add(64);
    
    hashTable.displayContents();
    HashNode<int> number;
    number.setData(4);
}

void DataStructureController:: testGraph(){
    Graph<string> myHobbies;
    
    myHobbies.addVertex("Programming");
    myHobbies.addVertex("Video Games");
    myHobbies.addVertex("Engeneering");
    myHobbies.addVertex("Swimming");
    myHobbies.addVertex("Hiking");
    myHobbies.addVertex("Camping");
    
    myHobbies.addEdge(0,1);
    myHobbies.addEdge(1,2);
    myHobbies.addEdge(3,4);
    myHobbies.addEdge(4,5);
    
    myHobbies.depthFirstTraversal(myHobbies, 0);
    
    cout << endl;
    
    myHobbies.breadthFirstTraversal(myHobbies, 0);
}

