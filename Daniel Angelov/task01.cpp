// 15т.
#include <iostream>
#include <cstring>

const unsigned int MAX_CAPACITY = 1024;

using std::cin;
using std::cout;

unsigned int string_to_digit (char str[],size_t const SIZE);
bool leq (unsigned int n1, unsigned int n2);
int main ()
{
    char str1 [MAX_CAPACITY], str2 [MAX_CAPACITY];
    cin.getline(str1,MAX_CAPACITY); // Един прост cin ти върши работа тук.
    cin.getline(str2,MAX_CAPACITY); // Един прост cin ти върши работа тук.
    // Нямаш валидация на string-a. Ако ти въведат "2h8291jo01"?
    string_to_digit (str1, strlen(str1));
    string_to_digit (str2,strlen(str2));

    
    unsigned int n1 = string_to_digit (str1, strlen(str1));
    unsigned int n2 = string_to_digit (str1, strlen(str1));


    cout << std::boolalpha << leq(n1,n2);


    return 0; 
}

unsigned int string_to_digit (char str[],size_t const SIZE)
{
    // Хубаво е i и SIZE да са от един тип за сравняването.
    for (unsigned int i = 0 ; i < SIZE; i++ )
    {
        // Логиката тук е ако имаме цифра в string-а,
        // Дефинирай number = 1 * 10 и към него добави стойността на цифрата от string-а.
        // И след това върни number.
        // Ако имам "123", това ще върне 1 * 10 + 1 -> 11, нищо общо с 123.
        if (str [i] >= '0' && str [i] <= '9')
        {   
            int number = 1; 

            str [i] -= '0';
            number *= 10;
            number += str[i];

            return number;      
        } 
        
    }
    // Не трябва да се връща такава стойност.
    // За тази цел първо валидираме входа.
    return -1;

}

bool leq (unsigned int n1, unsigned int n2)
{
    return n1 <= n2;
}

