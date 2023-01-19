// Overall добре написана, но има малки проблеми с логиката.
// 22т.
#include <iostream> 

const int SIZE = 1024;

int matches (int arr[][4], const int n) {

    int count = 0;

    for (size_t i = 0; i < n; i++) {
            
        // Липсват ти само равнотата.
        if (((arr[i][0] < arr[i][2]) && (arr[i][1] > arr[i][3])) || ((arr[i][0] > arr[i][2]) && (arr[i][1] < arr[i][3]))) {

            count++;
        }
    }

    return count;
}

bool validInput (int arr[][4], const int n, const int m) {

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {

            // Тука можеше да добавиш проверка и за прецакване на интервали.
            // Примерно 5 2.
            if (arr[i][j] < 0) {

                return false;
            }
        } 
    }
     
    return true;
}

int main () {

    // Тука трябваше да използваш динамичен масив.
    // Тъй като ти се въвежда размера.
    int arr[SIZE][4];

    int n, m = 4;
    std::cin >> n;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {

         std::cin >> arr[i][j];
        }
    }

    if (!validInput (arr, n, m)) {
        std::cout << "Invalid input!";
        return 1;
    }
    std::cout << matches(arr, n) << " pair/s overlaps.";

    return 0;

}