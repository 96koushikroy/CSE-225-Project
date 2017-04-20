//
//  Dictionary.hpp
//  Dictionary
//
//  Created by Nur Islam on 4/20/17.
//  Copyright © 2017 nur islam. All rights reserved.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <stdio.h>
#include <iostream>
using namespace std;


template <class ItemType>
struct node
{
    bool endmark;
    node *next[52+2];
    
    node(){
        endmark = false;
        for(int i = 0; i <= 52; i++)
            next[i] = NULL;
    }
};

template <class ItemType>
class Tree
{
    public :
    Tree();
    ~Tree();
    
    void InsertItem(ItemType item);
    bool SearchItem(ItemType item);
    //void DeleteItem(ItemType item);
    
    private :
    node <ItemType> *root;
};



#endif /* Dictionary_hpp */

