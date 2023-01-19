// Задачата си е перфектна!
// 25т.
#include <iostream>
#include <cstring>

using std::cin; 
using std::cout; 

const int MAX_LINES = 50;
const int MAX_LENGTH = 30; // 31
const int UPPER_LOWER_DIFF = 'a' - 'A';

bool validate (int n){
    return n > 0;
}

int tolower (char c){
    if (c >= 'A'  && c <= 'Z') return c + UPPER_LOWER_DIFF; 
    return  c;
}

int ignore_case_cmp(const char* str1, const char* str2) {
    int i = 0;
    while (tolower(str1[i]) == tolower(str2[i]) && str1[i] != '\0') i++; 
    return tolower(str1[i]) - tolower(str2[i]);
}

void sort_strings(char* str [], const size_t size) {
    char temp[MAX_LENGTH];

    //Bubble Sort
    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            int cmp = ignore_case_cmp(str[i], str[j]); // Умно!
            if (cmp > 0){
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
}

int main()
{
    int n;
    char* lines[MAX_LINES];

    std::cout << "Number of lines: ";
    std::cin >> n;
    if (n > 50 || !validate(n)) return -1;

    std::cin.ignore(); 

    std::cout << "Enter the lines: " << '\n';
    for (size_t i = 0; i < n; ++i){

        lines[i] = new(std::nothrow) char[MAX_LENGTH];
        std::cin.getline(lines[i], sizeof(lines) - 1);
        // sizeof(lines) = 8 * MAX_LINES - 1 = 399???
        // Тук ти трябва само MAX_LENGTH.

    }

    sort_strings(lines, n);

    cout << '\n';
    for (size_t i = 0; i < n; ++i) 
        std::cout << lines[i] << '\n';


    for (size_t i = 0; i < n; ++i) 
        delete[] lines[i];

    return 0;
}
