#include <iostream>

using std::nothrow;



void pivot (int *&arr, int &arrLength, int x) {

for (int i = 0; i < arrLength; i++) {

    if ((arr[i] > x) && (arr[i + 1] <= x)) {

        std::swap (arr[i], arr[i + 1]);
    }

}    

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

int x;

std::cin >> x;

int newArr = pivot(arr, n, x);

std::cout << newArr << std::endl;




delete[] arr;


return 0;
}