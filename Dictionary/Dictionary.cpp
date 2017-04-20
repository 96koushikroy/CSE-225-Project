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


template <class ItemType>
Tree <ItemType> :: Tree(){
    root = NULL;
}


template <class ItemType>
void Insert(Tree<ItemType> *&root, ItemType item)
{
    node *curr = root;
    int id, len = strlen(item);
    
    for(int i=0; i<len; i++)
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

template <class ItemType>
void Tree <ItemType> :: InsertItem(ItemType item)
{
    Insert(root, item);
}



template <class ItemType>
bool Search(Tree<ItemType> *&root, ItemType item)
{
    node *curr = root;
    int id, len = strlen(item);
    
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

template <class ItemType>
bool Tree <ItemType> :: SearchItem(ItemType item)
{
    return Search(root, item);
}




