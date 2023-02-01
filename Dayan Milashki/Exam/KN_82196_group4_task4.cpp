#include <iostream>

void readArray(int *number , int size)
{
       for(int i = 0 ; i < size ; i++)
    {
        std::cin >> number[i];
    }
}

void swap(int &a , int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int *number , int size)
{
    for(int i = 0 ; i < size; i++)
    {
        std::cout << number[i] << " ";
    }
}

void pivot(int *number , int x)
{
    size_t size;
    std::cin >> size;

    readArray(number , size);
   
    for(int i = 0 ; i < size - 1 ; i++)
    {
        if(number[i] > x && number[i] > number[i + 1])
        {
            swap(number[i] , number[i + 1]);
        }
    }

    printArray(number , size);
}

int main()
{   
    const int MAX_ARRAY_SIZE = 100;
    int array[MAX_ARRAY_SIZE];

    int x;
    std::cin >> x;
    pivot(array , x);
    

   

    return 0;
}