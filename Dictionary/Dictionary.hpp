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

class Dictionary
{
    public :
    Dictionary();
    //~Dictionary();
    
    void InsertItem(string);
    bool SearchItem(string);
    
    //void DeleteItem(ItemType item);
    
    private :
    node *root;
    
};



#endif /* Dictionary_hpp */

