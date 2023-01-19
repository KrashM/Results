// 0т.
#include <iostream>
#include <cstring>
//void alpfaOrder(char myArray[50][31]){


//}
int main(){
    char myArray[50][31];
    int temp, randomNumber;
    std::cout<<"Enter a number"<<std::endl;
    std::cin>> randomNumber;
     for(int i=0;i<randomNumber+1;i++){
       for(int j;j<31;j++){
         std::get>> myArray[i][j];
       }
     }
     
    return 0;
}