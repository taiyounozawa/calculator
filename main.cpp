#include <iostream>
#include <string>
#include <sstream>
#include "calc.cpp"

using namespace std;

/**
 * @brief ユーザーからdouble型の数値を安全に入力させる関数
 * 数値以外の入力があった場合、エラーメッセージを表示し再入力を促す。
 * @param prompt ユーザーに表示するプロンプト文字列
 * @return 入力された有効なdouble型の数値
 */
double DetectNumber(const string& prompt)
{
    double value;
    string line;
    while(true) {
        cout << prompt;
        getline(cin, line);     // 常に新しい行を読み込む

        stringstream ss(line);  // 文字列をストリームとして扱う
        ss >> value;            // stringstreamからdouble型への変換を試みる

        // 変換が成功し、かつ、stringstreamが終端に達しているかチェック
        // ssには数値のみが抽出されている（）
        if(ss && ss.eof()) {
            return value;   // 有効値を返す 
        } else {
            cout << "Error. Enter only number.";
        }
    }
}

int main()
{
    Calc calc;

    // 入力変数の用意
    int num1 = 0;
    int num2 = 0;
    
    // 数値の入力
    calc.SetFirstNum ( DetectNumber("Input num (1) : ") );
    calc.SetSecoundNum ( DetectNumber("Input num (2) : ") );

    // 入力された数値の表示
    cout << "num (1) : " << calc.GetFirstNum() << endl;
    cout << "num (2) : " << calc.GetSecoundNum() << endl;
    
    return 0;
}