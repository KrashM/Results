// 30т.
#include <iostream>

using std::size_t;

// Тип на тази функция?!? XD
strlen(char str[]){

    unsigned int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

bool ed(char n[]){

    for(int i = 0; i < strlen(n); ++i){

        // Това е вярно, но можеше да го напишеш така примерно:
        // (n[i] - '0') % 2 == 1
        if(n[i] != '2' && n[i] != '4' && n[i] != '6' && n[i] != '8' && n[i] != '0'){
            return false;
        }
    }
    return true;
}

int main(){

    char n[255];
    std::cin >> n;
    // Нямаш валидация на числото.

    std::cout << std::boolalpha << ed(n);

}