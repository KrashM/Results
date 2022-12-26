// 25т.
#include<iostream>

// Верен подход, въпроса е че работи само за малки числа.
// Предпочитаното нещо тук е да се сравнява дирекнто string-а.
int changeIntoNumber(char n1[])
{
    int index = 0;
    int number = 0;
    while (n1[index] != '\0')
    {
       number = number*10;
       number = number + (n1[index] - '0');
       index+=1;
    }
    return number;
}
bool leq(char n1[], char n2[])
{
    int integerN1 = changeIntoNumber(n1);
    int integerN2 = changeIntoNumber(n2);
    if(integerN1 <= integerN2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char n1[256];
    std::cin.getline(n1,256); // Обикновен cin върши работа тук.
    char n2[256];
    std::cin.getline(n2,256); // Обикновен cin върши работа тук.
    // Освен за '-' трябваше да провериш и за други символи.
    // Примерно ако въведа "8872joi8291-2p="?
    if(n1[0] == '-' || n2[0] == '-')
    {
        std::cout << "Vuveli ste otricatelno chislo";
        return 1;
    } 
   
    if(leq(n1,n2))
    {
        std::cout << "Vqrno" << std::endl;
    }
    else
    {
        std::cout << "Ne e Vqrno" << std::endl; 
    }
    return 0;
}