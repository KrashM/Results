// 15т.
#include <iostream>

const std::size_t MAX_SIZE = 1000;

int area(std::size_t n, double array[MAX_SIZE][2]){

    int area = 1;

    double biggestX = array[0][0];
    double smallesX = array[0][0];

    double biggestY = array[0][1];
    double smallesY = array[0][1];

    // По дефиниция няма как да направиш квадрат от 1 точка.
    // От това => area = 0.
    if(n == 1){
        if(abs(biggestX) < abs(biggestY)){
            biggestX = biggestY;
        }
        while(1){
                if((area*area)/2 > biggestX){
                    return area*area;
                }
            area += 1;
        }
    }

    // Хубаво е i и n да са от един и същи тип за сравнението.
    for(int i = 1; i < n; i++){
        // Зашо ти е втория цикъл?!?
        for(int j = 0; j < 2; j++){

            if(biggestX < array[i][0]){
                biggestX = array[i][0];
            }
            if(biggestY < array[i][1]){
                biggestY = array[i][1];
            }
            if(smallesX > array[i][0]){
                smallesX = array[i][0];
            }
            if(smallesY > array[i][1]){
                smallesY = array[i][1];
            }
        }   
    }
    // Не се смятат така страните.
    // Ако имаш max = -3 и min = -5 => страната ти е с дължина 2.
    // Да обаче ти смяташ |-3| + |-5| = 8.
    // max - min ти върши работа.
    double biggestSum = abs(biggestX) + abs(smallesX);
    if(biggestSum < abs(biggestY) + abs(smallesY)){
        biggestSum = abs(biggestY) + abs(smallesY);
    }
    while(1){
        // Трябва ти корена от това нещо не да делиш на 2.
        // Плюс така смяташ само лице от страни с цели числа.
        // Има много проблеми с тази формула.
        // Просто си върни biggestSum * biggestSum.
        if((area*area)/2 > biggestSum){
            return area*area;
        }
        area += 1;
    }
}

int main(){

    std::size_t n;
    std::cin >> n;
    // Нямаш валидация за n. n >= 1000.

    double array[MAX_SIZE][2];

    for(int i = 0; i < n; i++){
        std::cin >> array[i][0];
        std::cin >> array[i][1];
    }
    
    std::cout << area(n, array);

    // for(int i = 0; i < n; i++){
    //     std::cout << array[i][0];
    //     std::cout << array[i][1];
    //     std::cout << '\n';
    // }
}