//
//  BeatNum.h
//  barrage
//
//  Created by luleyan on 15/5/23.
//
//

#ifndef __barrage__BeatNum__
#define __barrage__BeatNum__

struct BeatNum
{
    char numerator;
    char denominator;
    short num;
    
    //6又四分之三排分别输入6，3，4
    BeatNum(short n, char numerator = 0, char denominator = 0);
};

#endif /* defined(__barrage__BeatNum__) */
