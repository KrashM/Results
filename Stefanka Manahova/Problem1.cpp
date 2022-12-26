// 34т.
#include <iostream>

using std::cin;
using std::cout;
using std::size_t;

size_t strlen (char* str) {
    size_t count = 0;

    while (str[count] != '\0') {
        count++;
    }

    return count;
}

bool isDigit (const char &c) {
    return c >= '0' && c <= '9';
}

bool isCorrectNumber (char* n) {
    if (!isDigit(n[0]) || n[0] == '0') {
        return false;
    }

    size_t i = 1;

    while (n[i] != '\0')
    {
        if (!isDigit(n[i])) {
            return false;
        }

        i++;
    }
    
    return true;
}

bool leq (char* n1, char* n2) {
    size_t size1 = strlen(n1);
    size_t size2 = strlen(n2);

    if (size1 > size2) {
        return false;
    }

    if (size1 < size2) {
        return true;
    }

    //if size1 == size2
    for (size_t i = 0; i < size1; i++)
    {
        if(n1[i] < n2[i]) {
            return true;
        }

        if (n1[i] > n2[i]) {
            return false;
        }
    }
    
    return true;
}

int main () {
    const size_t MAX_SIZE = 256;

    char n1[MAX_SIZE], n2[MAX_SIZE];

    do {
        cin >> n1 >> n2;

    } while (!isCorrectNumber(n1) || !isCorrectNumber(n2));

    cout << std::boolalpha << leq(n1, n2);

    return 0;
}