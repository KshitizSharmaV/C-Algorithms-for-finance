//
//
//                          PayOff2.cpp
//
//


#include <PayOff2.h>
#include <minmax.h>
#include <cmath>

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_)
{
}

PayOffPut::PayOffPut(double Strike_) : Strike(Strike_)
{
}

PayOffDoubleDigital::PayOffDoubleDigital(double LowerLevel_, double UpperLevel_)
:   LowerLevel(LowerLevel_),
UpperLevel(UpperLevel_)
{
}

PayOffPowerCall::PayOffPowerCall(double Strike_, double Power_) : Strike(Strike_), Power(Power_)
{
}

PayOffPowerPut::PayOffPowerPut(double Strike_, double Power_) : Strike(Strike_), Power(Power_)
{
}



double PayOffCall::operator () (double Spot)
{   
    return max(Spot-Strike,0.0);
}


double PayOffPut::operator () (double Spot)
{
    return max(Strike-Spot,0.0);
}

double PayOffDoubleDigital::operator()(double Spot) 
{
    if (Spot <= LowerLevel)
        return 0;
    if (Spot >= UpperLevel)
        return 0;
    
    return 1;
}

double PayOffPowerCall::operator()(double Spot)
{
    return max(pow(Spot,Power)-Strike,0.0);
}

double PayOffPowerPut::operator()(double Spot)
{
    return max(Strike-pow(Spot,Power),0.0);
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

