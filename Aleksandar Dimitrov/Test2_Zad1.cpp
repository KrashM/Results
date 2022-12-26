// 30т.
#include<iostream>

// Нека не го използваме.
using namespace std;

bool ed(char n[]){
    int i = 0;
    while(n[i] != '\0'){
        if((n[i] - '0') % 2 == 1)
            return false;
        i++;    
    }
    return true;
}

int main(){
    // Липсват само вход и валидация. Иначе топ.
    if(ed("242824"))
        cout<<"True";
    else 
        cout<<"False";
    return 0;
}