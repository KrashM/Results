// Перфектно разписана!
// Само мога да отбележа да не набутваш всичко в main-а.
// 25т.
#include <iostream>

int main()
{
    int numElfs;
    std :: cin >> numElfs;

    if(numElfs <= 0 || numElfs > 100)
    {
        std :: cout << "Enter new number of elfs, this one is incorrect." << std :: endl;
        return 1;
    }

    int rations, elfWithMaxCalories;
    long long int calories, sumCaloriesPerElf = 0, maxCalories = -1;

    for(int i = 1; i <= numElfs; i++)
    {
        std :: cin >> rations;
        if(rations <= 0 || rations > 20)
        {
            std :: cout << "Enter new number of rations, this one is incorrect." << std :: endl;
            return 1;
        }

        for(int j = 0; j < rations; j++)
        {
            std :: cin >> calories;
            if(calories < 0)
            {
                std :: cout << "Enter new number for calories, this one is incorrect." << std :: endl;
                return 1;
            }
            sumCaloriesPerElf += calories;
        }
        if(sumCaloriesPerElf > maxCalories)
        {
            maxCalories = sumCaloriesPerElf;
            elfWithMaxCalories = i;
        }

        sumCaloriesPerElf = 0;
    }

    std :: cout << "Elf " << elfWithMaxCalories << " carries the biggest amount of calories - " << maxCalories << std :: endl;

    return 0;
}