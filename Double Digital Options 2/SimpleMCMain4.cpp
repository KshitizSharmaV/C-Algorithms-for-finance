//
//
//		SimpleMCMain4.cpp
//
//     
/*
requires 
        PayOff2.cpp 
        Random1.cpp 
        SimpleMC2.cpp
*/
#include<SimpleMC2.h>
#include<iostream>
#include<time.h>

using namespace std;

int main()
{
    double Expiry;
	double Strike;
    double LStrike;
    double UStrike;
	double Spot; 
	double Vol; 
	double r; 
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nr\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;


    unsigned long optionType;

    cout << "\nenter 0 for call, 1 for put, 2 for Double Digital ";
    cin >> optionType;


    PayOff* thePayOffPtr; 

    switch(optionType){
            case 0:
                cout << "\nEnter strike\n";
                cin >> Strike;
                thePayOffPtr = new PayOffCall(Strike);
                break;
            case 1:
                cout << "\nEnter strike\n";
                cin >> Strike;
                thePayOffPtr = new PayOffPut(Strike);
                break;
            case 2:
                cout << "\nEnter Lstrike\n";
                cin >> LStrike;
                cout << "\nEnter Ustrike\n";
                cin >> UStrike;
                thePayOffPtr = new PayOffDoubleDigital(LStrike,UStrike);
                break;
            
    }
    clock_t start, finish;
    start = clock();
    double result = SimpleMonteCarlo2(*thePayOffPtr,
                                      Expiry,
                                      Spot, 
                                      Vol,
                                      r,
                                      NumberOfPaths);
    finish = clock();
	
    cout <<"The time taken is " <<((double)(finish - start))/CLOCKS_PER_SEC << "\n";
    
    cout <<"\nthe price is " << result << "\n";
    double tmp;
    cin >> tmp;

    delete thePayOffPtr;

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

