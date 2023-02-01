#include <iostream>

void removeUpper(char *s)
{
    for(int i = 0 ; s[i] != '\0' ; i++)
    {
    
        if((s[i] >= 65 && s[i] <= 90) && (s[i + 1] < 65 || s[i + 1] > 90) )
        {
            for(int j = i ; s[j] != '\0' ; j++)
            {
                s[j] = s[j + 1];
                
            }
        }
    }
}

int main()
{   
    const int MAX_ARRAY_SIZE = 100;
    char array[MAX_ARRAY_SIZE];

    std::cin.getline(array , MAX_ARRAY_SIZE);
    removeUpper(array);

    for(int i = 0 ; array[i] != '\0' ; i++)
    {
        std::cout << array[i];
    }
    
    //std::cout << array;

    return 0;
}