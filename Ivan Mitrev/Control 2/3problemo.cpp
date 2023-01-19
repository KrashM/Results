// 25т.
#include<iostream>
#include<cmath>
int main()
{
    int n;
    std::cin >> n;
    // Валидация за n < 2?
    double arr[1024];
    for (int i = 0; i < n*2; i++)
    {
        std::cin >> arr[i];
    }
    // Става, но ако ти въведа по-големи стойности от това няма да е вярно.
    // Плюс точките се определят с double не с int.
    // Можеше да вземеш първата двойка x и y от масива за 0ви стойности.
    int miny = 10000000;
    int minx = 100000000;
    int maxx = -100000000;
    int maxy = -100000000;
    // (n * 2) - 2 ти е валиден индекс, който не разглеждаш.
    // Не трябва да има -2 там.
    for (int i = 0; i < (n*2)-2; i+=2)
    {
        if(arr[i] < minx)
        {
            minx = arr[i];
        }
        if(arr[i] > maxx)
        {
            maxx = arr[i];
        }
    }
    for (int i = 1; i < (n*2); i+=2)
    {
        if(arr[i] < miny)
        {
            miny = arr[i];
        }
        if(arr[i] > maxy)
        {
            maxy = arr[i];
        }

    }
    // Какво закръгляш като те са int. XD
    // Целият този блок е излишен.
    int lefttopx = floor(minx);
    int lefttopy = ceil(maxy);
    int righttopx = ceil(maxx);
    int righttopy = ceil(maxy);
    int downleftx = floor(minx);
    int downlefty = floor(miny);
    int downrightx = ceil(maxx);
    int downrighty = floor(miny);

    // Страната се намира като правиш max - min.
    int height = miny + maxy;
    int width =  minx + maxx;

    std::cout << floor(minx) << " " << ceil(maxy) << " " << height << " " << width << std::endl;
    return 0;
}