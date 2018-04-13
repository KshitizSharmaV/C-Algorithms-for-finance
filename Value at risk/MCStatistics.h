//
//
//
//                      MCStatistics.h
//
//

#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>

class StatisticsMC
{
public:

    StatisticsMC(){}

    virtual void DumpOneResult(double result)=0;
    virtual void Second_Moment(double result)=0;
    virtual void Third_Fourth_Moment(double result)=0;
    virtual std::vector<std::vector<double> > GetResultsSoFar() const=0;
    virtual std::vector<std::vector<double> > GetSecondMomentResultsSoFar() const=0;
    virtual std::vector<std::vector<double> > GetThirdMomentResultsSoFar() const=0;
    virtual std::vector<std::vector<double> > GetForthMomentResultsSoFar() const=0;
    virtual StatisticsMC* clone() const=0;
    virtual ~StatisticsMC(){}

private:

};


class StatisticsMean : public StatisticsMC
{

public:

    StatisticsMean();
    virtual void DumpOneResult(double result);
    virtual void Second_Moment(double result);
    virtual void Third_Fourth_Moment(double result);
    virtual std::vector<std::vector<double> > GetResultsSoFar() const;
    virtual std::vector<std::vector<double> > GetSecondMomentResultsSoFar() const;
    virtual std::vector<std::vector<double> > GetThirdMomentResultsSoFar() const;
    virtual std::vector<std::vector<double> > GetForthMomentResultsSoFar() const;
    virtual StatisticsMC* clone() const;

private:

    double RunningSum;
    double RunningSumSquare;
    double RunningSumCube;
    double RunningSumFour;
    unsigned long PathsDone;
    unsigned long PathsDone2;

};

#endif

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

