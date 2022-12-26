// 30т.
#include <iostream>
#include  <cstring>

bool leq(unsigned int n1, unsigned int n2)
{
    // Има по-компактен начин да се напише.
    // return n1 <= n2;
    if(n1 <= n2) return 1;
    return 0;
}

int main()
{
    char str1[1024], str2[1024];
    std :: cin >> str1;

    for(int i=0;i<strlen(str1);i++)
    {
        if(str1[i] < '0' || str1[i] > '9')
        {
            std :: cout << "Number 1 is incorrect." << std :: endl;
            return 1;
        }
    }

    std :: cin >> str2;

    for(int i=0;i<strlen(str2);i++)
    {
        if(str2[i] < '0' || str2[i] > '9')
        {
            std :: cout << "Number 2 is incorrect." << std :: endl;
            return 1;
        }
    }

    unsigned int n1=0, n2=0;

    // Този подход е валиден само за малки числа.
    // Директното сравняване на стринговете е за предпочитане.
    for(int i=0;i<strlen(str1); i++)
    {
        n1*=10;
        n1+=str1[i] - '0';
    }

    for(int i=0;i<strlen(str2); i++)
    {
        n2*=10;
        n2+=str2[i] - '0';
    }

    //std :: cout << n1 << " " << n2 << std :: endl;

    // Можеше да използваш просто std::boolalpha.
    if(leq(n1, n2)) std :: cout << "True" << std :: endl;
    else std :: cout << "False" << std :: endl;
        


    return 0;
}