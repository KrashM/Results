// 35т.
#include <iostream>

using std::cout;
using std::cin;

void enterArr(int arr[], unsigned int size) {

    for(unsigned int i = 0; i < size; i++) {

        cout << "Please enter array element # " << i + 1 << ": ";
        cin >> arr[i];

    }
}   

void printArr(int arr[], unsigned int size) {

    for(unsigned int i = 0; i < size; i++) cout << arr[i] << ' ';

}

void enterSize(int &n) {

    cout << "Please enter arr size: ";
    cin >> n;
    // Много интересна валидация с рекурсия.
    // Харесва ми имаш бонус точка!
    if(n <= 0) enterSize(n);
    
}

bool checkIfSawType1(int arr[], unsigned int size) {

    for(unsigned int i = 0; i < size - 1; i++) {

        // Проверява в зависимост от индекса

        if((i + 1) % 2 != 0) if(arr[i] >= arr[i + 1]) return false;
        if((i + 1) % 2 == 0) if(arr[i] <= arr[i + 1]) return false;

    }

    return true;
}

bool checkIfSawType2(int arr[], unsigned int size) {

    for(unsigned int i = 0; i < size - 1; i++) {

        // Проверява в зависимост от индекса

        if((i + 1) % 2 == 0) if(arr[i] >= arr[i + 1]) return false;
        if((i + 1) % 2 != 0) if(arr[i] <= arr[i + 1]) return false;

    }

    return true;
}

bool checkIfSaw(int arr[], unsigned int size) {

    return checkIfSawType1(arr, size) || checkIfSawType2(arr, size);
}

int main() {

    int n;
    enterSize(n);

    int arr[n];

    enterArr(arr, n);
    printArr(arr, n);
    cout << '\n';

    cout << std::boolalpha << checkIfSaw(arr, n);

    // {12, 0, 4, 3} Returns true;
    // {12, 0, 4, 9} Returns false;
    // {12, 18, 9, 17} Returns true;
    // {12, 4, 9, 17} Returns false;

    return 0;

}