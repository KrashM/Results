#include <iostream>

struct int_array {
    int *arr;
    unsigned int size;
};

int* duplicate(int_array arr) {
    std::size_t newSize;
    int* newArray = new (std::nothrow) int[newSize];

for (int i = 0; i < arr.size; i++) {
    newArray[i+1] = arr.arr[i]; 
    newArray[i] = newArray[i+1];
      
     i++;
}

return newArray;

}

int main () {

int_array array;
array.arr;
array.size = 4;

for(int i = 0; i < array.size; i ++) {
    std::cin >> array.arr[i];
}


int* newArray = duplicate(array);

for (int i = 0; i < sizeof(newArray); i++) {
    std::cout << newArray[i] << " ";
}

return 0;


}