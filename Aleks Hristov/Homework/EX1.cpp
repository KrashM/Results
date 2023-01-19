// 20т.
#include <iostream>


using std::size_t;


bool Catch2(size_t **matrix, int i, int j){
    try {
        if ((j == 1 || j == 3) && matrix[i][j] <= matrix[i][j - 1]) {
            throw matrix[i][j];
        }
    }
    catch (...) {
        std::cout << "Wrong Input! Please start over.";
        return true;
    }
    return false;
}


int Pairs(size_t **matrix,const size_t n){
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (matrix[i][0] <= matrix[i][2] && matrix[i][1] >= matrix[i][3]) count++;
        else if (matrix[i][0] >= matrix[i][2] && matrix[i][1] <= matrix[i][3]) count++;
    }
    return count;
}




int main() {
    unsigned int a, b = 4;
    std::cin >> a;
    auto **matrix = new size_t *[a];


    for (int i = 0; i < a; i++) matrix[i] = new size_t[b];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            std::cin >> matrix[i][j];
            if (Catch2(matrix, i, j)==true) return 1; // Memory leak!!
        }
    }

   std::cout << Pairs(matrix, a);


    for (int i=0; i<a; i++) delete[] matrix[i];
    delete[] matrix;

    return 0;
}

// Никъде в условието не пишеше, че трябва да има лимит, колко секции един елф може да бъде назначен и затова и аз ги
// оставих без ограничение. Също не разбрах дали трябва да се потвърди, че входът от потребителя е правилен и затова
// сложих exception, който терминира програмата ако е грешен, а за грешен подразбирам да не е число или да въвежда
// секциите в обратен ред, тоест от по-голямото число към по-малкото. Единственото, за което много се двоумях
// (освен как да напиша exception-а) е дали два елфа могат да имат напълно съвпадащи секции (тоест дали да
// го оставя като допустим вход от потребителя или не), но накрая го оставих, защото реално те просто
// се съдържат в себе си взаимно. Надявам се да не съм изпуснал нещо. o7

