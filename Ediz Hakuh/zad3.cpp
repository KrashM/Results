// 30т.
#include <iostream>

int main()
{
    int n;
    std :: cin >> n;

    if(n<=0)
    {
        std :: cout << "n is incorrect." << std :: endl;
        return 1;
    }

    double x, y;
    // Грешно е да им слагаме някакви наши си стойности,
    // освен ако не са лимити на съответния тип.
    // Представи си ако всички стойности за X са ми по-големи от 100000.
    double minX=100000, maxX = -100000, minY = 100000, maxY=-100000;
    double a, b;

    for(int i=0;i<n;i++)
    {
        std :: cin >> x >> y;

        if(x < minX)minX = x;
        else if(x > maxX)maxX = x;

        if(y > maxY)maxY = y;
        else if(y < minY)minY = y;
    }

    a = maxX - minX;
    b = maxY - minY;

    // Страните няма как да станат отрицателни по горната формула.
    // Но браво че си го съобразил.
    if(a < 0) a *= -1;
    if(b < 0) b *= -1;

    std :: cout << minX << " " << maxY << " " << a << " " << b << std :: endl; 


    return 0;
}