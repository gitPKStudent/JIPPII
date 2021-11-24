//
// Created by mik15 on 15.10.2021.
//

#ifndef SIMPLECALC_UTILS_H
#define SIMPLECALC_UTILS_H
#include "common.h"
/*
    return true if char is a digit or '.'
*/
bool isDigitOrDot(char c);
bool isNumber(char* str);
bool isOperator(char * str);
void error();
#endif //SIMPLECALC_UTILS_H
