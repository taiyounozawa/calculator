#ifndef _CALC_H_
#define _CALC_H_

class Calc{
private:
    double first_num;
    double secound_num;

public:
    double GetFirstNum();
    double GetSecoundNum();
    void SetFirstNum(double num1);
    void SetSecoundNum(double num2);

    double CalcSum();
    double CalcMin();
    double CalcMult();
    double CalcDiv();
};

# endif

//# pragma once