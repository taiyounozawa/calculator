# include "calc.h"

double Calc::GetFirstNum()
{
    return first_num;
}

double Calc::GetSecoundNum()
{
    return secound_num;
}

void Calc::SetFirstNum(double num1)
{
    first_num = num1;
}

void Calc::SetSecoundNum(double num2)
{
    secound_num = num2;
}

double Calc::CalcSum()
{
    return this->GetFirstNum() + this->GetSecoundNum();
}

double Calc::CalcMin()
{
    return this->GetFirstNum() - this->GetSecoundNum();
}

double Calc::CalcMult()
{
    return this->GetFirstNum() * this->GetSecoundNum();
}

double Calc::CalcDiv()
{
    return this->GetFirstNum() / this->GetSecoundNum();
}