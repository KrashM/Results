// 0т.
#include <iostream>
#include <cmath>

struct point
{
    double x;
    double y;
};

double min(double a, double b)
{
    return a<b;
}

int main()
{
    unsigned int n;
    std::cin>>n;
    if(!std::cin)
    {
        std::cout<<"Invalid input";
        return -1;
    }
    // От тук нататък логиката е грешна.
    // Не трябва да слагаме минималните стойности да са 0.
    point temp;
    temp.x=0;
    temp.y=0;
    double minDistX=0;
    double minDistY=0;
    double minX=0;
    double minY=0;
    for (int i = 0; i < n; ++i)
    {
        point p1;
        std::cin>>p1.x>>p1.y;

        if(minDistX>abs(temp.x+p1.x))
        {
            minDistX=abs(temp.x+p1.x);
            minX=min(temp.x,p1.x);
        }

        if(minDistY>abs(temp.y+p1.y))
        {
            minDistY=abs(temp.y+p1.y);
            minY=min(temp.y, p1.y);
        }
        temp.x=p1.x;
        temp.y=p1.y;

    }
    std::cout<<"The sides are: "<<minDistX <<" "<<minDistY;
    if(minY<0)
    {
        std::cout<<"The upper left corner has coordinates "<<minX<<" and "<< minY - minDistY;
    }
    else
    {
        std::cout<<"The upper left corner has coordinates "<<minX<<" and "<< minY + minDistY;
    }
    
    
    return 0;
}