#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::size_t;

const int MAX_CAPACITY = 100;

void input(int arr[], size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}


bool trionArray(int arr[], size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        // Липсват равнота. Също така при първата срещната тройка казваме, че редицата е такава.
        // Нататък нещата може да се прецакват.
        if(arr[i] < arr[i + 1] && arr[i + 1] > arr[i + 2]) return true;
        else if(arr[i] > arr[i + 1] && arr[i + 1] < arr[i + 2]) return true;
        return false;
    }
    
}
int main()
{
    unsigned int n;
    int arr[MAX_CAPACITY];
    cin >> n;
    // Нямаш валидация на n. Ако n >= MAX_CAPACITY.
    input(arr, n);
    cout << std::boolalpha << trionArray(arr, n) << endl;
    return 0;
}