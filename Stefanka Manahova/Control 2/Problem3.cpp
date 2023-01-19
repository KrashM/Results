// 34т.
#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

struct point {
    double x;
    double y;
};

double minX (point* arr, const int &size) {
    double minX = arr[0].x;

    for (size_t i = 1; i < size; i++)
    {
        if (arr[i].x < minX) {
            minX = arr[i].x;
        }
    }
    
    return minX;
}

double minY (point* arr, const int &size) {
    double minY = arr[0].y;

    for (size_t i = 1; i < size; i++)
    {
        if (arr[i].y < minY) {
            minY = arr[i].y;
        }
    }
    
    return minY;
}

double maxX (point* arr, const int &size) {
     double maxX = arr[0].x;

    for (size_t i = 1; i < size; i++)
    {
        if (arr[i].x > maxX) {
            maxX = arr[i].x;
        }
    }
    
    return maxX;
}

double maxY (point* arr, const int &size) {
    double maxY= arr[0].y;

    for (size_t i = 1; i < size; i++)
    {
        if (arr[i].y > maxY) {
            maxY= arr[i].y;
        }
    }
    
    return maxY;
}

int main () {
    const size_t MAX_SIZE = 1024;

    point arr[MAX_SIZE];
    int n;

    do {
        cout << "Please enter n: ";
        cin >> n;
        // Тук по дефиницията за правоъгълник ни тряват поне 2 точки
        // Тъй че търсим n >= 2 ;)
    } while (n <= 0 || n > MAX_SIZE);

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }

    point upperLeft;
    upperLeft.x = minX(arr, n);
    upperLeft.y = maxY(arr, n);

    double sideX = maxX(arr, n) - minX(arr, n);
    double sideY = maxY(arr, n) - minY(arr, n);

    cout << upperLeft.x << ' ' << upperLeft.y << ' ' << sideX << ' ' << sideY << '\n';
    return 0;
}