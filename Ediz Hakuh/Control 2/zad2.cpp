// 30т.
#include <iostream>

// Малко по-чисто можеше да се напише тази функция.
bool trion(int n, int a[])
{
    // Защо ги слагаш да са true, като веднага след това ги правиш на false.
    bool flag1 = true, flag2 = true;
    if(a[0] <= a[1])
    {
        flag1 = false;
        for(int i=1;i<n-1;i++)
        {
            if(flag1 == false && a[i] >= a[i+1])flag1=true;
            else if(flag1 == false && a[i] < a[i+1]) return false;
            if(flag1 == true && a[i] <= a[i+1])flag1=false;
            else if(flag1 == true && a[i] > a[i+1])return false;
        }
        return true;
    }
    else if(a[0] >= a[1])
    {
        flag2 = false;
        for(int i=1;i<n-1;i++)
        {
            if(flag2 == false && a[i] <= a[i+1])flag2=true;
            else if(flag2 == false && a[i] > a[i+1]) return false;
            if(flag2 == true && a[i] >= a[i+1])flag2=false;
            else if(flag2 == true && a[i] < a[i+1])return false;
        }
        return true;
    }
}

int main()
{
    int n;

    if(n < 0) // Хубаво щеше да е да проверяваме и за n > 1024
    {
        std :: cout << "n is incorrect." << std :: endl;
        return 1; 
    }

    int a[1024];

    std :: cin >> n;
    for(int i=0;i<n;i++)
    {
        std :: cin >> a[i];
    }

    // Отново можеше с boolalpha за по-лесно.
    if(trion(n, a))std :: cout << "True" << std :: endl;
    else std :: cout << "False" << std :: endl;


    return 0;
}