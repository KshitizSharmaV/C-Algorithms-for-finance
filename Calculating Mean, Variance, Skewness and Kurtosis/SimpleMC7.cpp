//
//
//
//                      SimpleMC7.cpp
//                         
//

#include <SimpleMC7.h>
#include <Random1.h>
#include <cmath>
#include<iostream>

// the basic math functions should be in namespace std but aren't in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

void SimpleMonteCarlo5(const VanillaOption& TheOption, 
						 double Spot, 
						 const Parameters& Vol, 
						 const Parameters& r, 
                         unsigned long NumberOfPaths,
						 StatisticsMC& gatherer)
{
    double Expiry = TheOption.GetExpiry();
	double variance = Vol.IntegralSquare(0,Expiry);
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5*variance;
	double movedSpot = Spot*exp(r.Integral(0,Expiry) +itoCorrection);
	double thisSpot;
    vector<int> prices (NumberOfPaths);

    // Monte Carlo Stimuation for calculating the futute stock prices
    for (unsigned long i=0; i < NumberOfPaths; i++)
	{
		double thisGaussian = GetOneGaussianByBoxMuller();
		thisSpot = movedSpot*exp( rootVariance*thisGaussian);
        prices[i]=thisSpot;
        
        // This function will be used to find the mean value of the log returns of stock prices
        gatherer.DumpOneResult(prices[i],Spot);
    }
    
    vector<vector<double> > results1 = gatherer.GetResultsSoFar();
    
    // This loop is to calculate the Variance for the returns of stock prices
    for (unsigned long i=0; i < NumberOfPaths; i++)
    {
        gatherer.Variance(prices[i]-Spot,results1[0][0]);
    }
    
    // Code for calculating the confidece level
    vector<vector<double> > results2 = gatherer.GetVarianceResultSoFar();
    double sd=sqrt(results2[0][0]);
    cout<<sd<<"\n";
    double v1= -1.65 * sd;
    double v2= -2.33 * sd;
    
    
    cout<<"95% confidence That company will not lose more than "<< v1<<"\n";
    cout<<"99% confidence That company will not lose more than "<< v2;
    return;
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


