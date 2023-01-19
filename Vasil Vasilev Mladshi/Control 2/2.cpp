#include <iostream>

using std :: cin;
using std :: cout;

bool checkIfSaw(int arr[], int size);

int main (){

    int arr[1000];
    int n;

    cout << "Input n: ";
    cin >> n;
    cout << std :: endl;
    
    // Проверка за n? n < 0 || n >= 1000.

    for (int i = 0; i < n; i++)
    {
        cout << "Input element number " << i + 1 << " of the array: ";
        cin >> arr[i];
        cout << std :: endl;
    }
    
    if(checkIfSaw(arr, n)) cout << "It is";
    else cout << "It is not";
}

bool checkIfSaw(int arr[], int size) {

    int counter = 2;

    for (int i = 1; i < size - 1; i++)
    {
        if(arr[0] <= arr[1]){
            if(counter % 2 == 0){
                if (!(arr[i] >= arr[i+1])) return false;
            }
            else
            {
                if(!(arr[i] <= arr[i+1])) return false;
            }
            
        }
        else if (arr[0] >= arr[1]){
            if(counter % 2 == 0){
                if (!(arr[i] <= arr[i+1])) return false;
            }
            else
            {
                if(!(arr[i] >= arr[i+1])) return false;
            }
        }
        counter ++;
    }
    return true;
}