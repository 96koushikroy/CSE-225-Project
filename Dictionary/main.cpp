//
//  main.cpp
//  Dictionary
//
//  Created by Nur Islam on 4/20/17.
//  Copyright © 2017 nur islam. All rights reserved.
//

#include <iostream>
#include "Dictionary.hpp"
using namespace std;




int main(int argc, const char * argv[]) {
    Dictionary a;
    
    a.InsertItem("Hello","Greetings from Koushik Roy1");
    a.InsertItem("Helloh","Greetings from Koushik Roy2");
    a.InsertItem("Hellohh","Greetings from Koushik Roy3");
    
    a.SearchItem("Hello1");
    
    return 0;
}
