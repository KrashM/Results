// Задача 1. Да се дефинира функция bool leq ([подходящ тип] n1,  [подходящ тип] n2). 
// n1 и n2 са две цели неотрицателни числа, представени чрез символни низове, състоящи се от цифрите на числото (напр. “123”).
// Функцията да връща истина тогава и само тогава, когато n1 ≤ n2.  
// Можете да приемете, че в представянето на числата няма водещи нули.

// 30т.

#include <iostream>

unsigned int convertToNumber(char* str){
    unsigned int result = 0;

    for(int i = 0; str[i] != '\0'; ++i){
        result *= 10;
        result += str[i] - '0';
    }

    return result;
}

// Този подход е верен, но работи само за малки числа.
// Предпочита се директното сравняване на string-овете.
bool leq(char* n1, char* n2){
    unsigned int number1 = convertToNumber(n1);
    unsigned int number2 = convertToNumber(n2);

    return number1 <= number2;
}

int main(){

    const size_t MAX = 254;

    char n1[MAX], n2[MAX];
    std::cin >> n1 >> n2;
    // Нямаме валидация за числата.

    std::cout << leq(n1, n2);

    return 0;
}