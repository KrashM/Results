#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;

constexpr int MAX_ARR_SIZE = 512;

int main() {
    int n;
    cin >> n;
    // Трябва да ти е n < 2.
    // Защото по дефиниция, няма как да направиш квадрат с 1 точка.
    while(n < 1 || n > 512)
    {
        cout << "Please enter a valid N: ";
        cin >> n;
    }
    double x[MAX_ARR_SIZE];
    double y[MAX_ARR_SIZE];
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i]; 
    }
    double xDiff;
    double yDiff;
    double minX = x[0], maxX = x[0];
    for (int i = 1; i < n; ++i) {
        if(x[i] > maxX)
        {
            maxX = x[i];
        }
        if(x[i] < minX)
        {
            minX = x[i];
        }
    }
    xDiff = abs(maxX - minX); // Нямаш нужда от abs, защото разликата винаги ще е положителна.
    double minY = y[0], maxY = y[0];
    for (int i = 1; i < n; ++i) {
        if(y[i] > maxY)
        {
            maxY = y[i];
        }
        if(y[i] < minY)
        {
            minY = y[i];
        }
    }
    yDiff = abs(maxY - minY); // Същата логика и тук, няма нужда от abs.
    if(xDiff > yDiff)
    {
        cout << xDiff*xDiff;
    }
    else{
        cout << yDiff * yDiff;
    }
    return 0;
}