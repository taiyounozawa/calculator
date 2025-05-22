#include <iostream>
#include <string>
#include <sstream>
#include "calc.cpp"

#include <map>
#include <functional>

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

string DetectOperator(const string& prompt)
{
    string op;
    string line;
    while(true) {
        cout << prompt;
        getline(cin, op);     // 常に新しい行を読み込む

        // opに演算子が含まれているかチェック
        // 演算子は+、-、*、/のいずれか 
        if(op == "+" || op == "-" || op == "*" || op == "/") {
            return op;   // 有効値を返す 
        } else {
            cout << "Error. Enter only operator.";
        }
    }
}

int main()
{
    Calc calc;

    // 演算子の入力変数
    string op;

    // 入力変数の用意
    int num1 = 0;
    int num2 = 0;
    
    // 数値の入力1
    calc.SetFirstNum ( DetectNumber("Input num (1) : ") );

    // 演算子の入力
    op = DetectOperator("Input operator (+, -, *, /) : ");

    // 数値の入力2
    calc.SetSecoundNum ( DetectNumber("Input num (2) : ") );

    // 演算子と計算処理のマッピング
    map<string, function<double()>> op_map = {
        {"+", [&](){ return calc.CalcSum(); }},
        {"-", [&](){ return calc.CalcMin(); }},
        {"*", [&](){ return calc.CalcMult(); }},
        {"/", [&](){ return calc.CalcDiv(); }}
    };

    cout << "Result: " << op_map[op]() << endl;

    return 0;
}