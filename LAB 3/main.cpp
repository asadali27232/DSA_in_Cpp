#include "iostream"
#include "Stack.h"
#include "Stack.cpp"
#include "cstring"

using namespace std;

void baseConversion();

void balancedExpression();

void infixToPostfix();

void evaluatePostfix();

int main() {
//    baseConversion();
    balancedExpression();
    return 0;
}

void baseConversion() {
    int number;
    int base;

    Stack<int> stack(100);

    cout << "Enter a Decimal Number:";
    cin >> number;
    cout << "Enter Output Base:";
    cin >> base;

    while (number > 0) {
        stack.push(number % base);
        number = number / base;
    }
    stack.print();
}

void balancedExpression() {
    string str;
    cout << "Enter expression without spaces:" << endl;
    cin >> str;

    char expression[str.length() + 1];
    strcpy(expression, str.c_str());

    Stack<char> stack(str.length() + 1);

    for (int i = 0; i < str.length() + 1; ++i) {
        if (expression[i] == '[' || expression[i] == '{' || expression[i] == '(' || expression[i] == ']' ||
            expression[i] == '}' || expression[i] == ')') {

            if (expression[i] == '[' || expression[i] == '{' || expression[i] == '(') {
                stack.push(expression[i]);
            } else if ((expression[i] == ']' || expression[i] == '}' || expression[i] == ')') && (!stack.isEmpty())) {
                char openingSymbol = stack.pop();
                char closingSymbol;

                if (openingSymbol == '[')
                    closingSymbol = ']';
                else if (openingSymbol == '{')
                    closingSymbol = '}';
                else
                    closingSymbol = ')';

                if (expression[i] != closingSymbol) {
                    cout << "Expression is not in Balanced form!" << endl;
                    return;
                }
            } else if ((expression[i] == ']' || expression[i] == '}' || expression[i] == ')') && (stack.isEmpty())) {
                cout << "Expression is not in Balanced form!" << endl;
                return;
            }
        }
    }
    if (stack.isEmpty())
        cout << "Expression is in Balanced form." << endl;
    else
        cout << "Expression is not in Balanced form!" << endl;
}

void infixToPostfix() {

}

void evaluatePostfix() {

}