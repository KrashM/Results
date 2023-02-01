#include <iostream>

using std::nothrow;
const int MAXSIZE = 1024;



int filterEvens (int *&arr, int &arrLength) {

    int *newArr = new(nothrow) int[arrLength];

    for (int i = 0; i < arrLength; i++) {
        if (arr[i] % 2 == 0) {
            newArr [i] = arr [i];
        }
    }
        delete[] newArr;
    return *newArr;

}

int main () {

int n;

std::cin >> n;

int *arr = new(nothrow) int[n];

if(!arr) return 1;

for (int i = 0; i < n; i ++)
    {
        std::cin >> arr[i];
    }

    std::cout << filterEvens(arr, n) << std::endl;

    delete[] arr;


    return 0;
}