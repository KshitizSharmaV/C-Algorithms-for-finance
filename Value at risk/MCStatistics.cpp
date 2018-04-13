//
//
//
//                      MCStatistics.cpp
//
//

#include<MCStatistics.h>
#include<cmath>
using namespace std;

StatisticsMean::StatisticsMean()
    :
    RunningSum(0.0),RunningSumSquare(0.0),RunningSumCube(0.0),RunningSumFour(0.0),PathsDone(0UL),PathsDone2(0UL)
{
}
    
void StatisticsMean::DumpOneResult(double result)
{
    PathsDone++;
    RunningSum += result;
    
}

void StatisticsMean::Second_Moment(double result){
    if(result>0){
        RunningSumSquare += pow(result,2);
    }
}

void StatisticsMean::Third_Fourth_Moment(double result){
    if(result>0){
        RunningSumCube += pow(result,3);
        RunningSumFour += pow(result,4);
    }
}

vector<vector<double> > StatisticsMean::GetResultsSoFar() const
{
    vector<vector<double> > Results(1);
    
    Results[0].resize(1);
    Results[0][0] = RunningSum / PathsDone;
    
    return Results;
}

vector<vector<double> > StatisticsMean::GetSecondMomentResultsSoFar() const{
    vector<vector<double> > Results(1);
    Results[0].resize(1);
    Results[0][0] = RunningSumSquare / (PathsDone-1);
    return Results;
}

vector<vector<double> > StatisticsMean::GetThirdMomentResultsSoFar() const
{
    vector<vector<double> > Results(1);
    
    Results[0].resize(1);
    Results[0][0] = RunningSumCube / PathsDone;
    
    return Results;
}

vector<vector<double> > StatisticsMean::GetForthMomentResultsSoFar() const{
    
    vector<vector<double> > Results(1);
    
    Results[0].resize(1);
    Results[0][0] = RunningSumFour / PathsDone;
    
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

