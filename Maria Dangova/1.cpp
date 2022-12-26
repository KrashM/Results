// 10т.
#include <iostream>

const int SIZE = 1024;

int strlen (char str [])
{
    int i = 0;
    while (str [i] != '\0')
        {
            i++;
        }
    return i;
}

bool evenNumbers(int n)
{

    // Не трябва да има равно.
    while (n >= 1)
    {
        if (n % 2 == 1) return 0;
        // Трябва да е /=, защото така не запазваш промените по n.
        // Това става безкраен цикъл.
        n / 10;
    }
 if ( n == 0) return 1;
}

   int main ()
{
    char arr [SIZE];
    std::cin >> arr;
    // Нямаш валидация на string-а.
    int number = 0;
   
    
    // arr - '\0' не прави, това което си мислиш.
    // Подхода е верен, но работи само за малки числа.
    // Тук се предпочита дирекнто сравняване на символите.
    for (int i = 0; i < strlen(arr - '\0'); i++)
    {
        number *= 10;
        number += arr[i];
    }

    // Няма как да стане отрицателно.
    // Логиката ти не го позволява.
    if (number < 0)
    {
        std::cout << "Invalid number" << std::endl;
    }
    
    // Грешно име на функцията.
    std::cout << std::boolalpha << isEven(number);
    return 0;
}

