// 34т.
#include <iostream>

using std::size_t;

const int SIZE = 100;

void readArray(int arr[], size_t n){

    for(size_t i = 0; i < n; ++i){

        std::cin >> arr[i];
    }
}

bool hill(int arr[], size_t n){

    bool flip = false;

    for(int i = 0; i < n - 2; i++){

        if(arr[i] <= arr[i+1] && arr[i+1] >= arr[i+2]){
            flip = true;
        }
        if(flip){

            if(arr[i+1] < arr[i+2])
            return false;
        } 
    }

    return flip;

}

int main(){

    int arr[SIZE];

    unsigned int n;
    std::cin >> n;
    if(n > 1000)
    return 1;

    readArray(arr, n);

    std::cout << std::boolalpha << hill(arr, n);
}