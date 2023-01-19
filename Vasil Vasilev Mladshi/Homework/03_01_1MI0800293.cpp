// Overall супер.
// Малко сложна имплементация с тези string-ове.
// 20т.
#include <iostream>

using std :: cout;
using std :: cin;
using std :: endl;

struct Dwarf
{
    short firstSection = 0, secondSection = 0;
};

void FillDwarfValues (Dwarf &x, char string[], int &i);
void setDwarfValuesToNill (Dwarf &x);

int main () {

    int n, currentNumber = 1, counter = 0, i = 0;
    Dwarf first;
    Dwarf second;
    
    // Нямаш защита от проблем с паметта.
    // Не си въвел още n!!
    // Защо числата ги въвеждаш като string-ове?
    char *input = new char(n);
    // char input[255];

    cout << "Input the ammount of pairs: ";
    cin >> n;
    cin.ignore(n, '\n');
    cout << endl;

    while(n > 0) {

        cout << "Input pair number " << currentNumber << ": ";
        cin.getline(input, 255);
        cout << endl;

        FillDwarfValues (first, input, i);
        FillDwarfValues (second, input, i);

        // Липсват ти равнота на втората част.
        if ((first.firstSection <= second.firstSection && first.secondSection >= second.secondSection) || (first.firstSection > second.firstSection && first.secondSection < second.secondSection)){
            counter ++;
        }

        setDwarfValuesToNill(first);
        setDwarfValuesToNill(second);
        i = 0;

        currentNumber ++;
        n--;

    }

    cout << "The ammount of overlapping pairs is: " << counter;

    // cout << first.firstSection << first.secondSection << second.firstSection << second.secondSection << endl;

    // FillDwarfValues(first, test, i);
    // FillDwarfValues(second, test, i);
    // cout << first.firstSection << first.secondSection << endl;

    // delete[] ти трябва.
    delete input;

    return 0;
}

void FillDwarfValues (Dwarf &x, char string[], int &i){
    // cout <<endl<< "Here is 'i' at the beginning of the function: " << i << endl;
    while (string[i] != ' ')
        {
            x.firstSection *= 10;
            x.firstSection += int(string[i] - '0');
            i++;
            // cout <<endl<< "Here is 'i' at each iteration of the first while: " << i << endl; 
        }
    i++;
    // cout <<endl<< "Here is 'i' at the end of the first while: " << i << endl; 
    while (string[i] != ' ' && string[i] != '\0')
        {
            x.secondSection *= 10;
            x.secondSection += int(string[i] - '0');
            i++;
            // cout <<endl<< "Here is 'i' at each iteration of the second while: " << i << endl; 
        }
    i++;
    // cout <<endl<< "Here is 'i' at the end of the second while: " << i << endl; 
}

void setDwarfValuesToNill (Dwarf &x){
    x.firstSection = 0;
    x.secondSection = 0;
}