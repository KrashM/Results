// 20т.
#include <iostream>

const int MAX_SIZE=1024;

std::size_t strlen(const char str[])
{
    std::size_t i=0;
    while(str[i]!='\0')
    {
        ++i;
    }

    return i;
}


// Подхода не е лош но няма да работи за по-големи числа.
bool leq(const char n1[], const char n2[])
{
    std::size_t len1=strlen(n1);
    std::size_t len2=strlen(n2);
    long long num1=0;
    long long num2=0;
    // Не е хубаво да умесваме типовете при сравнения,
    // защото може да се получат странни неща.
    // len1 и len2 са ти size_t направи и i size_t.
    for(int i=0; i<len1; ++i)
    {
        num1*=10;
        num1+=(n1[i]-'0');
    }

    // Предполагам е typo трябва да len2 тук.
    for(int i=0; i<len1; ++i)
    {
        num2*=10;
        num2+=(n2[i]-'0');
    }

    return num1<=num2;
}

int main()
{
    char n1[MAX_SIZE];
    char n2[MAX_SIZE];

    std::cout<<"Enter the first string of numbers: ";
    std::cin>>n1;
    if(!std::cin)
    {
        std::cout<<"Invalid input";
        return -1;
    }
    std::size_t len=strlen(n1);
    for(int i=0; i<len; ++i)
    {
        // Няма как да е едновременно по-малко и по-голямо,
        // затова трябва логическо или тук.
        if(n1[i]<'0' && n1[i]>'9')
        {
            std::cout<<"Invalid input";
            return -1;
        }
    }
    std::cout<<"Enter the second string of numbers: ";
    if(!std::cin)
    {
        std::cout<<"Invalid input";
        return -1;
    }
    std::cin>>n2;
    // Липсва ни валидацията за n2.

    std::cout<<std::boolalpha<<leq(n1,n2);

    return 0;
}