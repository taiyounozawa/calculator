#include <iostream>
#include <string>
#include <sstream>
#include "calc.cpp"

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

int main()
{
    Calc calc;

    // ���͕ϐ��̗p��
    int num1 = 0;
    int num2 = 0;
    
    // ���l�̓���
    calc.SetFirstNum ( DetectNumber("Input num (1) : ") );
    calc.SetSecoundNum ( DetectNumber("Input num (2) : ") );

    // ���͂��ꂽ���l�̕\��
    cout << "num (1) : " << calc.GetFirstNum() << endl;
    cout << "num (2) : " << calc.GetSecoundNum() << endl;
    
    return 0;
}