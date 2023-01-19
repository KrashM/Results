// Overall супер задача. На места може малко да се поопрости, но е топ!
// 25т.
#include <iostream>
#include <cstring>
const int SIZE_ROW = 50;
const int SIZE_COL = 31;
const int SIZE_CIN = 1024;

void swapWords(char *a, char *b)
{
        char temp[SIZE_COL];
        strcpy(temp, a);
        strcpy(a, b);
        strcpy(b, temp);
    
}

bool checkLetters(char str)
{
    return str >= 'a' && str <= 'z' || str >= 'A' && str <= 'Z' || str >= '0' && str <= '9' || str == ' ';
}

void deallocate(char **str, int size)
{
    for (std::size_t i = 0; i < size; ++i)
    {
        delete[] str[i];
    }

    delete[] str;
}

char **allocate(int n)
{
    char **str = new (std::nothrow) char*[n];

    if(!str) {
        std::cout << "Memory problem!";
        return nullptr;
    }

    for (std::size_t i = 0; i < n; i++)
    {
        char temp[SIZE_CIN];
        std::cout << "Enter sentence number " << i + 1 << ":\n";
        std::cin.getline(temp, SIZE_CIN);

        str[i] = new (std::nothrow) char[strlen(temp) + 1];

        if(!str[i])
        {
            deallocate(str, i);
            return nullptr;
        }

        strcpy(str[i], temp);
    }

    return str;
}

void **lexicographicalSort(char **str, std::size_t n)
{

    for (std::size_t i = 0; i < n; i++)
     {
        for (std::size_t j =  i + 1; j < n - 1; j++)
        {
                if(strcasecmp(str[i], str[j]) > 0)
                {
                    swapWords(str[i], str[j]);
                }   
        }
     }
}


void print(char **str, int size)
{
    for (std::size_t i = 0; i < size; i++)
    {
        std::cout << str[i] << '\n';
    }

}

int main()
{
    std::size_t n;

    std::cout << "Enter number of rows: " << '\n';
    std::cin >> n;
    if(n < 0 && n > SIZE_ROW)  // n няма как да е по-малко от 0.
    {
        std::cout << "Enter number between 1 and 50!";
    } else {
        std::cin.ignore();

        char **str = allocate(n);
        if(!str)
        {
            std::cout << "Memory problem!"; // 2 пъти принтиш това.
            return 1;
        }

        bool valid = true;

        for (std:: size_t i = 0; i < n; i++)
        {
            if(strlen(str[i]) > SIZE_COL) 
            {
                std::cout << "Enter less than 30 characters.";
                valid = false;
                break;
            }
            for (std::size_t j = 0; j < strlen(str[i]); j++)
            {
                if(!checkLetters(str[i][j]))
                {
                    std::cout << "Enter only letters and numbers!";
                    valid = false;
                    break;
                } 
            } 
        } 
        
        if(valid)
        {
            std::cout << "Sentences, sorted lexicographical:";
            lexicographicalSort(str, n);

            std::cout << '\n';

            print(str, n);
        }

        deallocate(str, n);
    }
    
    return 0;
}