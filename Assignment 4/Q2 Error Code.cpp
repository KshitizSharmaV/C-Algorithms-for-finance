//
//  AutoPtrTest.cpp
//  check
//
//  Created by Kshitiz Sharma on 21/02/18.
//  Copyright © 2018 Kshitiz Sharma. All rights reserved.
//

#include "AutoPtrTest.hpp"
#include <iostream>
#include <memory>

using namespace std;

class Man
{
private:
    double value;
    auto_ptr<Man> ptr;
    
public:
    Man(double len) { value=len;cout << "constructor: " << value << endl; }
    Man(Man& obj){
        //ptr(_obj.value.get()?(new Man(*_obj.value.get())):0)
        //  ptr=*obj.value;
        // ptr(*obj.value);
        
    }
        
    ~Man() { cout << "destructor: " << value << endl; }
    //void setMan(double d) { Value = d; }

};

int main()
{
    //auto_ptr<Man> ptr(new Double(3.14));
    Man value(10);
    //(*ptr).setMan(15);
    return 0;
}


