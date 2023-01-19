// Overall добра задача, но има неща за оправяне.
// Също така може да се поизчисти малко main-а,
// като се напишат функции за сортировка и вход примерно
// Липсва също така валидация за входа.
// 10т.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//Донякъде работи, но трябва директно да се въведат 6-цифрените числа

const int MAX_CAPACITY = 6;

void printCard(int arr[][MAX_CAPACITY])
{
    for(int i = 0; i < MAX_CAPACITY; i++)
    {
    cout << "(";    
    switch(arr[1][i])
    {
    case 1:
    cout << "YELLOW";
    break;
    case 2:
    cout << "GREEN";
    break;
    case 3:
    cout << "BLUE";
    break;
    case 4:
    cout << "RED";
    break;
    // На черните не се принти цвета.
    case 5:
    cout << "BLACK";
    break;
    }

    cout << ' ';

    switch(arr[0][i])
    {
        case 10:
        cout << "+2";
        break;
        case 11:
        cout << "REVERSE";
        break;
        case 12:
        cout << "STOP";
        break;
        case 13:
        cout << "CHANGE COLOR";
        break;
        case 14:
        cout << "+4";
        break;

        default:
        cout << arr[0][i];
        break;
    }
    cout << ")";
    }
}

int main()
{
    /*int n;
    cout << "Enter the number of codes you want to input" << endl;
    cin >> n;*/

    // Трябваше да е динамичен масива.
    // Плюс трябваше да си го направиш от числа за по-лесно.
    // Пък и ако вкарам по-дълго число(невалидно), ще се счупи.
    char inputArr[MAX_CAPACITY][7];
    // На теб ти е казано, че ще ти се въведе, колко карти ще имаш.
    // Къде е този размер? Ние винаги врътим до MAX_CAPACITY.
    for(int i = 0; i < MAX_CAPACITY; i++)
    {
        cin >> inputArr[i];
    }

    int arr[2][MAX_CAPACITY];
    for(int i = 0; i < MAX_CAPACITY; i++)
    {
        arr[0][i] = (inputArr[i][3] - '0') * 10 + inputArr[i][4] - '0';
        arr[1][i] = inputArr[i][0] - '0';
    }

    for(int i = 0; i < MAX_CAPACITY - 1; i++)
    {
        for(int j = 0; j < MAX_CAPACITY - i - 1; j++)
        {
            if(arr[1][j] < arr[1][j + 1])
            {
                std::swap(arr[0][j], arr[0][j + 1]);
                std::swap(arr[1][j], arr[1][j + 1]);
            }
        }
    }
    // Двете сортировки са грешно направени.
    // Ти първо сортираш по стойност.
    // И после по цвят. Трябва да е едновременно и ако стойността
    // е една и съща тогава да сравняваш цветовете.
     for(int i = 0; i < MAX_CAPACITY - 1; i++)
    {
        for(int j = 0; j < MAX_CAPACITY - i - 1; j++)
        {
            if(arr[0][j] > arr[0][j + 1])
            {
                std::swap(arr[0][j], arr[0][j + 1]);
                std::swap(arr[1][j], arr[1][j + 1]);
            }
        }
    }

    printCard(arr);
    
    return 0;
}