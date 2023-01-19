// 30т.
#include <iostream>

int main() {

    // const нямаше да навреди ;).
    int MAX_NUM = 1000;

    int n;

    std::cin >> n;

    double coordinates[MAX_NUM], minX, minY, maxX, maxY;

    for(int i = 0; i < 2*n; i++) {
        std::cin >> coordinates[i];
    }

    minX = maxX = coordinates[0];
    minY = maxY = coordinates[1];

    for(int i = 0; i < 2*n; i += 2) {
        if(coordinates[i] < minX) {
            minX = coordinates[i];
        }
        if(coordinates[i] > maxX) {
            maxX = coordinates[i];
        }
    }

    for(int i = 1; i < 2*n; i += 2) {
        if(coordinates[i] < minY) {
            minY = coordinates[i];
        }
        if(coordinates[i] > maxY) {
            maxY = coordinates[i];
        }
    }

    // Тук ти трябва minX и maxY, защото искат горен ляв ъгъл.
    std::cout << minX << " " << minY << " " << maxX-minX << " " << maxY-minY << std::endl;

    return 0;
}
