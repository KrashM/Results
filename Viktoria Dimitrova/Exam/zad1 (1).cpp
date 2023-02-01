#include<iostream>

const size_t MAX_SIZE = 1024;

void deleteUpper(char *s)
{
    char *k = s;
    while(*(k+1) != '\0')
    {
        *k = *(k+1);
        k++;
    }
    *k = '\0';
}

void removeUpper (char *s)
{
    while(*s != '\0')
    {
        if(*s >= 'A' && *s<= 'Z')
        {
            deleteUpper(s);
        }
        s++;
    }
}

int main()
{
    char string[MAX_SIZE];
    std::cin.getline(string, MAX_SIZE);

    removeUpper(string);

    std::cout<<string;

    return 0;
}