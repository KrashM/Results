// Като цяло е ок задачата, но има къде да се оправи.
// 15т.
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;

// Returns length of string

int myStrLen(char *string)
{
    int i = 0;

    while(string[i]) i++;
    return i;
}

// Lets the user enter strings

void enterStrings(char **stringMat, int strings, int size)
{

    for (unsigned int i = 0; i < strings; i++)
    {
        // If the string is longer than 30 characters, asks again.

        // Не се пише така валидация!
        do
        {

            cout << "Enter string #" << i + 1 << ": ";
            // Ако тука го напишеш да ти вкарва size елемента...
            cin.getline(stringMat[i], 255);
            // няма да имаш нужда от тази проверка.
            if(myStrLen(stringMat[i]) > size) cout << "Too long! \n";

        // И от този цикъл също.
        } while (myStrLen(stringMat[i]) > size);

    }
}

// Prints the strings after they've been sorted

void printStrings(char **stringMat, int strings)
{
    for (unsigned int i = 0; i < strings; i++) cout << stringMat[i] << '\n';

}

// Compares the strings lexicographically

bool compStrings(char *str1, char *str2) {

    int minLen = 0;

    if(myStrLen(str1) > myStrLen(str2)) minLen = myStrLen(str2);
    else minLen = myStrLen(str1);

    for(unsigned int i = 0; i < minLen; i++){

        if(str1[i] == str2[i]) continue;

        // Тук имаме проблем ако имаш 'T' и 't'.
        // Защото лексикографски са една и съща буква а по ascii таблицата не са.
        if(str1[i] > str2[i]) return true;

        if(str1[i] < str2[i]) return false;
    }

    // Тука ти трябва да провериш дали не са с различна дължина.
    // Пример: little, littles
    return false;

}

// Sorts the strings lexicographically

void sortByAlphab(char **stringMat, int strings)
{

    // Insertion sort

    char* temp = new char[30];
    int j = 0;
    
    for (int i = 1; i < strings; i++)
    {

        j = i - 1;
        strcpy(temp, stringMat[i]);
        
        while(j >= 0 && compStrings(stringMat[j], temp)) {

            strcpy(stringMat[j + 1], stringMat[j]);
            j--;
        }

        strcpy(stringMat[j + 1], temp);

    }

    delete[] temp;
}

int main()
{

    // Initializing:

    int strings = 50, size = 30;
    cout << "Enter strings: ";
    cin >> strings;
    cin.ignore();
    // Първо не проверяваш и за > 50.
    // Второ трябва да приключиш с един return тука,
    // иначе програмата си продължава без проблем.
    if(strings <= 0) cout << "This input is invalid \n";

    // Allocating:

    // Нямаш nothrow
    char **stringMatrix = new char *[strings];

    if(!stringMatrix) {

        cout << "Problem while allocating \n";
        return 1;
    }

    for (unsigned int i = 0; i < strings; i++)
    {

        // Пак нямаш nothrow
        stringMatrix[i] = new char[size + 1];

        if(!stringMatrix[i]) {

            cout << "Problem while allocating \n";
            return 1; // Memory leak

        }
        
    }

    // Main part:

    enterStrings(stringMatrix, strings, size);
    sortByAlphab(stringMatrix, strings);
    printStrings(stringMatrix, strings);

    // Deallocating:

    for (unsigned int i = 0; i < strings; i++)
    {

        // delete[]!
        delete stringMatrix[i];
    }

    delete[] stringMatrix;

    return 0;

}