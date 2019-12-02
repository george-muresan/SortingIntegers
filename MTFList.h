//
//  mtfList.h
//  ProjectOne
//
//  Created by George Muresan on 2/7/19.
//  Copyright © 2019 George Muresan. All rights reserved.
//

#ifndef mtfList_h
#define mtfList_h

using namespace std;

struct Node
{
    int num;
    Node *next;

};

class MTFList
{
private:
    Node *header;
    //Node *trailer;
    
public:
    MTFList()
    {
        header = NULL;
        //trailer = NULL;
    }
    
    ~MTFList()
    {
        while(header != NULL)
        {
            Node *temp = header;
            header = header->next;
            delete temp;
        }
    }
    
    void push_front(int number) throw(bad_alloc)
    {
        Node *current = new Node;
        current->num = number;
        //current->next = NULL;
        current->next = header;
        header = current;
    }
    
    void print()
    {
        Node *current;
        current = header;
        //trailer = NULL;
        while(current != NULL)
        {
            cout << current->num << " ";
            current = current->next;
        }
    }
    
    void deleteIt(int value)
    {
        Node *current = header->next;
        Node *trailer = header;
        
        while(current != NULL && current->num != value)
        {
            trailer = current;
            current = current->next;
        }
        if (current == NULL){
            cout << "Cannot delete " << value << ". It is not in the list" << endl;
        }
        else if(current->num == value)
        {
            trailer->next = current->next;
            delete current;
            current = trailer->next;
        }
        
    }
    
    
    bool search(int value)
    {
        Node *current = header;
        Node *trailer = NULL;
        while(current != NULL)
        {
            if(current->num == value)
            {
                if(trailer != NULL)
                {
                    trailer->next = current->next;
                    current->next = header;
                    header = current;
                }
                
                return true;
            }
            
            
            trailer = current;
            current = current->next;
        }
        
        return false;
    }
    
    
    
    
    
};

#endif /* mtfList_h */
