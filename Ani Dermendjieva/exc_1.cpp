// Задача 1. Да се дефинира функция bool leq ([подходящ тип] n1,  
//[подходящ тип] n2). n1 и n2 са две цели неотрицателни числа, 
//представени чрез символни низове, състоящи се от цифрите на числото (напр. “123”). 
//Функцията да връща истина тогава и само тогава, когато n1 ≤ n2.  
//Можете да приемете, че в представянето на числата няма водещи нули.

// 20т.

#include <iostream> 

 unsigned int strlen(const char str[]){

    unsigned int i = 0;
    while(str[i] != '\0') i++;    
    return i;

}

// Валиден подход за малки числа.
// Предпочита се директното сравняване на string-овете.
long long convertToNumber(const char str[]){

    long long num = 0;

    for(int i = 0; i < strlen(str); i++){

        num *= 10;
        num += str[i] - '0';

    }

    return num;

}

bool leq (char n1, char n2) {

    // Има малко по-компактен начин да се напише.
    // return n1 <= n2;
    if (n1 <= n2) return true;
    return false;
}
 
int main () {

    const int SIZE = 1024;
    
    char number1[SIZE];
    char number2[SIZE];

    std::cin.getline(number1, SIZE); // Обикновен cin върши работа.
    std::cin.getline(number2, SIZE); // Обикновен cin върши работа.

    convertToNumber(number1); // Къде пазим резултата?
    convertToNumber(number2); // Къде пазим резултата?

    // Предполагам че number1 и number2 си искала да ти бъдат long long числата.
    // В такъв случай схемата ти по-горе, няма как да ти върне отрицателно число.
    // И последно валидацията е хубаво да ти е веднага след като ги въведеш числата.
    if (number1 < 0 || number2 < 0) {
        std::cout << "Invalid input!";
        return 1;
    }

    // Тук ти се кара, защото не подаваш long long числата, ами char масивите.
    // Можеше да го пишеш:
    // leq(convertToNumber(number1), convertToNumber(number2));
    leq(number1, number2);
    // Това е невалидно.
    // Да викаш функция без аргументи.
    // Трябваше да вкараш отгоре функцията в cout-а.
    std::cout << std::boolalpha << leq;

    return 0;
}