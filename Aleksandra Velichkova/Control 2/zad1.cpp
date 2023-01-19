// 0т.
#include <iostream>

const int SIZE = 1024;

// Подхода е верен, но работи само за малки числа.
// Предпочита се директното обхождане на string-а.
int createNum(char arr[]){
    int n = 0;
    for (std::size_t i = 0; arr[i] != '\0'; i++)
    {
        n *= 10;
        n += arr[i] - '0';
    }

    return n;
}

bool ed(int n) {
    while(n > 0) {
        // Ако се дели на 2 сме проверили само последната цифра, не трябва да връщаме все още.
        if(n % 2 == 0) {
            return true;
        } else {
            return false;
            break; // Това е излишно, няма да се достигне, заради return-а.
        }
        n /= 10; // Това никога няма да го достигнем.
    }
}

int main() {
    char arr[SIZE];
    int n = 0; // Излишно.
    std::cout << "Enter your number: ";
    // Можеш с един прост cin да си го въведеш.
    std::cin.getline(arr, SIZE);
    // Валидацията е хубаво да се отдели тук.

    for (std::size_t i = 0; arr[i] != '\0'; i++)
    {
        if((arr[i] >= '0' && arr[i] <= '9')) {
            if(arr[0] == '0') std::cout << "Enter valid starting number";
            n = createNum(arr);
        } else {
            // Влизайки тук сме разбрали, че в string-а има други неща освен цифри.
            // Все пак продължаваме до функцията ed(ред 52) след това.
            std::cout << "Enter only numbers ";
            break;
        }
    }

    std::cout << std::boolalpha << ed(n);

    return 0;
}