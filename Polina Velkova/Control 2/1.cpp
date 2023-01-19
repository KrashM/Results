// 10т.
#include <iostream>

char strlen1(char strN1[]);

char strlen2(char strN2[]);

int countNumbersN1(char strN1[], int n);

int countNumbersN2(char strN2[], int n);

bool leq(char strN1[], char strN2[], int n1, int n2);

int main()
{
    int n, n1, n2;
    char strN1[1024], strN2[1024];
    std::cin >> strN1 >> strN2;// Вевеждаме две числа
    // Няма валидация на string-овете.
    std::cout << leq(strN1, strN2, n1, n2);

    return 0;
}

// Тази функция е ненужна
char strlen1(char strN1[])
{
    for (std::size_t i = 0; strN1[i] != '\0'; ++i)
    {
        std::cout << i;
    }
}
// Правилна имплементация на strlen, само дето връщаме int не char.
char strlen2(char strN2[])
{
    int i = 0;
    while (i != '\0')
    {
        i++;
    }
    return i;
}

// Следвашите две функции правят абсолютно едно и също нещо.
// Посто загубено време да ги пишеш просто с различни имена.

// Тук просто принтираме цифра по цифра числото
// int n е ненужно, никъде не се използва
int countNumbersN1(char strN1[], int n)
{
    for (int n1 = 0; strN1[n1] != '\0'; ++n1)
    {
        std::cout << n1;
    }
}
// Тук просто принтираме индексите, през които минаваме.
// int n е ненужно, никъде не се използва
int countNumbersN2(char strN2[], int n)
{
    for (int n2 = 0; strN2[n2] != '\0'; ++n2)
    {
        std::cout << n2;
    }
}
// Тук проверяваме n1 <= n2.
// Обаче какво са n1 и n2?
// Къде им даваме стойност в програмата?
bool leq(char strN1[], char strN2[], int n1, int n2)
{
    if (n1 <= n2)
    {
        std::cout << " true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
}