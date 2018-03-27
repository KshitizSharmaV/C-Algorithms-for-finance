//
//
//
//                  PayOff1.cpp
//
//

double thepayoff(double Spot,double LStrike,double UStrike){
    if(Spot >= LStrike && Spot<= UStrike){
        return 1.0;
    }
    else{
        return 0.0;
    }
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

