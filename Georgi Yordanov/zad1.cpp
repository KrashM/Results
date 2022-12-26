// 34т.
#include <iostream>

using std::cout;
using std::cin;

int myStrLen(char str[]) {

    int i = 0;

    while(str[i]) i++;

    return i;
}

int pow(int n, int p) {

    int res = 1;

    for(unsigned int i = 0; i < p; i++) res *= n;

    return res;
}

int convertToNum(char str[]) {
    
    int num = 0, length = myStrLen(str);

    for(unsigned int i = 0; i < length; i++) 
    num += (str[i] - '0') * pow(10, length - 1 - i);

    return num;
}

bool leq(char num1[], char num2[]) {

    if(convertToNum(num1) <= convertToNum(num2)) return true;

    return false;
}

int main() {

    // Липсват ти вход и валидация, инче топ!!
    char str[] = "6787";
    char str2[] = "6786";

    // cout << convertToNum(str);

    cout << std::boolalpha << leq(str, str2) << '\n'; // num1 > num2

    char str3[] = "6784";
    char str4[] = "6786";

    cout << std::boolalpha << leq(str3, str4) << '\n'; // num1 < num2

    char streq[] = "1234";
    char streq2[] = "1234";

    cout << std::boolalpha << leq(streq, streq2) << '\n'; // num1 = num2

    return 0;
}
