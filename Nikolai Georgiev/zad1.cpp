// 30т.
#include <iostream>
#include <cstring>

bool ed(char* n){
    bool isFalse = true;
    for(int i = 0; i < strlen(n); i++){
        // Трябва ти n[i] - '0', за да намериш точно цифрата.
        // (int)n[i] -> връща ascii стойността на цифрата, които са следните 0(48)...
        if(((int)n[i]) % 2 != 0){
            // Можеш направо тук да върнеш false.
            // То няма да стане по-false.
            isFalse = false;
        }
    }
    return isFalse;
}

int main(){
    char number[] = "1234";
    
    // std::cin >> number; // Защо е закоментирано?
    std::cout << ed(number);
}