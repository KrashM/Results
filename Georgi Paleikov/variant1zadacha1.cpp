// 30т.
#include <iostream>


int sizecheck (char chislo[], int size = 1000)
{
    int broqch = 0;
    while (chislo[broqch]!= '\0')
    {
        broqch++;
    }
    return broqch;
}

// Този подход е верен, но работи за малки числа.
// Тук се предпочита директното сравняване на string-овете.
int chartonum (char chislo[])
{
    int result = 0;
    int size = sizecheck(chislo);
    for (int i = 0; i<size; i++)
    {result = result*10 + chislo[i]-'0';}
    return result;
}

bool leq (char n1[], char n2[])
{
    int size1 = sizecheck (n1); // Излишно
    int chislo1int = chartonum(n1);
    int size2 = sizecheck (n2); // Излишно
    int chislo2int = chartonum (n2);

    if(chislo1int <= chislo2int)
    return true;
    return false;
}

int main ()
{
    char chislo1 [1000];
    char chislo2 [1000];
    std::cin>>chislo1;
    std::cin>>chislo2;

    int size1 = sizecheck(chislo1);
    int size2 = sizecheck(chislo2);

    for(int i = 0; i < size1; i++)
    {
        if(chislo1[i]>'9' || chislo1[i]<'0')
        {
            std::cout << "Greshno vuvejdane";
            return 0;
        }
    }
    // Предполагам си искал да пишеш до size2.
    for(int m = 0; m < size1; m++)
    {
        if(chislo1[m]>'9' || chislo2[m]<'0')
        {
            std::cout << "Greshno vuvejdane";
            return 0;
        }
    }

    std::cout << leq (chislo1, chislo2);

    return 0;
}