//
//  main.cpp
//  Dictionary
//
//  Copyright © 2017 O(1). All rights reserved.
//

#include <iostream>
#include "Dictionary.hpp"
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

/* Prototype */
int About();
int Search();
int HelpManual();


Dictionary a;
int About()
{
    cout << endl;
    
    cout << "---------------" << endl;
    
    cout << endl;
    
    cout << "Amazing Dictionary" << endl;
    cout << "\nCreated BY : " << endl;
    cout << "Koushik Roy. \nNur Islam. \nSaida Mahmood. \nKamrun Nahar." << endl;
    cout << "\nCSE 225 Semester Final Project." << endl;
    cout << "Version 1.0\n" << endl;
    
    cout << "Press Any Of The Key To Go For: " << endl;
    cout << "9 >> Main Menu." << endl;
    cout << "0 >> Quit." << endl;
    
    int choice;
    cout << "\nYour Choice : ";
    scanf("%d",&choice);
    
    if(choice == 0){
        return 4;
    }
    else if(choice == 9) return 0;
    else cout << "You Pressed the Wrong Key. Going Back to Main Menu.." << endl;
    return 0;
}

int HelpManual()
{
    
    cout << endl;
    
    cout << "---------------" << endl;
    
    cout << endl;
    cout << "Instructions:" << endl;
    cout << "\n1) From Main Menu Press 3" << endl;
    cout << "2) Then Type the word to search" << endl;
    cout << "3) The search result will be given below." << endl << endl;
    
    cout << "Press Any Of The Key To Go For: " << endl;
    cout << "9 >> Main Menu." << endl;
    cout << "0 >> Quit." << endl;
    
    int choice;
    cout << "\nYour Choice : ";
    scanf("%d",&choice);
    
    if(choice == 0){
        return 4;
    }
    else if(choice == 9) return 0;
    else cout << "You Pressed the Wrong Key. Going Back to Main Menu.." << endl;
    return 0;
}


int Search()
{
    
    cout << "\nType a word to search for it's meaning." << endl << endl;
    
    string s;
    while(cin >> s)
    {
        string ss = "";
        for(int i = 0; s[i]; ++i)
            ss += tolower(s[i]);
        
        Pair WordInfo = a.SearchItem(ss);
        cout << endl;
        
        cout << "Search Result:" << endl;
        cout << "---------------" << endl << endl;
        
        if(WordInfo.wordId < 1)
        {
            cout << "No meanings were found for " << "'" << s << "'" << "." << endl;
            cout << endl;
        }
        else
        {
            cout << "Word: " << s << endl;
            cout << "Word ID: " << WordInfo.wordId << endl;
            cout << "Meaning: " << WordInfo.meaning << endl;
            cout << endl;
            
            vector <string> syn = a.getSynonymList(ss);
            
            if(syn.size() > 1){
                cout << syn.size()-1 << " synonym/s were found: " << endl;
                
                for(int k = 1; k < syn.size(); k++){
                    cout << syn[k] << endl;
                }
                cout << endl;
            }
            else{
                cout << "Synonyms: No synonyms were found for this word." << endl;
                cout << endl;
            }
        }
        
        cout << "-------x-------" << endl;
        cout << endl;
        
        cout << "Press: " << endl;
        cout << "1 >> Search Another word." << endl;
        cout << "2 >> Main Menu." << endl;
        cout << "0 >> Quit." << endl;
        cout << endl;
        int choice;
        cout << "Your Choice: ";
        scanf("%d",&choice);
        
        if(choice == 0){
            return 4;
        }
        else if(choice == 2) return 0;
        else if(choice == 1) {
            cout << "\nType a word to search for it's meaning." << endl << endl;
            continue;
        }
        else cout << "You Pressed the Wrong Key. Going Back to Main Menu.." << endl;
        break;
        
    }
    return 0;
}



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
        
        a.addSynonym(word1, word2);
    }
    
    fin.close();
}


int main(int argc, const char * argv[]) {
    
    BuildTrie();
    BuildSynonymGraph();
    
    int flag = 0;
    
    while(1){
        
        if(flag){
            
            cout << endl;
            
            cout << "---------------" << endl;
            
        }
        
        cout << endl;
        cout << "Welcome To Amazing Dictionary" << endl;
        cout << "You Can Search Any Word and It will Show The Corresponding Meaning\n" << endl;
        
        cout << "Press Any Of The Key To Go For: " << endl;
        cout << " 1 >> About." << endl;
        cout << " 2 >> Help Manual." << endl;
        cout << " 3 >> Search For Word." << endl;
        cout << " 0 >> Quit." << endl;
        cout << "\nYour Choice : ";
        
        int choice;
        scanf("%d",&choice);
        
        int res = -1;
        
        if(choice == 0)
        {
            cout << "Thanks For using Our App." << endl;
            return 0;
        }
        else if(choice == 1) res = About();
        else if(choice == 2) res = HelpManual();
        else if(choice == 3) res = Search();
        else cout << "You Pressed the Wrong Key." << endl;
        
        if(res == 4){
            cout << "Thanks For using Our App." << endl;
            return 0;
        }
        
        flag = 1;
        
    }

    return 0;
    
    
}
