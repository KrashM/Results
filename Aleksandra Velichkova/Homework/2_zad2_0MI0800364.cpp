// Отново много добра задача. Имам само 2 забележки.
// Може малко по-чисто да се разпише без всички тези вложени if-ове.
// И също така не е желателно всичко да се пише в main-а.
// 25т.
#include <iostream>

int main() {
    int numOfElfs;
    bool valid = true;

    std::cout << "Enter number of Elfs: " << '\n';
    std::cin >> numOfElfs;

    if(!(numOfElfs > 0 && numOfElfs <= 100 && isalpha(numOfElfs))) // даже не знаех, че има такава функция XD. Обаче май не прави това, което мислиш.
    {
        std::cout << "Enter number of Elfs between 1 and 100!";
    } else {
        int maxCal = 0, index = 0;
        for (std::size_t i = 1; i <= numOfElfs; i++)
        {
            int numOfRation, currSum = 0;

            std::cout << "Enter number of ration for Elf number " << i << ":" << '\n';
            std::cin >> numOfRation;
            if(!(numOfRation >= 1 && numOfRation <= 20 && isalpha(numOfElfs))) 
            {
                std::cout << "Enter number of ration between 1 and 20!";
                valid = false;
                break;
            } else {
                std::cout << "Enter calories: \n";
                for (std::size_t j = 0; j < numOfRation; j++)
                {
                    int calories;
                    std::cin >> calories;
                    currSum += calories;
                }
                if(currSum > maxCal) {
                    maxCal = currSum;
                    index = i;
                }
                currSum = 0;
            }

        }
        if(valid)
        {
            std::cout << "Elf number " << index << " has max calories - " << maxCal << '.';
        }
    }

    
}