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
    double discounting = exp(-r.Integral(0,Expiry));
    vector<int> pays (NumberOfPaths);

    // Calculate first moment mean
	for (unsigned long i=0; i < NumberOfPaths; i++)
	{
		double thisGaussian = GetOneGaussianByBoxMuller();
		thisSpot = movedSpot*exp( rootVariance*thisGaussian);
		double thisPayOff = TheOption.OptionPayOff(thisSpot);
        pays[i]=thisPayOff*discounting;
        gatherer.DumpOneResult(pays[i]);
	}
    
    vector<vector<double> > results = gatherer.GetResultsSoFar();
    
    // With first moment calculating variance
    for (unsigned long i=0; i < NumberOfPaths; i++)
    {
        gatherer.Second_Moment(pays[i]-results[0][0]);
    }
    vector<vector<double> > results2 = gatherer.GetSecondMomentResultsSoFar();
    
    // With variance and mean calculating Skewness and kurtosis
    for (unsigned long i=0; i < NumberOfPaths; i++)
    {
        gatherer.Third_Fourth_Moment((pays[i]-results[0][0])/results2[0][0]);
    }
    
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


