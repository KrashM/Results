// 34т.
#include <iostream>

int main(){

    double x, y;
    unsigned int n;
    std::cin >> n;

    if(n > 1000)
    return 1;

    // Тук има по-адекватен начин да ги занулиш.
    // Въведи си първата двойка кординати и тях ги сложи за стартови стойност.
    double minX, minY = 99999;
    double maxX, maxY = -99999;

    for(int i = 0; i < n; ++i){

        std::cin >> x >> y;

        if(x < minX){
            minX = x;
        }
        if(y < minY){
            minY = y;
        }
        if(x > maxX){
           maxX = x;
        }
        if(y > maxY){
           maxY = y;
        }  
    }
    double minSide = 0;
    if((maxX - minX) > (maxY - minY)){
        minSide = (maxX - minX);
    }else{
        minSide = (maxY - minY);
    }

    std::cout << minSide * minSide;

}