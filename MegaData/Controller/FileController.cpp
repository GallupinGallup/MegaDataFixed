//
//  FileController.cpp
//  ArrayProject
//
//  Created by Gallup, Tyler on 3/27/17.
//  Copyright © 2017 Gallup, Tyler. All rights reserved.
//

#include "FileController.hpp"



DoubleList<FoodItem> FileController :: readDataFromFile(string fileName)
{
    DoubleList<FoodItem> dataSource;
    string currentCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(fileName);
    if(dataFile.is_open())
    {
        while(!dataFile.eof())
        {
            getline(dataFile, currentCSVLine, '\r');
            stringstream parseCSV(currentCSVLine);
            
            string title, tempCost, tempCalorie, tempTasty;
            double cost;
            int calories;
            bool isDelish;
            
            //Each part as a string in order of the csv - hen convert after using stod, stoi
            getline(parseCSV, title, ',');
            getline(parseCSV, tempCost, ',');
            getline(parseCSV, tempCalorie, ',');
            getline(parseCSV, tempTasty, ',');
            
            if(rowCount != 0)
            {
                cost = stod(tempCost);
                calories = stoi(tempCalorie);
                isDelish = stoi(tempTasty);
                
                FoodItem temp(title);
                temp.setCost(cost);
                temp.setCalories(calories);
                temp.setDelicious(isDelish);
                
                dataSource.add(temp);
            }
            rowCount++;
            
            cout<< currentCSVLine << endl;
        }
        dataFile.close();
    }
    else
    {
        cerr<< "NO FILE" << endl;
        
    }
    return dataSource;
}


void FileController :: writeFoodDataStatistics(DoubleList<FoodItem> dataSource, string fileName)
{
    ofstream saveFile(fileName);
    
    if(saveFile.is_open())
    {
        saveFile << "These are the contents of the list" << endl;
        for(int index =0; index < dataSource.getSize(); index++)
        {
            saveFile << "Food Title: " << dataSource.getFromIndex(index).getFoodName() << endl;
            
        }
        
    }
    else
    {
        cerr<< "File unavalible" << endl;
    }
    saveFile.close();
}

BinarySearchTree<CrimeData> FileController :: readCrimeDataToBinarySearchTree(string filename)

{
    
    BinarySearchTree<CrimeData> crimeData;
    
    
    
    string currentCSVLine;
    
    int rowCount = 0;
    
    
    
    ifstream dataFile(filename);
    
    
    
    if(dataFile.is_open())
        
    {
        
        while(!dataFile.eof())
            
        {
            
            getline(dataFile, currentCSVLine, '\r');
            
            
            
            //Exclude first row headers
            
            if (rowCount != 0)
                
            {
                
                CrimeData rowData(currentCSVLine);
                
                crimeData.insert(rowData);
                
            }
            
            rowCount++;
            
        }
        
        dataFile.close();
        
    }
    
    else
        
    {
        
        cerr << "NO FILE" << endl;
        
    }
    
    
    
    
    
    return crimeData;
    
}

AVLTree<CrimeData> FileController :: readCrimeDataToAVLTree(string filename)

{
    
    AVLTree<CrimeData> crimeData;
    
    
    
    string currentCSVLine;
    
    int rowCount = 0;
    
    
    
    ifstream dataFile(filename);
    
    
    
    if(dataFile.is_open())
        
    {
        
        while(!dataFile.eof())
            
        {
            
            getline(dataFile, currentCSVLine, '\r');
            
            
            
            //Exclude first row headers
            
            if (rowCount != 0)
                
            {
                
                CrimeData rowData(currentCSVLine);
                
                crimeData.insert(rowData);
                
            }
            
            rowCount++;
            
        }
        
        dataFile.close();
        
    }
    
    else
        
    {
        
        cerr << "NO FILE" << endl;
        
    }
    
    
    
    return crimeData;
    
}















