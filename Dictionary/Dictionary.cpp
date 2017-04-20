//
//  Dictionary.cpp
//  Dictionary
//
//  Created by Nur Islam & Koushik Roy on 4/20/17.
//  Copyright © 2017 O(1). All rights reserved.
//

#include "Dictionary.hpp"
#include <iostream>
using namespace std;


Dictionary::Dictionary(){
    root = new node();
    wordCounter = 0;
}


string Dictionary::Word(int ID){
    return word[ID];
}

void Dictionary::WordSetter(int ID, string w){
    word[ID] = w;
}

void Insert(node *root, string item, string meaning, int cnt)
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
    curr->wordMeaning = meaning;
    curr->wordID = cnt;
    
}


void Dictionary::InsertItem(string item, string meaning)
{
    Insert(root, item, meaning,++wordCounter);
    WordSetter(wordCounter,item);
}



Pair isFound(node *root, string item)
{
    node *curr = root;
    int id, len = (int)item.size(), wID = -1; string wM = "Not Found";
    
    for(int i=0; i<len; i++)
    {
        char ch = item[i];
        if(isupper(ch)) id = (ch-'A')+26;
        else id = (ch-'a');
        
        if(curr->next[id] == NULL) return {wM,wID};
        curr = curr->next[id];
    }
    
    wM = curr->wordMeaning;
    wID = curr->wordID;
    
    
    return {wM,wID};
}


void Dictionary::SearchItem(string item)
{
    Pair res = isFound(root, item);
    cout << res.wordId << " " << res.meaning << endl;
}












