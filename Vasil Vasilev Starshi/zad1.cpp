#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;

constexpr size_t MAX_ARR_SIZE = 1024;

bool ed(char* n)
{
    size_t size = strlen(n);
    for (int i = 0; i < size; ++i) {
        if(((n[i]-'0')%2) != 0)
            return false;
    }
    return true;
}
int main() {
    char* n = new char[MAX_ARR_SIZE];
    cin.getline(n,MAX_ARR_SIZE,'\n'); // Обикновен cin върши работа.
    cout << ed(n);
    delete[] n;
    return 0;
}
