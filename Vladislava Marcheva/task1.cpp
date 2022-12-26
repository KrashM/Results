#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;

const int MAX_CAPACITY = 1024;

// Тази функция ще връща само положителни числа unsigned int, щеше да е за предпочитане.
int strlen(char str[])
{
    unsigned int i = 0;
    while(str[i] != '\0') i++;
    return i;
}

bool leq (char n1[], char n2[])
{
    size_t len1 = strlen(n1), len2 = strlen(n2);
    for(size_t i = 0; i < len1; i++)
    {
        // Това не работи така, както си мислиш.
        // Това, което се случва е следното.
        // Сравняваш n1[0] <= n2[0], ако да връщаш true, ако не връщаш false.
        // Реално сравняваш само първата цифра на двете числа.
        // Ако се абстрахираме от return-а, отново не прави, това което трябва.
        // Ще сравняваш по следния начин:
        // n1[0] <= n2[0], n1[0] <= n2[1], ..., n1[0] <= n2[len2 - 1]
        // ...
        // n1[len1 - 1] <= n2[0], n1[len1 - 1] <= n2[1], ..., n1[len1 - 1] <= n2[len2 - 1]
        for(size_t j = 0; j < len2; j++)
        {
            if(n1[i] <= n2[j]) return true;
            return false;
        }
    }
    
}

int main()
{
    char n1[MAX_CAPACITY];
    char n2[MAX_CAPACITY];

    cin >> n1 >> n2;
    // Нямаш валидация на числата.
    // Какво става ако вкарам "2i24823jij0931"?

    cout << std::boolalpha << leq(n1, n2) << endl;

    return 0;
}