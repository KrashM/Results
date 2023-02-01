#include <iostream>


void readArray(int *number , size_t &size)
{
       for(int i = 0 ; i < size ; i++)
    {
        std::cin >> number[i];
    }
}

int chekEvens(int *number , size_t &size)
{
    int counter = 0;
    for(int i = 0 ; i < size ; i++)
    {
        if(number[i] % 2 == 0)
        {
            counter++;
        }
    }
    return counter;
}

int* filterEvens(int* numbers , size_t &size)
{
    
    int* arrayOfEvenns = new (std::nothrow) int[size];
    if(!arrayOfEvenns)
    {
        return nullptr;
    }
    int arrayOfevensIndex = 0;
    for(int i = 0 ; i < size ; i++)
    {
        if(numbers[i] % 2 == 0)
        {
            arrayOfEvenns[arrayOfevensIndex] = numbers[i];
            arrayOfevensIndex++;
        }
    }
    size = chekEvens(numbers , size);
    return arrayOfEvenns;
}


int main()
{   
    const int MAX_ARRAY_SIZE = 100;
    int array[MAX_ARRAY_SIZE];
    size_t size;
    std::cin >> size;

    readArray(array , size);
    int *arrayOfEvens = filterEvens(array , size);

    for(int i = 0 ; i < size ; i++)
    {
        std::cout << arrayOfEvens[i] << " ";
    }

    delete[] arrayOfEvens;
   

    return 0;
}