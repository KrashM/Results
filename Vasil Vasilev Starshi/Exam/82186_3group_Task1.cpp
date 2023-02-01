#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;

void removeUpper(char* s)
{
    int i = 0;
    int i1;
    int count = 0;
    while(s[i]!='\0')
    {
        if(s[i] > 'A' && s[i] < 'Z')
        {
            i1 = i;
            count++;
            while(s[i1+1]!='\0')
            {
                s[i1] = s[i1+1];
                i1++;
            }
        }
        i++;
    }
    while(count != 0)
    {
        s[--i] = '\0';
        count--;
    }
}

constexpr size_t sizeOfArray = 13;

int main() {
    char* inputString = new char[sizeOfArray];
    for (int i = 0; i < sizeOfArray; ++i) {
        inputString[i] = '\0';
    }
    cin.getline(inputString,sizeOfArray,'\n');
    removeUpper(inputString);
    int i = 0;
    while(inputString[i]!='\0')
    {
        cout << inputString[i];
        i++;
    }
    return 0;
}
