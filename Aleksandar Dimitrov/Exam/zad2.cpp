#include<iostream>
using std::cin;
using std::cout;
using std::endl;

struct int_array {  
    int arr[100]; 
    unsigned int size; 
};

int_array filter_events(int_array a){
    int_array b;
    int j = 0;
    for(int i = 0;i < a.size;i++){
        if(a.arr[i] % 2 == 0){
            b.arr[j] = a.arr[i];
            j++;
        }
    }
    b.size = j;

    return b;
}

int main(){
    int_array myArr;
    int_array newArr;
    cin>>myArr.size;

    for(int i = 0;i < myArr.size;i++)
        cin>>myArr.arr[i];

    newArr = filter_events(myArr);

    for(int i = 0;i < newArr.size;i++)
        cout<<newArr.arr[i]<<" ";

    cout<<endl;
    return 0;
}