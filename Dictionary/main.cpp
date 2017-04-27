//
//  main.cpp
//  Dictionary
//
//  Created by Nur Islam & Koushik Roy on 4/20/17.
//  Copyright © 2017 O(1). All rights reserved.
//

#include <iostream>
#include "Dictionary.hpp"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


Dictionary a;

void BuildTrie()
{
    ifstream fin;
    fin.open("data.txt");
    

    while(!fin.eof())
    {
        string word,meaning;
        fin >> word;
        fin.ignore();
        getline(fin, meaning);
        
        //cout << "word : " << word << endl;
        //cout << " Meaning : " << meaning << endl;
        a.InsertItem(word, meaning);
    }
    
    fin.close();
}

void BuildSynonymGraph()
{
    ifstream fin;
    fin.open("Synonym.txt");
    
    
    while(!fin.eof())
    {
        string word1,word2;
        fin >> word1;
        fin >> word2;
        
        //cout << word1 << " " << word2 << endl;
        
        //cout << "word : " << word << endl;
        //cout << " Meaning : " << meaning << endl;
        a.addSynonym(word1, word2);
    }
    
    fin.close();
}


int main(int argc, const char * argv[]) {
    
    BuildTrie();
    BuildSynonymGraph();
    
    cout << "CSE 225 Semester Final Project." << endl;
    cout << "Dictionary version 1.0" << endl;
    
    cout << "Type a word to search for it's meaning." << endl;
    cout << "Or Type '---' without quotes to stop the program." << endl;
    cout << endl;
    string s;
    
    while(cin >> s){
        if(s == "---")break;
        Pair WordInfo = a.SearchItem(s);
        cout << endl;
        if(WordInfo.wordId < 1){
            cout << "No meanings were found for " << "'" << s << "'" << "." << endl;
            cout << endl;
        }
        else{
        
        
        cout << "Word: " << s << endl;
        cout << "Word ID: " << WordInfo.wordId << endl;
        cout << "Meaning: " << WordInfo.meaning << endl;
        cout << endl;
        
        vector <string> syn = a.getSynonymList(s);
        
        if(syn.size() > 1){
            cout << syn.size()-1 << " synonym/s were found: " << endl;
            
            for(int k = 1; k < syn.size(); k++){
                cout << syn[k] << endl;
            }
            cout << endl;
        }
        else{
            cout << "No synonyms were found for this word." << endl;
            cout << endl;
        }
        }
        
        cout << "-----x-----" << endl;
        cout << endl;
        
    }
    
}
