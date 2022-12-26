// 30т.
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    // Валидация за n < 2.
   
    double x[n], y[n];
    double minX, minY, maxX, maxY; 
    cin>>x[0]>>y[0];
    minX = x[0];
    maxX = x[0];
    minY = y[0];
    maxY = y[0];
    
    for(int i = 1;i < n;i++){
        cin>>x[i]>>y[i];
        if(x[i] > maxX)maxX = x[i];
        if(x[i] < minX)minX = x[i];
        if(y[i] > maxY)maxY = y[i];
        if(y[i] < minY)minY = y[i];
    }

    if(maxX - minX > maxY - minY)cout<<(maxX - minX) * (maxX - minX);
    else cout<<(maxY - minY) * (maxY - minY);

    return 0;
}