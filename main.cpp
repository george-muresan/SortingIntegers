//
//  main.cpp
//  ProjectOne
//
//  Created by George Muresan on 2/4/19.
//  Copyright © 2019 George Muresan. All rights reserved.
//
#include <iostream>
#include <fstream>
#include "main.h"
#include <ctime>

using namespace std;


int main(int argc, const char * argv[])
{
    
    /*
     he following steps should be executed by the main method:
     A.Read input file and store data items in both lists.
     B.Record the time needed to complete the sequence of retrievals for the Ordered Array Structure. Include the time needed to initially sort the list.
     C.Record the time needed to complete the sequence of retrievals for the MTF Linked List Structure.
     D.Display the total retrieval times for both List
     s, and declare which was faster.
     */
    
    clock_t TimeStart;
    clock_t TimeStop;
   
    MTFList list;



    
    //reading file in
    //string fileName = "/Users/georgemuresan/Desktop/poisson_small.txt";
    string fileName = argv[1];
    ifstream inFile(fileName.c_str());
    int totalNum = 0;
    int counter = 0;
    int data;
    
    //reading first character
    inFile >> totalNum;
    
    TimeStart = clock();
    while(counter < totalNum)
    {
        inFile >> data;
        counter++;
        list.push_front(data);
    }
    
    int expected = 0;
    inFile >> expected;
    for(int i = 0; i < expected; i++)
    {
        inFile >> data;
        list.search(data);
    }
    TimeStop = clock();
    double time1 = (double) (TimeStop - TimeStart) / CLOCKS_PER_SEC;

    cout << "Move To Front Method: ";
    cout << time1 << endl;
    
    inFile.close();
    
    
    clock_t TimeStart2;
    clock_t TimeStop2;
    
    
    
    
    //string fileName2 = "/Users/georgemuresan/Desktop/poisson_small.txt";
    string fileName2 = argv[1];
    ifstream inFile2(fileName2.c_str());
    totalNum = 0;
    
    inFile2 >> totalNum;
    orderedList List2 = orderedList(totalNum);
    TimeStart2 = clock();
    List2.read(inFile2);

    //DO THE SORT
    List2.mergeSort(0, totalNum);
   
    expected = 0;
    inFile2 >> expected;
    for(int i = 0; i < expected; i++)
    {
        inFile2 >> data;
        List2.binarySearch(data);
    }
    TimeStop2 = clock();
    double time2 = (double) (TimeStop2 - TimeStart2) / CLOCKS_PER_SEC;
    
    cout << "Ordered List Method: " << time2 << endl;

    
    if(time1 < time2)
    {
        cout << "The Move to Front method was faster by: " <<  time2 - time1 << endl;
    }
    
    if(time2 < time1)
    {
        cout << "The Ordered List method was faster by " << time1 - time2 << endl;
    }
    
    if(time1 == time2)
    {
        cout << "The methods were equally fast..." << endl;
    }
    
    
    
    inFile.close();
    
    
    //state both of the times
    //compare them after
    //use fi statements to tell which is faster
    // > < =
    
    
  
    return 0;
}
