//
//  Dictionary.hpp
//  Dictionary
//
//  Created by Nur Islam & Koushik Roy on 4/20/17.
//  Copyright © 2017 O(1). All rights reserved.
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
    string Word(int);
    void WordSetter(int,string);
    
    
    private :
    node *root;
    int wordCounter;
    string word[100000];
    
};




#endif /* Dictionary_hpp */

