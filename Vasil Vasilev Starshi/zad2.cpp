#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;

constexpr int MAX_ARR_SIZE = 1024;

bool checkIfHill(int array[], size_t size)
{
    bool flag = false;
    // Хубаво е i и size да са от един и същи тип за сравнението.
    for (int i = 0; i < size-1; ++i) {
        // Липсва ти и равното.
        if(array[i] > array[i+1])
        {
            flag = true;
        }
        if(flag && array[i] < array[i+1])
        {
            flag = false;
            return flag;
        }
    }
    return flag;
}

int main() {
    size_t n;
    cin >> n;
    while(n < 1)
    {
        cout << "Please enter a valid N: ";
        cin >> n;
    }
    int array[MAX_ARR_SIZE];
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }
    cout << checkIfHill(array,n);
    return 0;
}