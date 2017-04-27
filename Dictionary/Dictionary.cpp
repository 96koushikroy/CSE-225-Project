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
    //cout << wordCounter << endl;
    WordSetter(wordCounter,item);
}



Pair isFound(node *root, string item)
{
    node *curr = root;
    int id, len = (int)item.size(), wID = -1; string wM = "Not Found";
    if(!isalpha(item[0])) return {wM,wID};
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


Pair Dictionary::SearchItem(string item)
{
    Pair res = isFound(root, item);
    return res;
}

void Dictionary::addSynonym(string w1, string w2){
    int id1 = isFound(root, w1).wordId;
    int id2 = isFound(root, w2).wordId;
    
    Synonym[id1].push_back(id2);
    Synonym[id2].push_back(id1);
}

int visited[100000];

vector <string> Dictionary::getSynonymList(string word){
    for(int k = 1; k <= wordCounter; k++)
        visited[k] = 0;
    
    vector <string> synonymList;
    
    int id1 = isFound(root, word).wordId;
    
    SynonymDFS(synonymList, id1);
    return synonymList;
}

void Dictionary::SynonymDFS(vector <string> &v, int node){
    visited[node] = 1;
    v.push_back(Word(node));
    
    for(int i = 0; i < Synonym[node].size(); i++){
        int word2ID = Synonym[node][i];
        if(!visited[word2ID]){
            visited[word2ID] = 1;
            SynonymDFS(v, word2ID);
        }
    }
    
}











