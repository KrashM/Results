// Overall very good.
// 24т.
#include <iostream>

unsigned int overlappedPairs(unsigned int pairCount){

    int pairOneFrom, pairOneTo, pairTwoFrom, pairTwoTo;

    unsigned int overlappedPairs = 0;

    for(int i = 0; i < pairCount; ++i){

        std::cin >> pairOneFrom >> pairOneTo >> pairTwoFrom >> pairTwoTo;

        // Нямаш валидация за отрицателни числа или за грешни интервали.

        if(pairOneFrom >= pairTwoFrom && pairOneTo <= pairTwoTo){
            overlappedPairs++;
        }else if(pairTwoFrom >= pairOneFrom && pairTwoTo <= pairOneTo){
            overlappedPairs++;
        }

    }
    return overlappedPairs;
}

int main(){

    unsigned int pairCount;
    std::cin >> pairCount;

    if(pairCount < 1)
    return 1;

    std::cout << "There are " << overlappedPairs(pairCount) << " overlapped pairs.";

}