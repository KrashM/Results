// 0т.
#include <iostream>
using std::cin;
using std::cout;

void insertArr(double arr[], int n) {
    for (size_t i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void printArr(double arr[], int n) {
    for (size_t i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << std::endl;
}
int main(){
    int n;
    double arr[1024];
    cin >> n;
    insertArr(arr, 2*n);
    printArr(arr, 2*n);
    return 0;
}
