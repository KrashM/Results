// 34т.
#include <iostream>
#include <limits>
#include <cmath>

using std::cout;
using std::cin;

struct point{

    double x, y;
};

// За следващите две функции разликата винаги ще е положителна.
// abs е излишно.
double getHeight(double maxY, double minY) {

    // Side b

    return abs(maxY - minY);

}

double getLength(double maxX, double minX) {

    // Side a

    return abs(maxX - minX);

}

int main() {

    int n;
    cout << "Enter number of points: ";
    cin >> n;

    // Зануляването трябваше да го направиш с първият елемент от масива.
    // Това ще работи само за положителни max-ове.
    // А за double не съм сигурен дали няма по-големи стойности от INT_MAX, за които да се чупи това.
    double maxX = 0, minX = INT_MAX, maxY = 0, minY = INT_MAX;

    for(unsigned int i = 0; i < n * 2; i++) {

        point A;

        if(i % 2 == 0) {

            cout << "Enter X: ";
            cin >> A.x;

            if(A.x > maxX) maxX = A.x;
            if(A.x < minX) minX = A.x;
    
        }
        
        if(i % 2 != 0) {

            cout << "Enter Y: ";
            cin >> A.y;

            if(A.y > maxY) maxY = A.y;
            if(A.y < minY) minY = A.y;
            
        }
        
    }

    // cout << maxX << ' ' << minX << ' ' << maxY << ' ' << minY << '\n';

    cout << "Side a: " << getLength(maxX, minX) << '\n';
    cout << "Side b: " << getHeight(maxY, minY) << '\n';
    
    cout << "Upper-left corner: (" << minX << " , " << maxY << ")"; 


    return 0;
}