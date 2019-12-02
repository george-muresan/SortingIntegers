//
//  orderedList.h
//  ProjectOne
//
//  Created by George Muresan on 2/7/19.
//  Copyright © 2019 George Muresan. All rights reserved.
//

#ifndef orderedList_h
#define orderedList_h
#include <fstream>
#include <iostream>

using namespace std;

class orderedList
{
public:

    //constructor
    orderedList(int capacity)
    {
        contents = new int [capacity];
        size = 0;
        this->capacity = capacity;
        
        //setting everything in array = to zero
        for(int i = 0; i < capacity; i++)
        {
            contents[i] = 0;
        }
    }

    void mergeSort(int low, int high)
    {
        int half;
        if(low < high)
        {
            half = (low + high) / 2;
            mergeSort(low, half);
            mergeSort(half+1, high);
            merge(low, half+1, high);
        }
    }

    int binarySearch(int anItem)
    {
        //returns location of item
        int low = 0;
        int high = size - 1;
        int mid = 0;
        bool something = false;
        while (low <= high && !something)
        {
            mid = (low + high) / 2;
            if (contents[mid] == anItem)
            {
                something = true;
            }
            else if (contents[mid] > anItem)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        if (something)
        {
            return mid;
        }
        else
        {
            return -1;
        }
    } //end

    void add(int data)
    {
        contents[size] = data;
        size++;
    }
    
    void read(ifstream &inFile2)
    {
        int counter = 0;
        int data; 
        while(counter < capacity)
        {
            inFile2 >> data;
            add(data);
            counter++;
        }
    }
    
    void print()
    {
        for(int i = 0; i < size; i++)
        {
            cout << contents[i] << " ";
        }
    }
    
private:
    int *contents;
    int size;
    int capacity;
    
    void merge( int start, int mid, int end)
    {
        //temp array
        int temp[end - start + 1];
        
        int i = start;
        int j = mid+1;
        int k = 0;
        
        while(i <= mid && j <= end)
        {
            if(contents[i] <= contents[j])
            {
                temp[k] = contents[i];
                k +=1;
                i +=1;
            }
            else
            {
                temp[k] = contents[j];
                k +=1;
                j +=1;
            }
        }
        
        while (i <= mid)
        {
            temp[k] = contents[i];
            k +=1;
            i +=1;
        }
        while(j <= end)
        {
            temp[k] = contents[j];
            k +=1;
            j +=1;
        }
        
        for( i = start; i <= end; i+=1)
        {
            contents[i] = temp[i - start];
        }
        
        
    }
};

#endif /* orderedList_h */
