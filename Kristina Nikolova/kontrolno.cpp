// 1ва - 20т.
// 2ра - 15т.
// 3та - няма
#include <iostream>
#include<cstring>
const int MAX_SIZE = 255;

bool task2(int arr[], const int& n)
{
    
    int counter = 0;
    // Трябва да въртиш с i += 2(през 2 елемента),
    // за да може логиката в if-а да те удовлетворява.
    for (int i = 0; i < n; i++)
    {
        // Това ти е само единият вариант на такава редица.
        if (i % 2 != 0)
        {
            // Тук на първа врътка имаш i - 1 = -1. Такъв индекс прави проблеми.
            // Също така на последна врътка i = n - 1 => i + 1 = n, което е извън масива.
            if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            {
                
                counter++;
                
            }

        }
    }
   
    if (counter == n / 2)
    {
        
        return true;
    }
    else
    {
       return false;
    }
    
   
}
void readArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout<< arr[i]<<" ";
    }
}
void printArr(char arr[])
{
    for (int i = 0; arr[i]!='\0'; i++)
    {
        std::cout << arr[i] << " ";
    }
}
int* charArrToInt(char str1[], int size)
{
    // Това за следващото контролно ;).
    int *n = new(std::nothrow)int[size];
    if (!n)
    {
        std::cout << "Memory problem!";
        return 0;
    }
    // Защо го правиш на int array, като можеш направо да го съберше тук.
    for (int i = 0; i < size; i++)
    {
        n[i] = str1[i] - '0';
    }
    return n;
}
// Тази функция ти намира сбора на всички цифри на числото.
// Не намира самото число.
// Ако ти въведа "123", това ще ти върне 6.
int sumOfNum(int* arr, int size)
{
    int sumOfDigitsOfN = 0;
    for (int i = 0; i < size; i++)
    {
        sumOfDigitsOfN += arr[i];
    }
    return sumOfDigitsOfN;
}
 bool leq(int n1, int n2)
 {
    // Можеш да го напишеш по-компактно
    // return n2 >= n1;
     if (n2 >= n1)
     {
         return true;
     }
     else
     {
         return false;
     }
 }
int main()
{
    //TASK 1
    char n1[MAX_SIZE];
    char n2[MAX_SIZE];
    std::cout << "Enter n1: ";
    std::cin.getline(n1, MAX_SIZE); // Обикновен cin върши работа.
    int size1 = strlen(n1); // strlen() -> връща стойност от тип size_t, каствайки го към int губим информация.

    std::cout << "Enter n2: ";
    std::cin.getline(n2, MAX_SIZE); // Обикновен cin върши работа.
    int size2 = strlen(n2); // strlen() -> връща стойност от тип size_t, каствайки го към int губим информация.

    // Нямаш валидация за числата.
    // Какво ще стане ако въведа "1lkj2uh1809sh9".

    int* N1 = charArrToInt(n1, size1);
    int* N2 = charArrToInt(n2, size2);

    int Nn1 = sumOfNum(N1, size1);
    int Nn2 = sumOfNum(N2, size2);
   std::cout<<std::boolalpha<< leq(Nn1, Nn2);
    

    // Браво че си се сетила!!
    delete[]N1;
    delete[]N2;
    
        
    ////Task 2
    //int n;
    //int arr[MAX_SIZE];
    //std::cout << "Enter n: ";
    //std::cin >> n;
    // Проверка за n ти трябва. 0 < n или n >= MAX_SIZE.
    //readArr(arr, n);
    //std::cout<<std::boolalpha<<task2(arr, n);
}

