#include <iostream>
#include <cstring>

using std :: cin;
using std :: cout;

bool leq(char n1[], char n2[], int sizeN1, int sizeN2);
int getNumVersionOfString(char string[], int size);
int getDigitVersionOfChar(char character);

int main() {
    // Липсват само вход и валидация.
    char text[] = {'1', '2'};
    char text2[] = {'3', '4', '5'};
    
    cout << leq(text, text2, sizeof(text), sizeof(text2));
}

bool leq(char n1[], char n2[], int sizeN1, int sizeN2){
    
    int firstNumber = getNumVersionOfString(n1, sizeN1);
    int secondNumber = getNumVersionOfString(n2, sizeN2);

    if(firstNumber <= secondNumber) return true;

    return false;
}

int getNumVersionOfString(char string1[], int size){
    
    int numberVersion = 0;

    for (int i = 0; i < size; i++)
    {
        numberVersion *= 10;
        numberVersion += getDigitVersionOfChar(string1[i]);
    }
    return numberVersion;
}

int getDigitVersionOfChar(char character){
    char asciOfOne = '1';
    // Можеше направо да пишеш character - '0' и си топ!
    int digit = (int) character - (int) asciOfOne + 1;

    return digit;
}