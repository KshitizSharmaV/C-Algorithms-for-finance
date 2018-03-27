//
//  Assignment_Double_Digital.cpp
//  Derivative Pricing and Pattern Analysis
//
//  Created by Kshitiz Sharma on 26/01/18.
//  Copyright © 2018 Kshitiz Sharma. All rights reserved.
//
//
//
//                  Double Digital.cpp
//
//



#include<SimpleMC.h>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    
    double Expiry;
    double LStrike;
    double UStrike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    
    cout << "\nEnter expiry\n";
    cin >> Expiry;
    
    cout << "\nEnter Lower strike\n";
    cin >> LStrike;
    
    cout << "\nEnter Upper strike\n";
    cin >> UStrike;
    
    cout << "\nEnter spot\n";
    cin >> Spot;
    
    cout << "\nEnter vol\n";
    cin >> Vol;
    
    cout << "\nr\n";
    cin >> r;
    
    cout << "\nNumber of paths\n";
    cin >> NumberOfPaths;
    
    double result = SimpleMonteCarlo1(Expiry,
                                      LStrike,
                                      UStrike,
                                      Spot,
                                      Vol,
                                      r,
                                      NumberOfPaths);
    
    cout <<"the price of option is " << result << "\n";
    
    double tmp;
    cin >> tmp;
    
    return 0;
}










/*
 *
 * Copyright (c) 2002
 * Mark Joshi
 *
 * Permission to use, copy, modify, distribute and sell this
 * software for any purpose is hereby
 * granted without fee, provided that the above copyright notice
 * appear in all copies and that both that copyright notice and
 * this permission notice appear in supporting documentation.
 * Mark Joshi makes no representations about the
 * suitability of this software for any purpose. It is provided
 * "as is" without express or implied warranty.
 */

