//Задача 3. От стандартния вход се въвежда естественото число n, следвано от други 2 ✕ n на брой дробни числа
// (представени чрез тип double) x0, y0, x1, y1,…,xn-1, yn-1. Двойките (xi, yi) са декартови координати 
//на точки в евклидовата равнина. Да се намери правоъгълник с възможно най-малка площ, 
//чиито страни са успоредни на координатните оси и който съдържа всички въведени точки.
// Да се изведат на стандартния изход координатите на горния ляв ъгъл на правоъгълника и
// дължините на страните му. 

// Пример: За редицата от точки (0, 0), (-1, 0), (2, 1) програмата ще изведе -1 1 3 1.

// 10т.

#include <iostream> 

int main () {

    unsigned int SIZE = 1000;

    double arr [SIZE];

    int n;
    std::cin >> n;

    // n < 2? Валидация ти трябва.

    for (size_t i = 0; i < 2*n; i++)
    {
        std::cin >> arr[i];
    }

    //Ще работи само за положителни числа
    // Много правилна забележка!
    // Трябва да може да работи и с отрицателни.
    // За тази цел, като начална стойност слагаме първата от масива.

    double maxX1 = 0;

    for (size_t i = 0; i < 2*n; i++)
    {
        if (arr[2*i] > maxX1) maxX1 = arr[2*i];
    }

    double maxY1 = 0;
    for (size_t i = 0; i < 2 * n ; i++)
    {
        if (arr[2*i + 1] > maxY1) maxY1 = arr[2*i + 1];
    }

    // Това просто са ти най-големите координати.
    // Нищо общо с горен ляв ъгъл и страни.
    std::cout << "a = " << maxX1 << std::endl;
    std::cout << "b = " << maxY1 << std::endl;
    
    
    return 0;
}

//пуснах сълза за четящия това :(
// Аз пък се усмихвам XD