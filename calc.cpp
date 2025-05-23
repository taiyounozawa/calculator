# include "calc.h"
#include <stdexcept>
using namespace std;

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
    try{
        // 0‚ÅŠ„‚éê‡‚Ì—áŠOˆ—
        if (this->GetSecoundNum() == 0) {
            throw invalid_argument("Division by zero is not allowed.");
        }
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        exit(0); // —áŠO‚ª”­¶‚µ‚½ê‡‚Í0‚ð•Ô‚·
    }

    return this->GetFirstNum() / this->GetSecoundNum();
}