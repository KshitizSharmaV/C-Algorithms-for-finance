//
//
//		StatsMain1.cpp
//
//       
//
/*
 uses source files 
    MCStatistics.cpp,
    Parameters.cpp,
    PayOff3.cpp, 
    PayOffBridge.cpp,
    Random1.cpp, 
    SimpleMC7.cpp, 
    Vanilla3.cpp,    
  */
#include<SimpleMC7.h>
#include<iostream>
using namespace std;
#include<Vanilla3.h>
#include<MCStatistics.h>

int main()
{

	double Expiry;
	double Strike; 
	double Spot; 
	double Vol; 
	double r; 
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nStrike\n";
	cin >> Strike;

	cout << "\nEnter spot\n";
	cin >> Spot;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nr\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

    PayOffCall thePayOff(Strike);

    VanillaOption theOption(thePayOff, Expiry);

    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);

    StatisticsMean gatherer;

	SimpleMonteCarlo5(theOption,
                                      Spot, 
                                      VolParam,
                                      rParam,
                                      NumberOfPaths,
                                      gatherer);

    vector<vector<double> > results = gatherer.GetResultsSoFar();
    cout<<"\n Mean is ";
    cout << results[0][0];
    
    vector<vector<double> > results2 = gatherer.GetSecondMomentResultsSoFar();
    cout<<"\n Variance ";
    cout << results2[0][0];
    
    vector<vector<double> > results3 = gatherer.GetThirdMomentResultsSoFar();
    cout<<"\n Skewness ";
    cout << results3[0][0];
    
    vector<vector<double> > results4 = gatherer.GetForthMomentResultsSoFar();
    cout<<"\n Kurtosis ";
    cout << results4[0][0]-3;
    
    
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

