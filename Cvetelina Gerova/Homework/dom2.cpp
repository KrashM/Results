// Като цяло доста добре разписана.
// Малки корекции.
// 22т.
#include <iostream>

int main() {
     
    int n;
    std::cout << "enter n: ";
    std::cin >> n;

    // Защо double? Числата са ти цели.
    double currSum = 0;
    double maxSum = 100; // Защо = 100? Може макса да е по-малък. По-добре 0.
    int portions;
    int calories;
    int maxIndex = 0;

    // n < 0?
    if (n > 100) {
        std::cout << "Invalid input";
        // Тук трябва да приключиш програмата.
        // Иначе си продължава с грешния вход.
    }

for (int i = 0; i < n; i++) {
    std::cout << "enter number of portions: ";
    std::cin >> portions;
    if(portions > 20) {
        std::cout << "Invalid output";
        break; // Тук имаме същият проблем не приключваме програмата.
    } else {
        std::cout << "enter the calories: ";
        for (int j = 0; j < portions; j ++) {
            std::cin >> calories;
            currSum += calories;
            calories = 0;
            // Няма нужда от това, ние така или иначе вкарваме,
            // нова стойност на следващата врътка.
        }
        if (currSum > maxSum) {
            maxSum = currSum;
            maxIndex = i;
        }
        currSum = 0;
    }
}

std::cout << "Elf " << maxIndex << ": " << maxSum << " calories"; 

return 0;

}