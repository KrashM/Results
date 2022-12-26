// CONTROLA_02.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool Condition(int input[], int size)
{
    //so we have already inserted all the values for each element, we have to go thru them and check the following condition:
    for (int g = 0; g < size; g++)
    {
        //a0 <= a1, a1 >= a2, a2 <= a3, a3 >=  a4 ... the elements with even index are always greater than these with odd index
        // Това още при g = 1 се чупи.
        // За тази логика трябва да въртиш през интервал 2.
        // Тоест g += 2 в цикула.
        // Плюс това ти връщаш резултат още при първите 3 числа като провериш.
        // Какво ако редицата ни се чупи по-нататък?
        if ((input[g] <= input[g + 1]) && (input[g + 1] >= input[g + 2])) return true;
        else return false;
    }
}

bool Condition2(int input[], int size)
{
    //we make another "goint-thru-the-Arr so we can check the next condition:
    for (int j = 0; j < size; j++)
    {
        //a0 >= a1, a1 =< a2, a2 >= a3, a3 =< a4 ... the elements with even index are always greater than these with odd index
        // Същата забележка тук.
        if ((input[j] >= input[j + 1]) && (input[j + 1] <= input[j + 2])) return true;
        else return false;
    }
}

int main()
{
    //we define the max size of the Arr - the user should choose and insert a value, which is not greater or smaller than defined
    const int MAX_SIZE = 1000; int size;
    int input[MAX_SIZE]; 
    // Отново не пиши толкова неща на 1 ред.
    // Не е точно валидацията, която търсим, но се подсигоряваш все пак.
    do { std::cout << "Insert size for the Arr between 1 and " << MAX_SIZE << ": "; std::cin >> size; }
    while (size < 0 || size > MAX_SIZE); // Тук позволяваш да въведа число от следния интервал [0, MAX_SIZE].

    for (int i = 0; i < size; i++)
    {
        std::cout << "Insert a value for the element: ";
        std::cin >> input[i];
    }

    //here I will call the functions and the should print out if the values are true or false for them
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Do the values make the following condition true: \na0 >= a1, a1 =< a2, a2 >= a3, a3 =< a4 ...?" << std::endl; 
    // Извикваш функция без аргументи?!?
    std::cout << Condition << std::endl;

    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Do the values make the following condition true: \na0 <= a1, a1 >= a2, a2 <= a3, a3 >=  a4 ...?" << std::endl;
    // Извикваш функция без аргументи?!?
    std::cout << Condition2 << std::endl;
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
