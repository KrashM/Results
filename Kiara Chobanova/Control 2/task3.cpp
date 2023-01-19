// Задача 3. От стандартния вход се въвежда естественото число n,
// следвано от други 2 ✕ n на брой дробни числа (представени чрез тип double) x0, y0, x1, y1,…,xn-1, yn-1.
// Двойките (xi, yi) са декартови координати на точки в евклидовата равнина. 

// Да се намери правоъгълник с възможно най-малка площ, 
// чиито страни са успоредни на координатните оси и 
// който съдържа всички въведени точки.
// Да се изведат на стандартния изход координатите на горния ляв ъгъл на правоъгълника и дължините на страните му. 

// Пример: За редицата от точки (0, 0), (-1, 0), (2, 1) програмата ще изведе -1 1 3 1.

// 15т.

#include <iostream>

int min(int *array, const size_t& size){
    int min = array[0];
    for(int i = 1; i < size; ++i){
        if(array[i] < min){
            min = array[i];
        }
    }

    return min;
}

int max(int *array, const size_t& size){
    int max = array[0];
    for(int i = 1; i < size; ++i){
        if(array[i] > max){
            max = array[i];
        }
    }

    return max;
}

int main(){
    const size_t MAX = 1000;
     
    int n;
    std::cin >> n;
    // Проверка за n > MAX или n <= 0.

    unsigned int m = n*2, numberOfXes = 0, numberOfYes = 0;

    // Тази задача може да се реши и без да пазим точките в масив.
    // Типът на данните ти трябва да е double.
    // Може да ти се подаде точка p(1.24, 0.35) примерно.
    int arrayOfDoubles[MAX];
    int arrayOfXes[MAX];
    int arrayOfYes[MAX];

    for(int i = 0; i < m; ++i){
        // Много сложно да си ги въвеждаш всички двойки последователно в един масив.
        // Можеше просто да ги въвеждаш arrayOfXes[i] и arrayOfYes[i] заедно.
        std::cin >> arrayOfDoubles[i];
    }
    
    for(int i = 0, j = 1; i < m; i += 2, j += 2){
        arrayOfXes[numberOfXes] = arrayOfDoubles[i];
        arrayOfYes[numberOfYes] = arrayOfDoubles[j];
        numberOfXes++; // numberOfXes = n.
        numberOfYes++; // numberOfYes = n.
    }

    int coordinatesRac[2];
    coordinatesRac[0] = min(arrayOfXes, numberOfXes);
    coordinatesRac[1] = max(arrayOfYes, numberOfYes);

    // Грешно намираш страните.
    // Представяме си че минималният x е -5, а максималният е -3.
    // Разтоянието между двете точки е 2.
    // С твоята формула взимаме |-5| + |-3| = 8.
    // Същото важи и за y.
    int firstSide = abs(min(arrayOfXes, numberOfXes)) + abs(max(arrayOfXes, numberOfXes));
    int secondSide = abs(min(arrayOfYes, numberOfYes)) + abs(max(arrayOfYes, numberOfYes));

    std::cout << coordinatesRac[0] << " " << coordinatesRac[1] << " " << firstSide << " " << secondSide << "\n";

    return 0;
}