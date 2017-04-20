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
    
    a.InsertItem("Hello");
    a.InsertItem("Helloh");
    a.InsertItem("Hellohh");
    
    cout << a.SearchItem("hello") << endl;
    cout << a.SearchItem("Helloh") << endl;
    
    return 0;
}
