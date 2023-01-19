// 5т.
#include <iostream>


char strlen(char str[]);

bool isDecIncreFun(char str[], int n); //създаваме функция, която проверява числата

int main()
{
    int n;

    // Защо като ще въвеждаме числа ги вкарваме в char масив?!?
    // Тогава самите числа ще са ти от интервала [-128, 127].
    char str[1024];

    std::cin >> n;

    for (std::size_t i = 0; i < n; ++i)
    {
        std::cin >> str; //вевеждаме н-на брой числа
    }
    
    // Извикваме функцията без аргументи?!?
    std::cout << isDecIncreFun << std::endl;
    
    return 0;
}

// Правилна имплементация, само че връщаме int не char.
char strlen(char str[])
{
    int i = 0;
    while (i != '\0')
    {
        i++;
    }
    return i;
}
bool isDecIncreFun(char str[], int n)
{
    int n;

    for (std::size_t i; i < n; ++i)
    {
        if (str[i] <= str[i + 1])
        {
            
        }
        
    }
    
}