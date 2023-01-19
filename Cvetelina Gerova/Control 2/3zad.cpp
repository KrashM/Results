// 30т.
#include <iostream> 

int main () {

    int n;
    std::cout << "enter n :" << std::endl;
    std::cin >> n;
    // Нямаш валидация за n. n <= 1 или n >= 1000.

    double side;
    
    double arrX[1000]; 
    double arrY[1000];
    for (int i = 0; i < n; i++) {
        std::cout << "enter x[" << i << "]";
        std::cin >> arrX[i];
        std::cout << "enter y[" << i << "]";
        std::cin >> arrY[i];
    }
double maxX = arrX[0], minX = arrX[0];
double maxY = arrY[0], minY = arrY[0];

    for (int i = 0; i <  n; i++) {
        if (arrX[i] > maxX) {
            maxX = arrX[i];
        } else if (arrX[i] < minX) {
            minX = arrX[i];
    }
    }

    // Тези два for-а можеш да ги обединиш.
    for (int i = 0; i <  n; i++) {
        if (arrY[i] > maxY) {
            maxY = arrY[i];
        } else if (arrY[i] < minY) {
            minY = arrY[i];
    }
    }

    if (minX < 0) {
        minX = - minX;
    }
    if (minY < 0) {
        minY = - minX;
    }

    if ((minX + maxX) > (minY + maxY)) {
        side = minX + maxX;
    } else {
        side = minY + maxY;
    }

std::cout << side*side; 

return 0;
}