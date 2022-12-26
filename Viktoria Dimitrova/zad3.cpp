#include<iostream>
#include<cmath>

const std::size_t MAX_SIZE = 1000;

void enterArray(double array[], std::size_t n)
{
    for(std::size_t i=0; i<n; i++)
    {
        std::cin>>array[i];
    }
}

int findMaxX(double array[], std::size_t n)
{
    double max = array[0];
    for(int i=2; i<n; i=i+2)
    {
        if(array[i]>max) max = array[i];
    }
    return max;
}

int findMaxY(double array[], std::size_t n)
{
    double max = array[1];
    for(int i=3; i<n; i=i+2)
    {
        if(array[i]>max) max = array[i];
    }
    return max;
}

int findMinX(double array[], std::size_t n)
{
    double min = array[0];
    for(int i=0; i<n; i=i+2)
    {
        if(array[i]<min) min = array[i];
    }
    return min;
}

int findMinY(double array[], std::size_t n)
{
    double min = array[1];
    for(int i=3; i<n; i=i+2)
    {
        if(array[i]>min) min = array[i];
    }
    return min;
}



int main()
{
    size_t n;
    double array [MAX_SIZE];

    std::cin>>n;
    enterArray(array, 2*n);

    // Не се смятат така страните.
    // Пример кога няма да работи:
    // maxX = -3, minX = -5 => страната е с дължина 2.
    // Обаче по твоята схема става: |-3| + |-5| = 8.
    double dyljina =  abs(findMaxX(array, 2*n)) + abs(findMinX(array, 2*n));
    double shirina = abs(findMaxY(array, 2*n)) + abs(findMinY(array, 2*n));

    std::cout<<"dyljinata e "<<dyljina<<" shirinata e"<<shirina<<std::endl;
    // Не си дала параметри на findMaxY.
    std::cout<<"koordinati: ("<<findMinX(array, 2*n)<<" , "<<findMaxY<<")";


}