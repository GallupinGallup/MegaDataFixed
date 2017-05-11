//
//  FileController.hpp
//  ArrayProject
//
//  Created by Gallup, Tyler on 3/27/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include "../Model/DoubleList.hpp"
#include "../Model/FoodItem.hpp"
#include "../Model/CrimeData.hpp"
#include "../Model/BinarySearchTree.h"
#include "../Model/AVLTree.h"
#include <string> // String access
#include <fstream> // File operations
#include <iostream> // Console thing
#include <sstream> // String as stream


using namespace std;

class FileController
{
private:
    DoubleList<FoodItem> foodItemList;
    
    
public:
    DoubleList<FoodItem> readDataFromFile(string filename);
    void writeFoodDataStatistics(DoubleList<FoodItem> source, string fileName);
    BinarySearchTree<CrimeData> readCrimeDataToBinarySearchTree(string filename);
    AVLTree<CrimeData> readCrimeDataToAVLTree(string filename);
};






#endif /* FileController_hpp */
