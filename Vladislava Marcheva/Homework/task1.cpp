// Задачата е топ!
// Минимален проблем със знаците.
// Единствено може да се поизчисти малко да не е всичко в main-а.
// 25т.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::size_t;

int main()
{
    unsigned int n;
    cout << "Enter how many pairs you want to input" << endl;
    cin >> n;

    unsigned int start1, end1, start2, end2;
    int counter  = 0;

    
    
    for(size_t i = 0; i < n; i++)
    {
        cin >> start1 >> end1 >> start2 >> end2;
        // Тука са без равнотата.
        if(start1 >= end1 || start2 >= end2)
        {
        cout << "Invalid input";
        return 1;
        }

        // Тука обаче ти трябва равно XD.
        // Можеше да ги запишеш с един or двете условия.
        if(start1 > start2 && end1 < end2)
        counter ++;
        else if(start2 > start1 && end2 < end1)
        counter ++;
    }

    cout << "Overlapping pairs are:" << ' ' << counter;

    return 0;
}

