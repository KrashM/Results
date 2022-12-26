// 25т.
#include <iostream>

int main(){
 int pointsNum;
 std::cin>>pointsNum;
//  Валидация за pointsNum < 2?
// Не можеш така да декларираш статичен масив!
// Плюс масива трябва да ти е от тип double.
 int points[2*pointsNum];
 for(int i=0; i<2*pointsNum; i++){
    std::cin>>points[i];
 }
//  Трябваше да ги занулиш, като им сложиш първата двойка кординати.
 int minX = 999999;
 int maxX = -999999;
 for(int i=0; i<2*pointsNum; i+=2){
    if(minX>=points[i]) minX=points[i];
    if(maxX<=points[i]) maxX=points[i];
 }
// Трябваше да ги занулиш, като им сложиш първата двойка кординати.
 int minY = 999999;
 int maxY = -999999; 

 for(int i=1; i<2*pointsNum; i+=2){
    if(minY>=points[i]) minY=points[i];
    if(maxY<=points[i]) maxY=points[i];
 }
//  Нямаш нужда от abs max - min винаги е положително.
 int squareSide = max(abs(maxX-minX), abs(maxY-minY));
 std::cout<<squareSide*squareSide;
}