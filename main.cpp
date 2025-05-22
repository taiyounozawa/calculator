#include <iostream>
#include <string>
#include <sstream>
#include "calc.cpp"

#include <map>
#include <functional>

using namespace std;

/**
 * @brief ���[�U�[����double�^�̐��l�����S�ɓ��͂�����֐�
 * ���l�ȊO�̓��͂��������ꍇ�A�G���[���b�Z�[�W��\�����ē��͂𑣂��B
 * @param prompt ���[�U�[�ɕ\������v�����v�g������
 * @return ���͂��ꂽ�L����double�^�̐��l
 */
double DetectNumber(const string& prompt)
{
    double value;
    string line;
    while(true) {
        cout << prompt;
        getline(cin, line);     // ��ɐV�����s��ǂݍ���

        stringstream ss(line);  // ��������X�g���[���Ƃ��Ĉ���
        ss >> value;            // stringstream����double�^�ւ̕ϊ������݂�

        // �ϊ����������A���Astringstream���I�[�ɒB���Ă��邩�`�F�b�N
        // ss�ɂ͐��l�݂̂����o����Ă���i�j
        if(ss && ss.eof()) {
            return value;   // �L���l��Ԃ� 
        } else {
            cout << "Error. Enter only number.";
        }
    }
}

string DetectOperator(const string& prompt)
{
    string op;
    string line;
    while(true) {
        cout << prompt;
        getline(cin, op);     // ��ɐV�����s��ǂݍ���

        // op�ɉ��Z�q���܂܂�Ă��邩�`�F�b�N
        // ���Z�q��+�A-�A*�A/�̂����ꂩ 
        if(op == "+" || op == "-" || op == "*" || op == "/") {
            return op;   // �L���l��Ԃ� 
        } else {
            cout << "Error. Enter only operator.";
        }
    }
}

int main()
{
    Calc calc;

    // ���Z�q�̓��͕ϐ�
    string op;

    // ���͕ϐ��̗p��
    int num1 = 0;
    int num2 = 0;
    
    // ���l�̓���1
    calc.SetFirstNum ( DetectNumber("Input num (1) : ") );

    // ���Z�q�̓���
    op = DetectOperator("Input operator (+, -, *, /) : ");

    // ���l�̓���2
    calc.SetSecoundNum ( DetectNumber("Input num (2) : ") );

    // ���Z�q�ƌv�Z�����̃}�b�s���O
    map<string, function<double()>> op_map = {
        {"+", [&](){ return calc.CalcSum(); }},
        {"-", [&](){ return calc.CalcMin(); }},
        {"*", [&](){ return calc.CalcMult(); }},
        {"/", [&](){ return calc.CalcDiv(); }}
    };

    cout << "Result: " << op_map[op]() << endl;

    return 0;
}