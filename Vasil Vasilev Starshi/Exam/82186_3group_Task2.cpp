#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;

constexpr size_t TEST2 = 4;

int* filter_evens(int* arr, unsigned int size)
{
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if(arr[i] % 2 == 0)
        {
            count++;
        }
    }
    int* resultArray = new int[count];
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if(arr[i] % 2 == 0)
        {
            resultArray[j++] = arr[i];
        }
    }
    return resultArray;
}

int main() {
/* TEST_CODE
    int* input = new int[TEST2];
    for (int i = 0; i < TEST2; ++i) {
        cin >> input[i];
    }
    int* res = filter_evens(input,TEST2);
    for (int i = 0; i < 2; ++i) {
        cout << res[i] << " ";
    }*/
    return 0;
}