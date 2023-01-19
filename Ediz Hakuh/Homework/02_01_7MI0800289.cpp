// Без никаква забележка!! Иделен.
// 25т.
#include <iostream>
#include <cstring>

const int MAX_CAPACIY = 31;

char** dellocate(char** arr,int size)
{
    for(int i = 0; i < size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

char** allocate(int size)
{
    char** arr = new (std :: nothrow) char* [size];
    if(!arr)
    {
        return nullptr; 
    }

    for(int i = 0; i < size; i++)
    {
        char now[MAX_CAPACIY];
        std :: cin.getline(now, MAX_CAPACIY);

        arr[i] = new (std :: nothrow) char[strlen(now) + 1];
        if(!arr[i])
        {
            dellocate(arr, i);
            return nullptr;
        }
        strcpy(arr[i], now);
    }

    return arr;
}

bool isValid(char** arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < strlen(arr[i]); j++)
        {
            if(!((arr[i][j] >= 'A' && arr[i][j] <= 'Z') || 
               (arr[i][j] >= 'a' && arr[i][j] <= 'z') || 
               (arr[i][j] >= '0' && arr[i][j] <= '9') || arr[i][j] == ' ')) return false;
        }
    }
    
    return true;
}

int compare(char* arr1, char* arr2)
{
    int len1 = strlen(arr1), len2 = strlen(arr2), maxLen;
    char new1[MAX_CAPACIY];
    char new2[MAX_CAPACIY];

    for(int i = 0; i < len1; i++)
    {
        if(arr1[i] >= 'A' && arr1[i] <= 'Z')
        {
            new1[i] = arr1[i] + 32;
        }
        else new1[i] = arr1[i];
    }

    for(int i = 0; i < len2; i++)
    {
        if(arr2[i] >= 'A' && arr2[i] <= 'Z')
        {
            new2[i] = arr2[i] + 32;
        }
        else new2[i] = arr2[i];
    }

    return strcmp(new1, new2);
}

char** changeOrder(char** arr, int size)
{
    char change[MAX_CAPACIY];
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {

            if(compare(arr[i], arr[j]) > 0)
            {
                strcpy(change, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], change);
            }
        }
    }
    return arr;
}

void print(char** arr, int size)
{
    std :: cout << std :: endl;
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << std::endl;
    }
}
int main()
{

    int n;
    std :: cin >> n;

    if(n <= 0 || n > 50)
    {
        std :: cout << "Insert new number of strings. This one is incorrect." << std :: endl;
        return 1;
    }

    std :: cin.ignore();

    char** arr = allocate(n);
    if(!arr)
    {
        std :: cout << " Memory problem." << std :: endl;
        return 1;
    }
    
    if(!isValid(arr, n))
    {
        std :: cout << "There is an incorrect sentence." << std :: endl;
        return 1;
    }

    arr = changeOrder(arr, n);
    print(arr, n);
    dellocate(arr, n);
  

    return 0;
}