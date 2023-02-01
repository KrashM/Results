#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;

int maxElement(int* arr, size_t size)
{
    int maxElem = arr[0];
    for (int i = 0; i < size; ++i) {
        if(arr[i] > maxElem)
        {
            maxElem = arr[i];
        }
    }
    return maxElem;
}
int minElement(int* arr, size_t size)
{
    int minElem = arr[0];
    for (int i = 0; i < size; ++i) {
        if(arr[i] < minElem)
        {
            minElem = arr[i];
        }
    }
    return minElem;
}

void pivot(int* arr, int x, size_t size)
{
    int min = minElement(arr,size);
    int max = maxElement(arr,size);
    size_t newSize = max - min + 2;
    int countingArray[newSize];
    for (int i = 0; i < newSize; ++i) {
        countingArray[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        countingArray[arr[i]]++;
    }
    for (int i = 0; i < newSize; ++i) {
        while(countingArray[i] != 0)
        {
            cout << i << " ";
            countingArray[i]--;
        }
    }
}

constexpr size_t TEST4 = 6;

int main() {
    int x = 7;
    int* input = new int[TEST4];
    for (int i = 0; i < TEST4; ++i) {
        cin >> input[i];
    }
    pivot(input,x,TEST4);
    return 0;
}
