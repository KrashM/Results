// 30т.
#include <iostream>

using std::cin;
using std::cout;

void swap(double& a, double &b)
{
    double temp = a;
    a = b;
    // b = temp; ти трябва.
    b = a;



}
void BubbleSort(double arr[], size_t n)
{
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = i+1; j < n; j++)
        {
            if(arr[i] > arr[j]) swap(arr[i], arr[j]);
        }
        
    }
    


}

int main()
{
    int n;
    cin >> n;
    // Валидация за n < 2?
    
    double* xarr = new double[n];
    double* yarr = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> xarr[i];
        cin >> yarr[i];
    }
    BubbleSort(xarr,n);
    BubbleSort(yarr,n);

    double length1 = xarr[n-1]- xarr[0];
    double length2 = yarr[n - 1] - yarr[0];

    // Тук горен ляв ъгъл ще ти е xarr[0] и yarr[n - 1].
    cout << xarr[0] + length1 <<" "<< xarry[0]+length2<<" " << length1<<" " << length2;

    delete[] xarr;
    delete[] yarr;







}