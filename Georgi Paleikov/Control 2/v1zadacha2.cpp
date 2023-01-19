// 34т.
#include <iostream>

bool trion1 (int masiv[], int size)
{
    for (int m = 0; m < size-1; m++)
    {
        if(m%2 == 0 && masiv[m] <= masiv[m+1])
        {
            continue;
        }
        if(m%2 == 1 && masiv[m] >= masiv[m+1])
        {
            continue;
        }
        return false;
    }
    return true;
}

bool trion2 (int masiv[], int size)
{
    for (int m = 0; m < size-1; m++)
    {
        if(m%2 == 0 && masiv[m] >= masiv[m+1])
        {
            continue;
        }
        if(m%2 == 1 && masiv[m] <= masiv[m+1])
        {
            continue;
        }
        return false;
    }
    return true;
}



bool trion (int masiv[], int size)
{
   bool a = trion1 (masiv, size);
   bool b = trion2 (masiv, size);
   if (a == true || b == true)
   {
    return true;
   }
   else return false;
}

int main()
{
    int n;
    std::cin >> n;
    int masiv[1000];

    for (int i = 0; i < n; i++)
    std::cin >> masiv[i];

    for (int i = 0; i < n; i++)
    {
        // Числата могат да са отрицателни. Това не е проблем.
    if (masiv[i] < 0)
    {
        std::cout << "Greshno vuvejdane";
        return 0;
    }
    }

    std::cout << trion (masiv,n);
    return 0;
}