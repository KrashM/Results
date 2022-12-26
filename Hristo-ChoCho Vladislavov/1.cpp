// 30т.
#include <iostream>

int charLen(unsigned char n[]) {

    int num = 0;

    for(int i = 0; n[i] != '\0'; i++) num++;

    return num;

}

bool leq(unsigned char n1[], unsigned char n2[]) {

    if(charLen(n1) < charLen(n2)) return true;
    else if(charLen(n1) > charLen(n2)) return false;
    else {
        for(int i = 0; n1[i] != '\0'; i++) {

            if(n1[i] < n2[i]) return true;
            else if(n1[i] > n2[i]) return false;

        }
        return true;
    }
}

int main() {

    int MAX_NUM = 1000;

    unsigned char n1[MAX_NUM], n2[MAX_NUM];

    std::cin >> n1 >> n2;

    // Нямаш валидация на числата.
    // Какво ще стане ако въведа "29uhoa8202ih"?

    std::cout << leq(n1, n2) << std::endl;

    return 0;
}
