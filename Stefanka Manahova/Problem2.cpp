// 34т.
#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

bool trion (int* arr, const int &size) {
    int i = 0;
    bool inc;

    while (arr[i] == arr[i+1] && i < size - 1) {
        i++;
    }

    if (i == size - 1) {
        return true;
    }

    bool incr = arr[i] < arr[i+1];

    while (i < size - 1)
    {
        // Изпуснала си само равното и на двете места.
        if (incr && arr[i] > arr[i+1]) {
            return false;
        }

        else if (!incr && arr[i] < arr[i+1]) {
            return false;
        }

        i++;
        incr = !incr;
    }    

    return true;  

}


int main () {
    const size_t MAX_SIZE = 1024;

    int arr[MAX_SIZE];
    int n;

    do {
        cout << "Please enter n: ";
        cin >> n;
    } while (n <= 0 || n > MAX_SIZE);

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << std::boolalpha << trion(arr, n) << '\n';

    return 0;
}
