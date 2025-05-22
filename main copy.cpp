#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 入力変数の用意
    int num1 = 0;
    int num2 = 0;
    
    // 数値の入力
    cout << "input num (1) : ";
    cin >> num1;
    cout << "input num (2) : ";
    cin >> num2;

    // 入力された数値の表示
    cout << num1 << " " << num2 << endl;
    
    return 0;
}