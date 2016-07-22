//
// Created by Owner on 7/21/2016.
//

#ifndef TRADERCS4398_INDICATOR_H
#define TRADERCS4398_INDICATOR_H
#include "Bar.h"
#include <vector>
namespace indicator{
    // Returns simple moving average based on close
    float sma(const std::vector<Bar>& series, int length, std::vector<Bar>::const_iterator end){
        float sum = 0;
		//replace with auto?
        for(std::vector<Bar>::const_iterator i = end; i != (end - length); --i){
            std::cout << end->close;
            sum += end->close;
        }
        sum = sum / length;
        return sum;
    }
    // Returns exponential moving average based on close
    //todo: implement this correctly
    float ema(const std::vector<Bar>& series, int length, std::vector<Bar>::const_iterator end){
        float sum = 0;
        for(std::vector<Bar>::const_iterator i = end; i != (end - length); --i){
            std::cout << end->close;
            sum += end->close;
        }
        sum = sum / length;
        return sum;
    }
}

#endif //TRADERCS4398_INDICATOR_H