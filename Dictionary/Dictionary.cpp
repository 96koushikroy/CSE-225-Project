//
//  Dictionary.cpp
//  Dictionary
//
//  Created by Nur Islam on 4/20/17.
//  Copyright © 2017 nur islam. All rights reserved.
//

#include "Dictionary.hpp"
#include <iostream>
using namespace std;


Dictionary::Dictionary(){
    root = new node();
}



void Insert(node *root, string item)
{
    node *curr = root;
    int id, len = (int)item.size();
    
    for(int i=0; i < len; i++)
    {
        char ch = item[i];
        if(isupper(ch)) id = (ch-'A')+26;
        else id = (ch-'a');
        
        if(curr->next[id] == NULL)
            curr->next[id] = new node();
        
        curr = curr->next[id];
    }
    curr->endmark = true;
}


void Dictionary::InsertItem(string item)
{
    Insert(root, item);
}



bool Search(node *root, string item)
{
    node *curr = root;
    int id, len = (int)item.size();
    
    for(int i=0; i<len; i++)
    {
        char ch = item[i];
        if(isupper(ch)) id = (ch-'A')+26;
        else id = (ch-'a');
        
        if(curr->next[id] == NULL) return false;
        curr = curr->next[id];
    }
    return curr->endmark;
}


bool Dictionary::SearchItem(string item)
{
    return Search(root, item);
}




