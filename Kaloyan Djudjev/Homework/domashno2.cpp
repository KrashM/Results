// Идеална задача. Само проверките.
// 24т.
#include <iostream>
using namespace std;
    int main(){
    int elfCount, foodCount,calories,maxCalories=0,sum=0,maxElf=1;
    cin>>elfCount;
    if(elfCount<=0){ // > 100 Също.
    cout<<"Nekoreten vhod";
    return 0;
}
    for(int i=0; i<elfCount; i++){
        cin>>foodCount;
        if(foodCount<=0){ // > 20 Също.
            cout<<"Nekoreten vhod";
            return 0;
        }
        for(int j=0; j<foodCount; j++){
            cin>>calories;
            if(calories<0){
            cout<<"Nekoreten vhod";
            return 0;
            }
            sum+=calories;
        }
        if(sum>=maxCalories){
            maxCalories = sum;
            maxElf=i+1;
        }
        sum=0; 
    }
    cout<<maxElf<<endl<<maxCalories;
    return 0;
}