// Като цяло много добра задача.
// Само можеше примерно да не слагаш толкова неща в main-а.
// Примерно функция за print-а и sort-а нямаше да навредят XD.
// 21т.
#include <iostream>
#include <cstring>

const int SIZE = 1000;

using std::size_t;
using std::swap;


int color(int num){
    return num / 100000;
}

int value(int num){

    int number = ((num / 100) % 10) * 10 + ((num / 10) % 10);
    // Можеше просто да напишеш num / 10 % 100 ;)

    return number;
}

bool checkIfValid(int num){

    if(color(num) < 1 || color(num) > 5)
    return false;

    if(value(num) < 0 || value(num) > 14)
    return false;

    if(color(num) == 5 && value(num) < 13)
    return false;

    if(color(num) != 5 && value(num) > 12)
    return false;

    return true;
}


int main(){

    unsigned int cardsCount;
    std::cin >> cardsCount;

    // Трябваше да направиш динамичен масива.
    int allUnos[255];

    for(int i = 0; i < cardsCount; i++){

      std::cin >> allUnos[i];
      if(checkIfValid(allUnos[i]) == false){

      std::cout << "Invalid card!" << std::endl;

      return 1;
    }

}

    for(int i = 0; i < cardsCount - 1; i++){

        for(int j = i + 1; j < cardsCount; j++){

            // Тука трябваше да сравняваш value не color.
            if(color(allUnos[i]) > color(allUnos[j])){
                swap(allUnos[i], allUnos[j]);

            }else if(value(allUnos[i]) == value(allUnos[j])){

                if(color(allUnos[i]) < color(allUnos[j]))
                    swap(allUnos[i], allUnos[j]);
            }
        }
    }


    for(int i = 0; i < cardsCount; i++){

        std::cout << "(";

        if(color(allUnos[i]) == 1)
        std::cout << "YELLOW ";

        else if(color(allUnos[i]) == 2)
        std::cout << "GREEN ";

        else if(color(allUnos[i]) == 3)
        std::cout << "BLUE ";

        else if(color(allUnos[i]) == 4)
        std::cout << "RED ";
        
        else if(color(allUnos[i]) == 5){

            if(value(allUnos[i]) == 13)
            std::cout << "CHANGE COLOUR) ";

            else if(value(allUnos[i]) == 14)
            std::cout << "+4) ";

            continue;
        }

        if(value(allUnos[i]) < 10){

        std::cout << value(allUnos[i]) << ") ";

        }else if(value(allUnos[i]) == 10)
        std::cout << "+2) ";

        else if(value(allUnos[i]) == 11)
        std::cout << "REVERSE) ";

        else if(value(allUnos[i]) == 12)
        std::cout << "STOP) ";
    }

    std::cout << std::endl;

    return 0;

}