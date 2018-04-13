//
//
//
//                      MCStatistics.cpp
//
//

#include<MCStatistics.h>
#include<cmath>
#include<iostream>
using namespace std;

StatisticsMean::StatisticsMean()
    :
    RunningSum(0.0),PathsDone(0UL), RunningSumSquare(0.0)
{
}
    
void StatisticsMean::DumpOneResult(double price, double spot)
{
    PathsDone++;
    RunningSum += (price - spot);
    
}

void StatisticsMean::Variance(double r,double mreturn){
    double t=pow((r - mreturn),2);
    RunningSumSquare += t;
}



vector<vector<double> > StatisticsMean::GetResultsSoFar() const
{
    vector<vector<double> > Results(1);
    
    Results[0].resize(1);
    Results[0][0] = RunningSum / PathsDone;
    
    return Results;
}

vector<vector<double> > StatisticsMean::GetVarianceResultSoFar() const
{
    vector<vector<double> > Results(1);
    
    Results[0].resize(1);
    Results[0][0] = RunningSumSquare / (PathsDone-1);
    
    return Results;
}



StatisticsMC* StatisticsMean::clone() const
{
    return new StatisticsMean(*this);
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

