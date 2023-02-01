#include <iostream>

int* createArray(std::size_t n) {

int* result = new (std::nothrow) int[n];
if(!result) {
    return nullptr;
}
return result;

}

void readArray(int* array, std::size_t n){

for (std::size_t i = 0; i < n; i++) {
    std::cin >> array[i];
}

}

void printArray(int* array, std::size_t n){
    for (std::size_t i = 0; i < n; i++) {
    std::cout << array[i] << " ";
}
}

void shift_left (int* array, unsigned int n) {
// 1234567 -> 4567123
int k = sizeof(array);
int* newArray = new(std::nothrow) int[n];
for (std::size_t i = 0; i < n; i++) { 
    newArray[i] = array[i];
} 
//printArray(newArray, n);

for (std::size_t i = 0; i < n; i++) { 
    array[i] = array[i+n];
}
printArray(array, k);

std::cout << std::endl;

for (std::size_t i = 0; i < n; i++) { 
    array[i+n+1] = newArray[i];
}

printArray(newArray, n);

std::cout << std::endl;

printArray(array, k);
 
}



int main() {

int size, n;
std::cin >> size;
std::cout << std::endl;
std::cin>> n;

int* array = createArray(size);
readArray(array, size);
printArray(array, size);
shift_left(array, n);

//printArray(array, size);

return 0;

}