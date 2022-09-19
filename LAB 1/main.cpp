#include <iostream>

using namespace std;

void Factorial();

void Fibonacci();

void GCD();

void LCM();

int gcd(int num1, int num2);

void reverse();

void digits();

int main() {

    int choice;
    do {
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "1 - Factorial" << endl;
        cout << "2 - Fibonacci" << endl;
        cout << "3 - GCD" << endl;
        cout << "4 - LCM" << endl;
        cout << "5 - Reverse" << endl;
        cout << "6 - Number of digits" << endl;
        cout << "0 - Exit" << endl;


        cin >> choice;

        switch (choice) {
            case 1:
                Factorial();
                break;
            case 2:
                Fibonacci();
                break;
            case 3:
                GCD();
                break;
            case 4:
                LCM();
                break;
            case 5:
                reverse();
                break;
            case 6:
                digits();
                break;
        }

    } while (choice != 0);

    return 0;
}

void Factorial() {
    cout << "Enter a number to find Factorial:";
    int num;
    cin >> num;

    int fact = 1;
    for (int i = 1; i <= num; i++) {
        fact = fact * i;
    }
    cout << "Factorial of " << num << " is" << fact << endl;
}

void Fibonacci() {
    int t1 = 0;
    int t2 = 1;
    int nextTerm = 0;
    int till;

    cout << "Enter a number of terms you want:";
    cin >> till;

    cout << "Fibonacci Series is:" << endl;
    cout << t1 << " " << t2 << " ";

    for (int i = 0; i < till; i++) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        cout << nextTerm << " ";
    }
}

void GCD() {
    int num1;
    int num2;
    int g;

    cout << "Enter First Number :";
    cin >> num1;
    cout << "Enter Second Number :";
    cin >> num2;

    g = gcd(num1, num2);
    cout << "Greatest common divisor is:" << g << endl;
}

int gcd(int num1, int num2) {
    int g;
    for (int i = 1; i <= (num1 > num2 ? num1 : num2); ++i) {
        if (num1 % i == 0 && num2 % i == 0)
            g = i;
    }
    return g;
}

void LCM() {
    int num1;
    int num2;
    int lcm;

    cout << "Enter First Number :";
    cin >> num1;
    cout << "Enter Second Number :";
    cin >> num2;

    lcm = (num1 * num2) / gcd(num1, num2);

    cout << "Least common factor is:" << lcm << endl;
}

void reverse() {
    cout << "Enter a number to find Reverse:";
    int num;
    cin >> num;

    string strNum = to_string(num);
    char strRev[100000];

    for (int i = 0; i < strNum.length(); ++i) {
        strRev[i] = strNum[(strNum.length()-1) - i];
    }

    cout << "Reverse of given number is: " << strRev;
}

void digits() {
    cout << "Enter a number to find Reverse:";
    int num;
    cin >> num;

    cout << "Number of digits: " << to_string(num).length();
}