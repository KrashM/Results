// 0т.
#include <iostream>

bool trion(unsigned int& n, int N[]);

const unsigned int MAX_SIZE = 1000;

int main() {

    unsigned int a;
    std::cin >> a;
    // Нямаш валидация за a. Ако въведа число >= 1000?

    int Array[MAX_SIZE] {0};

    for (size_t i = 0; i < a; i++)
    {
        std::cin >> Array[i];
    }
    
    trion(a,Array); // Защо го викаме втори път?

    std::cout <<std::boolalpha << trion(a,Array) << std::endl;

    return 0;
}

bool trion(unsigned int& n, int N[]) {

    // Нека не бъркаме типовете.
    // n -> unsigned int
    // i -> size_t
    // Хубаво е и двете да са от един тип за сравняването.
    for (size_t i = 0; i < n; i++)
    {   
        // При i = n - 1 => i + 1 = n, i + 2 = n + 1 => Влизаме в памет, в която не трябва.
        // Това условие е валидно само за единия вариант на триона.
        // Също така ти след като провериш първите 3 стойност приключваш функцията връщайки стойност.
        // Дефакто ако имаме редицата 1 3 2 5 6 7 8 9 10 ти ще кажеш че е валидна.
        if(N[i] <= N[i+1] && N[i+1] >= N[i+2]) {
             return true ;
        }
        else if(N[i] >= N[i+1] && N[i+1] <= N[i+2]) {
             return true ;
        }
        else {
            return false;
        }
    }

    std::cout << std::endl; // Ненужно.
    
    return false; // Ненужно. Винаги ще върнем нещо горе от цикъла.
}