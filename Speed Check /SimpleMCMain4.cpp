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
    double Power;
    double S1,S2,S3;
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
    cout << "\nenter 3 for Power call, 4 for Power put";
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
            case 3:
                cout << "\nEnter strike for Power Call\n";
                cin >> Strike;
            cout << "\n Enter the power \n";
                cin >> Power;
                thePayOffPtr = new PayOffPowerCall(Strike, Power);
                break;
            case 4:
                cout << "\nEnter strike for Power Put\n";
                cin >> Strike;
                cout << "\n Enter the power \n";
                cin >> Power;
                thePayOffPtr = new PayOffPowerPut(Strike, Power);
                break;
    }
    
    
    double result = SimpleMonteCarlo2(*thePayOffPtr,
                                      Expiry,
                                      Spot, 
                                      Vol,
                                      r,
                                      NumberOfPaths);
    
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

