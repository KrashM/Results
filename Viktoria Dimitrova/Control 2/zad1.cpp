#include<iostream>

const std::size_t MAX_LENGTH = 1000;

bool leq (char n1[],  char n2[])  //n1 ≤ n2
{
    size_t n1DigitCount =0;
    while( n1[n1DigitCount] != '\0' )
    {
        n1DigitCount++;
    }

    size_t n2DigitCount =0;
    while( n2[n2DigitCount] != '\0' )
    {
        n2DigitCount++;
    }

    if(n1DigitCount < n2DigitCount) return true;
    if(n1DigitCount > n2DigitCount) return false;

    for(std::size_t i=0; i<n1DigitCount; i++)
    {
        // Можеше директно да ги сравняваш без да вадиш '0'.
        // Иначе пак си е валидно.
        if( n1[i]-'0' < n2[i]-'0' ) return true;
        if( n1[i]-'0' > n2[i]-'0' ) return false;
    }

    return true;
}

int main()
{
    char n1[MAX_LENGTH], n2[MAX_LENGTH];
    
    std::cin.getline(n1, MAX_LENGTH); // Един прост cin ти върши работа тук.
    std::cin.getline(n2, MAX_LENGTH); // Един прост cin ти върши работа тук.

    // Нямаш валидация за числата.
    // Ако въведа "29uh891u2390", какво правим?
    
    if(leq(n1, n2)) std::cout<<n1<<"<="<<n2;
    else std::cout<<n1<<">"<<n2;

    return 0;
}