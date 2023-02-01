#include<iostream>

const int MAX_SIZE = 0;

void pivot(int arr[], int size, int x)
{
    for(int i=0; i<size; i++)
    {
        
    }
}

int main()
{
    int arr[MAX_SIZE];
    int size;
    std::cin>>size;

    for(int i=0; i<size; i++)
    {
        std::cin>>arr[i];
    }

    int x;
    std::cin>>x;

    pivot(arr, size, x);

    for(int i=0; i<size; i++)
    {
        std::cout<<arr[i];
    }

}