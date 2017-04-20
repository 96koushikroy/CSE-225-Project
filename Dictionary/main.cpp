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

void BuildTree()
{
    ifstream fin;
    //fin.open("/Users/nurislam/Google Drive/NSU/CSE - Project/CSE-225-Project/data.txt");
    fin.open("data.txt");
    //fin.open("data.txt", fstream::in | fstream::out | fstream::app);
    

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


int main(int argc, const char * argv[]) {
    
    BuildTree();
    
    string s;
    
    while(cin >> s){
        if(s == "---")break;
        a.SearchItem(s);
    }
    
}
