// 30т.
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool isTrion(int arr[], size_t n)
{
    bool istrion = false;

    // -2 е достатъчно, с -3 изпускаш последната тройка числа.
    for (size_t i = 0; i < n-3; ++i)
    {
        if(arr[i] <= arr[i+1] && arr[i+1]>=arr[i+2] || arr[i]>=arr[i+1] && arr[i+1]<=arr[i+2])
        {
            istrion = true;
        }
        // В else-а трябва да направиш и че редицата вече не е трион.
        // Пример къде ще се счупи:
        // 1 3 2 4 5 6
        // При 1 3 2 ще го напрвиш true.
        // След това ще се счупи и ще върнеш true.
        else break;
    }

 return istrion;
}
int main()
{
    size_t n;
    cout << "n= ";
    cin >> n;
    

    int* arr = new int[n];

    cout << "array= ";

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << isTrion(arr, n);

    
    

delete[] arr;


}