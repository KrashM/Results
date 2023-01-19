// Доста сложно написано. Задачата търпи корекции.
// Използването на std::string е забранено.
// Не тръгва даже примера.
// 0т.
#include <iostream>
#include <cstring>

void sort(std::string arr[]) {

// Не се намира така размера на масив от тип string
int size = sizeof(arr);

// for (int i = 0; i < size; i++) {
//     for (int j = 0; j < size - 1 - i; j++) {
//         if (arr[j] < arr[j+1]) {
//             std::swap(arr[j], arr[j+1]);
//         }
//     }
// }

// Съвсем не се прави така сортировката
int k = 0;
for (int i = 0; i < size; i ++) {
    if (int(arr[i].at(k)) == int(arr[i+1].at(k))) {
        k++;
    } else {
        if (int(arr[i].at(k)) > int(arr[i+1].at(k))) {
        std::swap(arr[i], arr[i+1]);
    }
    }
}


for (int i = 0; i < size; i++) {
    std::cout << arr[i] << std::endl;
}

}

int main() { 

int n;
std::cout << "enter n: ";
std::cin >> n;
// Не може да се използва!!!
std::string strings[n];

// Проверка за n < 0?
if (n > 50) {
    std::cout << "Invalid input";
}

for (int i = 0; i < n; i++) {
    std::cout << "enter string " << i << std::endl;
    //std::cin.get(strings, 30);
    // Във всеки string въвеждаш по един символ.
    strings[i] = std::cin.get();
    //std::cin >> strings[i];
    std::cout << std::endl;    
    }

    sort(strings);

// for (int i = 0; i < n; i++) {
//     for (int j = 0; j < n - 1 - i; j++) {
//         if (strings[j] < strings[j+1]) {
//             std::swap(strings[j], strings[j+1]);
//         }
//     }
// }

// for (int i = 0; i < n; i++) {
//     std::cout << strings[i] << std::endl;
// }

return 0;

}



