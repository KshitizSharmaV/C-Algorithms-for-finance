//
//  main.cpp
//  check
//
//  Created by Kshitiz Sharma on 21/02/18.
//  Copyright © 2018 Kshitiz Sharma. All rights reserved.
//

#include <iostream>
#include "time.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    clock_t start,finish;
    start=clock();
    int n=10000;
    size_t mySize = 1000;
    for(int i=1;i<=n;i++){
            double* data = new double[mySize];
    }
    finish=clock();
    std::cout<<"The number of times loop ran for " << n <<"\n";
    std::cout<<"The size of array is " << mySize <<"\n";
    std::cout << ((double)(finish-start))/CLOCKS_PER_SEC<<"\n";
    return 0;
}
