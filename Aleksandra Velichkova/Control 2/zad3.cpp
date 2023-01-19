// 0т.
#include <iostream>
#include <cmath>

const int SIZE = 1024;
struct Point
{
    double x, y;
};

double pSquare(double x) {
    // Търсим лице, не периметър.
    int p = 4*x;
    return p;
}



int main() {
    double arr[SIZE]; // масив, в който ще съхраняваме точките
    int n;
    std::cin >> n;
    // Това не е валидация.
    if(n <= 0) std::cout << "Enter number > 0!";

    Point a;
    Point temp;
    temp.x = 0; temp.y = 0;

    int k = 0;
    double maxX, maxY, maxD;
    double sum1 = 0, tempSum1 = 0, sum2 = 0, tempSum2 = 0; // за if *

    for (std::size_t i = 0; i < n; i++)
    {
        std::cin >> a.x >> a.y;
        // Честно да си призная от тук надолу няма нужда да го гледам.
        // Не работи с отрицателни числа, заради abs.
        if(abs(a.x) > abs(temp.x) && abs(a.x) > abs(maxX)){
             maxX = abs(a.x);
         } 
         if(abs(a.y) > abs(temp.y) && abs(a.y) > abs(maxY)) {
             maxY = abs(a.y);
         }

        // Не мога да разбера каква е логиката на всички тези променливи.
        if(a.x == temp.x){  // if *
            tempSum1 = sum1;
            sum1 = abs(a.y) + abs(temp.y);
            
            if(sum1 > tempSum1 && a.y <= maxY) {
                maxD = sum1;
            }
        }

        if(a.y == temp.y){  // if *
            tempSum2 = sum2;
            sum2 = abs(a.x) + abs(temp.y);
            
            if(sum2 > tempSum2 && a.x <= maxX) {
                maxD = sum2;
            }
        }

         temp = a;


    }
    
    std::cout << pSquare(2 * maxD);

    return 0;
}