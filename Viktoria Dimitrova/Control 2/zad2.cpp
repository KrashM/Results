#include<iostream>

const std::size_t MAX_SIZE = 1000;

void enterArray(int array[], std::size_t n)
{
    for(std::size_t i=0; i<n; i++)
    {
        std::cin>>array[i];
    }
}

bool isTrion(int array[], std::size_t n)
{
    if(n<=2) return true; //priemam che 1 ili 2 chisla obrazuvat trion
    // Трябва да гледаш и за равно.
    if(array[0]>array[1])
    {
        for(int i=0; i<=n-2; i=i+2)
        {
            if(!(array[i]>=array[i+1]))
            return false;
        }
        for(int i=1; i<=n-2; i=i+2)
        {
            if(!(array[i]<=array[i+1]))
            return false;
        }
    }
    // Трябва да гледаш и за равно.
    if(array[0]<array[1])
    {
        for(int i=0; i<=n-2; i=i+2)
        {
            if(!(array[i]<=array[i+1]))
            return false;
        }
        for(int i=1; i<=n-2; i=i+2)
        {
            if(!(array[i]>=array[i+1]))
            return false;
        }
    }
    return true;
}

int main()
{
    size_t n;
    int array[MAX_SIZE];

    std::cin>>n;
    enterArray(array, n);

    if(isTrion(array, n)) std::cout<<"Trion";
    else std::cout<<"No trion";

}