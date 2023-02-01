#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void pivot(int arr[], int size){

    for(int i = 0;i < size; i++){
        for(int j = i+1;j < size;j++){
            if(arr[i] > arr[j]){
                int buf;
                buf = arr[i];
                arr[i] = arr[j];
                arr[j] = buf;
            }
        }
    }
}

int main(){
    int n, x;
    cin>>n>>x;
    int arr[n];
    for(int i = 0;i < n;i++)
        cin>>arr[i];

    pivot(arr, n);

    for(int i = 0;i < n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
    return 0;
}