// CONTROLA_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

//we have to convert the symbols from char to int so we can work with them
//i will do two different functions for these two numbers
// Трябва ти char масив не char
// Защо вместо да правиш функцията int и да връщаш параметъра num, просто не направиш num на референция.
int Convert(char input, int size, long num)
{    
    //we go thru the string element by element and the numbers will be sume of 
    //the first will the last element with index i < n + \0
    for (int i = 0; i < size; i++)
    {
            num *= 10;
            // Идеята е там. Въпросът е че за да добавяш цифрата
            // Ти трябва да правиш '2' - '0' -> 2
            // Вадиш аски кодовете и тъй като цифрите са една след друга разликата,
            // между кодовете им ще е точно толкова колкото цифрата.
            num += input[i] + '\0';     //the logic here is: value of first element (exmp: 2 + '\0') then (2 * 10) + (value of the second element, for exmp:) 2 --> 22... 
                                        //and so on till we reach the last element and the loop stops
    }

    //this function should return the value of the number
    return num;
}

//so we do the same here in this function
// Същите забележки на тази функция
int Convert2(char input2, int size2, long num2)
{
    for (int j = 0; j < size2; j++)
    {
        num2 *= 10;
        num2 += input2[j] + '\0';
    }

    return num2;
}

//in this function we will compare the numbers 
bool leq(int num, int num2)
{
    // Има по-хубав начин да се напише това нещо
    // return num <= num2;
    if (num <= num2) return true;
    else return false;
}

int main()
{
    const int MAX_SIZE = 1024;
    // Не е лоша идея да ги разделим на отделни редове.
    // Става много код за четене на един ред.
    char input[MAX_SIZE]; std::cout << "Insert a value in the first arr: "; std::cin >> input;
    char input2[MAX_SIZE]; std::cout << "Insert a value in the second arr: "; std::cin >> input2;
    // Липсва ти валидация и на двата входа.
    // Какво става ако въведа "Ai21j9?1j+"?

    //we use this to find easier the size of the char Arr (cuz i tried with a loop but it didn't exactly work out... next time...
    int size = strlen(input);
    int size2 = strlen(input2);

    //we define two numbers with start value 0
    long num = 0;
    long num2 = 0;

    // Никъде не извикваме функцията да конверира числата от формат string към int.

    //as an end we call the function and it will print if it's true that
    //num < num2 or false - if num > num2
    std::cout << "-----------------------------------" << std::endl;
    // Извикваме функцията без скоби и аргументи?!?
    // Моят компилатор просто винаги плюе 1.
    // Но на вярно при повечето даже няма да се компилира.
    std::cout << leq << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
