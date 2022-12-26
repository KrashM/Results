// 34т.
#include<iostream>

bool trion(int n, int arr[])
{
    
    bool flag1 = true;
    bool flag2 = true;
    
    if(arr[0] <= arr[1])
    {
        for (int i = 0; i < n-1; i++)
        {
            // Можеш направо тук да връщаш false.
            if((arr[i] > arr[i+1] && i % 2 == 0))
            {
                flag1 = false;
            }

            if((arr[i] < arr[i+1] && i%2 == 1))
            {
                flag1 = false;
            }
        }

        if(flag1)
        {
            return 1;
        }
        else
        {
            return 0;
        }

    }
    else if(arr[0] >= arr[1])
    {
        for (int i = 0; i < n-1; i++)
        {
            // Същото и тук.
            if((arr[i] < arr[i+1] && i % 2 == 0))
            {
                flag2 = false;
            }

            if((arr[i] > arr[i+1] && i%2 == 1))
            {
                flag2 = false;
            }
        }

        if(flag2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    } 
} 
int main()
{
    int n;
    std::cin >> n;
    if(n < 0)
    {
        std::cout << "Vuveli ste otricatelno chislo" << std::endl;
        return 1;
    }
    int arr[1024];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    
    if(trion(n,arr))
    {
        std::cout << "Trion e!" << std::endl; 
    }
    else
    {
        std::cout << "Ne e trion!" << std::endl; 
    }
    return 0;
}