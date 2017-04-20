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
    int wordID;
    string wordMeaning;
    node *next[52+2];
    
    node(){
        endmark = false;
        for(int i = 0; i <= 52; i++)
            next[i] = NULL;
    }
};

struct Pair
{
    string meaning;
    int wordId;
};



class Dictionary
{
    public :
    Dictionary();
    //~Dictionary();
    
    void InsertItem(string, string);
    void SearchItem(string);
    
    //void DeleteItem(ItemType item);
    
    private :
    node *root;
    int wordCounter;
    
};



#endif /* Dictionary_hpp */

