// 30т.
#include <iostream>

const int SIZE = 1024;

int findMaxNum(int arr[], int n){
    int max = arr[0];
    int index = 0;

    // Нека не объркваме типовете.
    // Ако имаме n -> int, нека и i -> int.
    // Ако имаме n -> size_t, тогава да имаме и i -> size_t.
    for (std::size_t i = 0; i < n; i++)
    {
        if(arr[i] > max) 
        {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

bool checkIncreaseThenDecrease (int arr[], int n, int index){
    bool check = false;
    // Същият проблем с типовете, както по-горе.
    for (std::size_t i = 1; i < index; i++)
    {
        // Внимавай с това i - 1 при size_t тип, за да не превъртиш.
        if(arr[i - 1] <= arr[i]) check = true;
        else 
        {
            check = false;
            break;
        }
    }

    // Малко по-приличен начин да се напишат проверките по-долу.
    // if(!check) return false;

    if(check == true) {
        for (std::size_t i = index; i < n - 1; i++)
        {
            if(arr[i] >= arr[i + 1]) check = true;
            else 
            {
                // Тук направо можеш да връщаш false.
                check = false;
                break;
            }
        }
        
    } else return false;

    return check;
    
}
int main() {
    int arr[SIZE];
    int n;

    std::cout << "Enter n: " << '\n';
    std::cin >> n;

    // Това само ни казва да вкараме по-голямо от 0.
    // А къде трябва да го вкараме след това?
    // Ние си продължаваме нататък.
    if(n <= 0) std::cout << "Enter number > 0: "; // А какво ако n > 1024?

    std::cout << "Enter " << n << " numbers: " << '\n';
    for (std::size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int maxIndex = findMaxNum(arr, n);

    std::cout << std::boolalpha << checkIncreaseThenDecrease(arr, n, maxIndex);
    
    return 0;
}