// 25т.
#include<iostream>
bool ed(char n[], int size){
    for(int i=0; i<size; i++){
        if((n[i]-'0')%2!=0){
            return false;
        }
    }
return true;
}

int main(){
    // Въвеждаме само числото, никакъв size преди това.
   int size;
   std::cin>>size;
   char digits[size];
   for(int i=0; i<size; i++){
        // Така като го правиш трябва всяка цифра да ти е на отделен ред.
        std::cin>>digits[i];
        // Ако е равно на 9 е ок. Иначе при некоректния вход направо трябваше да прекъснеш програмата.
        if(digits[i]-'0'>=9 || digits[i]-'0'< 0){
            std::cout<<"Nekorekten vhod";
        }
        break; // Чупи цикъла след първата итерация.
   }
   std::cout<<ed(digits,size);
}