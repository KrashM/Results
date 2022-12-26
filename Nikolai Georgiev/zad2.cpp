// 30т.
#include <iostream>
const std::size_t MAX_SIZE = 1000;

bool isHill(std::size_t n, unsigned* array){

    int biggestNum = array[0];
    int indexBiggestNum;

    // Хубаво е i и n да са от един тип за сравнението.
    for(int i = 1; i < n; i++){
        if(biggestNum < array[i]){
            biggestNum = array[i];
            indexBiggestNum = i;
        }
    }
    // От тук
    if(n == 2){
        if(biggestNum == array[0] && array[1] > biggestNum){
            return false;
        }
        else if(biggestNum == array[1] && array[0] > biggestNum){
            return false;
        }
    }
    // До тук не ти трябва.
    // Надолу кода ти покрива и тези случаи.
    for(int i = 0; i < indexBiggestNum; i++){
        if(array[i] > array[i+1]){
            return false;
        }
    }
    for(int i = indexBiggestNum; i < n-1; i++){
        if(array[i] < array[i+1]){
            return false;
        }
    }
    return true;
}

int main(){
    std::size_t n;
    std::cin >> n;
    // Нямаш валидация за n. Ако n >= 1000.

    // Това за следващото контролно ;)
    // unsigned* array = new unsigned[n];
    // for(int i = 0; i < n; i++){
    //     std::cin >> array[i];
    // }
    // for(int i = 0; i < n; i++){
    //     std::cout << array[i];
    // }
    //unsigned array[MAX_SIZE] = {1,21,1,21};
    unsigned array[MAX_SIZE];
    for(int i = 0; i < n; i++){
        std::cin >> array[i];
    }
    // for(int i = 0; i < n; i++){
    //     std::cout << array[i];
    // }
    std::cout << isHill(n, array);
    //delete[] array;
}