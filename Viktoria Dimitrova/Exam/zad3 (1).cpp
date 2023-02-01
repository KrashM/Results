#include<iostream>

struct Polynom
{
    unsigned int stepen;
    double* numbers;
};

Polynom enterPolynom()
{
    Polynom polynom;

    std::cout<<"enter stepen:";
    std::cin>>polynom.stepen;

    polynom.numbers = new (std::nothrow) double[polynom.stepen + 1];
    if(!polynom.numbers)
    {
        std::cout<<"problem while allocating memory for polynom";
        polynom.stepen = 0;
        return polynom;
    }

    std::cout<<"Enter numbers:";
    for(unsigned int i = 0; i<=polynom.stepen; i++)
    {
        std::cin>>polynom.numbers[i];
    }

    return polynom;
}

void printPolynom(Polynom& a)
{
    for(unsigned int i=0; i<=a.stepen; i++)
    {
        std::cout<<a.numbers[i]<<"x^"<<i<<" ";
    }
}

void deallocatePolynom(Polynom& a)
{
    delete[] a.numbers;
}

Polynom sum_poly(Polynom a, Polynom b)
{
    Polynom sum;
    if(a.stepen<b.stepen) return sum_poly(b, a);

    //a>b kato stepen

    sum.stepen = a.stepen;
    sum.numbers = new (std::nothrow) double[sum.stepen + 1];

    if(!sum.numbers)
    {
        std::cout<<"problem while allocating memory for polynom";
        sum.stepen = 0;
        return sum;
    }


    unsigned int i=0;
    for(i; i<=b.stepen; i++)
    {
        sum.numbers[i] = a.numbers[i] + b.numbers[i];
    }

    for(i; i<=a.stepen; i++)
    {
        sum.numbers[i] = a.numbers[i];
    }

    return sum;
    
}

int main()
{
    Polynom a = enterPolynom();
    Polynom b = enterPolynom();
    Polynom sum = sum_poly(a,b);
    printPolynom(a);
    std::cout<<" + ";
    printPolynom(b);
    std::cout<<" = ";
    printPolynom(sum);

    deallocatePolynom(a);
    deallocatePolynom(b);
    deallocatePolynom(sum);

}