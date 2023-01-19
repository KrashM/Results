// Супер е задачата!!
// 25т.
#include <iostream>
#include <cmath>
const int pari[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

bool proverka(double n, double k)
{
    if (n<0 || k<0)
    return false;
    return true;
}

void resto (const int pari[], int* broqch, int n, int k)
{
    if (k<n)
    {
        std::cout << "Money is not enough";
        return;
    }

    if (n==k)
    {
        std::cout << "Alright";
        return;
    }

    int temp = 0;
    int resto = k-n;
    while(resto > 0)
    {
        if(resto >= pari[temp])
        {
            resto -=pari[temp];
            broqch[temp]++;
        }
        else {temp++;}
    }
      
    for (int i = 0; i<13; i++)
    {
        if (broqch[i]!=0)
        std::cout << "Banknota/moneta ot " << (double)pari[i]/100 << " leva " << broqch[i] << " puti" << std::endl;
    }
}

int main()
{
    double N;
    double K;
    int broqch[13] = {0};

    std::cin >> N >> K;
    if (!proverka(N,K))
    {
        std::cout << "Greshno vuvejdane";
        return 0;
    }

    int n = round(N*100); // И без round става същото.
    int k = round(K*100); // И без round става същото.
    resto(pari, broqch, n, k);
    // Не е нужно да подаваш глобален масив.
    // Тъй като ще ги бърка и винаги ще предпочита глобалния пред локалния.
    
    return 0;
}