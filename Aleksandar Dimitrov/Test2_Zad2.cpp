// 30т.
#include<iostream>

// Нека не го използваме.
using namespace std;

bool PeakCheck(int n, int arr[]){
    bool peak = false;
    for(int i = 1;i < n;i++){
        if(arr[i] > n)return false;
        if(arr[i] < arr[i-1] && !peak)peak = true;
        if(arr[i] > arr[i-1] && peak == true)return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    // Проверка за n < 0?

    // Това е статичен масив, не можеш да му даваш неконстантен size.
    int arr[n];
    for(int i = 0;i < n;i++)
        cin>>arr[i];
    
    if(PeakCheck(n, arr))cout<<"True";
    else cout<<"False";

    return 0;
}