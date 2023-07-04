#include "iostream"
#include "Stack.h"
#include "Stack.cpp"
#include "cstring"
#include "cmath"

using namespace std;

void baseConversion();

void balancedExpression();

void infixToPostfix();

void evaluatePostfix();

int main() {
    int choice;
    do {
        cout << endl;
        cout << "--------------------------------------------------------";
        cout << endl << "Applications of Stack" << endl;
        cout << "--------------------------------------------------------";
        cout << endl << endl;

        cout << "1- Base Conversion" << endl;
        cout << "2- Balanced Expression" << endl;
        cout << "3- Infix to Postfix" << endl;
        cout << "4- Evaluate Postfix Expression" << endl;
        cout << "5- Exit..." << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                baseConversion();
                break;
            case 2:
                balancedExpression();
                break;
            case 3:
                infixToPostfix();
                break;
            case 4:
                evaluatePostfix();
                break;
            case 5:
                return -1;
            default:
                continue;
        }
    } while (choice != -1);
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
    cout << endl << "Enter expression without spaces:" << endl;
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
    string str;
    cout << endl << "Enter expression without spaces:" << endl;
    cin >> str;

    char expression[str.length() + 1];
    strcpy(expression, str.c_str());

    Stack<char> stack(str.length() + 1);

    string postfix = "";
    for (int i = 0; i < str.length() + 1; ++i) {
        if (expression[i] != '[' && expression[i] != '{' && expression[i] != '(' && expression[i] != ']' &&
            expression[i] != '}' && expression[i] != ')' && expression[i] != '+' && expression[i] != '-' &&
            expression[i] != '*' && expression[i] != '/' && expression[i] != '^') {
            postfix += expression[i];
            continue;
        }
        if (expression[i] == '[' || expression[i] == '{' || expression[i] == '(') {
            stack.push(expression[i]);
            continue;
        }
        if (expression[i] == ']' || expression[i] == '}' || expression[i] == ')') {
            char openingSymbol;

            if (expression[i] == ']')
                openingSymbol = '[';
            else if (expression[i] == '}')
                openingSymbol = '{';
            else
                openingSymbol = '(';

            char popValue = stack.pop();

            while (popValue != openingSymbol) {
                postfix += popValue;
                popValue = stack.pop();
            }
            continue;
        }
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' ||
            expression[i] == '^') {
            if (stack.isEmpty())
                stack.push(expression[i]);
            else {
                char popValue = stack.pop();
                switch (popValue) {
                    case '^':
                        postfix += popValue;
                        stack.push(expression[i]);
                        break;
                    case '/':
                        if (expression[i] == '^') {
                            stack.push(popValue);
                            stack.push(expression[i]);
                        } else {
                            postfix += popValue;
                            stack.push(expression[i]);
                        }
                        break;
                    case '*':
                        if (expression[i] == '^') {
                            stack.push(popValue);
                            stack.push(expression[i]);
                        } else {
                            postfix += popValue;
                            stack.push(expression[i]);
                        }
                        break;
                    case '+':
                        if (expression[i] == '^' || expression[i] == '/' || expression[i] == '*') {
                            stack.push(popValue);
                            stack.push(expression[i]);
                        } else {
                            postfix += popValue;
                            stack.push(expression[i]);
                        }
                        break;
                    case '-':
                        if (expression[i] == '^' || expression[i] == '/' || expression[i] == '*') {
                            stack.push(popValue);
                            stack.push(expression[i]);
                        } else {
                            postfix += popValue;
                            stack.push(expression[i]);
                        }
                        break;
                    default:
                        stack.push(popValue);
                        stack.push(expression[i]);
                        break;
                }
            }
            continue;
        }
    }
    if (!stack.isEmpty()) {
        for (int i = stack.getTOP(); i >= 0; --i) {
            postfix += stack.pop();
        }
        cout << endl << "Postfix Expression: " << postfix << endl;
    }
}

void evaluatePostfix() {
    string str;
    cout << endl << "Enter Single Digit expression without spaces seperated by ',' :" << endl;
    cin >> str;

    char expression[str.length() + 1];
    strcpy(expression, str.c_str());

    Stack<int> stack(str.length() + 1);

    for (int i = 0; i < str.length(); ++i) {
        if (expression[i] == ',' || expression[i] == '\n')
            continue;
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' ||
            expression[i] == '^') {
            if (stack.getTOP() > 0) {
                int first = stack.pop();
                int second = stack.pop();

                switch (expression[i]) {
                    case '^':
                        stack.push(pow(second, first));
                        break;
                    case '*':
                        stack.push(second * first);
                        break;
                    case '/':
                        stack.push(second / first);
                        break;
                    case '+':
                        stack.push(second + first);
                        break;
                    case '-':
                        stack.push(second - first);
                        break;
                }
            } else {
                cout << "Expression is not Valid!" << endl;
                return;
            }
        } else {
            stack.push((((int) expression[i]) - 48));
        }
    }
    if (stack.getTOP() > 0) {
        cout << "Expression is not Valid! " << endl;
    } else
        cout << "Answer is: " << stack.pop() << endl;
}