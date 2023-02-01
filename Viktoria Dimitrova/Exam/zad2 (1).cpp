#include<iostream>

const unsigned int MAX_SIZE = 100;

struct int_array
{ 
    int *arr; 
    unsigned int size; 
};

int_array filter_evens(int array[], unsigned int size, unsigned int countOfEvens)
{
    int_array arrayOfEvens;
    arrayOfEvens.size = countOfEvens;
    arrayOfEvens.arr = new (std::nothrow) int[countOfEvens];

    if(!arrayOfEvens.arr)
    {
        std::cout<<"Problem with allocating memory for the array";
        arrayOfEvens.size = 0;
        return arrayOfEvens;
    }
    
    unsigned int currentElement = 0;
    for(unsigned int i=0; i<size; i++)
    {
        if(array[i] % 2 == 0)
        {
            arrayOfEvens.arr[currentElement] = array[i];
            currentElement++;
        }
    }

    return arrayOfEvens;
}

void printInt_array (int_array& arrayOfEvens)
{
    for(unsigned int i=0; i<arrayOfEvens.size; i++)
    {
        std::cout<<arrayOfEvens.arr[i]<<" ";
    }
}

int main()
{
    int array[MAX_SIZE];
    unsigned int size;

    std::cin>>size;

    unsigned int countOfEvens = 0;

    for(unsigned int i=0; i<size; i++)
    {
        std::cin>>array[i];
        if(array[i] % 2 == 0) countOfEvens++;
    }

    int_array arrayOfEvens = filter_evens(array, size, countOfEvens);
    printInt_array(arrayOfEvens);

    delete[] arrayOfEvens.arr;
}