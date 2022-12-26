// 0т.
#include <iostream>

bool ed(int n) {
// "123"
    bool isEven = true;
    char number[255];

    int j = 0;
do {
    n %= 10; // Ако имаш числото n = 123, след този оператор n = 3. С две думи ще правиш само за една цифра тази операция.
    number[j] = n; // vzimame ostatuka i go dobavqme v niza
    j++;
} while (n / 10 != 0);

    for (int i = 0; i < j; i++){
        if ( number[i] % 2 != 0) {
            isEven = false; 
            break;
        }
    }
    return isEven;
}

int main () {
    
    bool result;
    // По условие числото ти се иска да се пази в string.
    // Тъй като може да е примерно 50/60/100 цифри.
    // Това не работи за int.
    int n;
    std::cout << "Enter n: " << std::endl;
    std::cin >> n; 
// 123
    // 
    
    result = ed(n);
    if (result == true) {
        std::cout << 1;
    } else {
        std::cout << 0;
    }

    return 0; 
    
}