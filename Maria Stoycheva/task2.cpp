// 0т.
#include <iostream>

const int MAX_SIZE=1024;

// Това е само единият вариант, за такава редица.
bool isTrion(unsigned int n, int arr[])
{
    for(int i=0; i<n-1; ++i)
    {
        // Условията са объркани, не трябва да има равно.
        if(i%2==0 && arr[i]>=arr[i+1])
        {
            return false;
        }
        // Същата грешка и тук, равното се брои за валидно по условие.
        if(i%2!=0 && arr[i]<=arr[i+1])
        {
            return false;
        }

    }

    return true;
}

int main()
{
    int arr[MAX_SIZE];
    unsigned int n;
    std::cout<<"Enter the length of the array: ";
    std::cin>>n;
    if(!std::cin || n>1024)
    {
        std::cout<<"Invalid input";
        return -1;
    }
    for(int i=0; i<n; ++i)
    {
        std::cin>>arr[i];
        if(!std::cin)
        {
            std::cout<<"Invalid input";
            return -1;
        }
    }

    std::cout<<std::boolalpha<<isTrion(n,arr);
    return 0;
}