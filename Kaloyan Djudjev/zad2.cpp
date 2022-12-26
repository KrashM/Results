// 30т.
#include <iostream>
bool isHulm(int nums[], int n){
    bool hulm=true;
    for(int i=0; i<n; i++){
        hulm = true;
        int numToTest = nums[i];
            if(numToTest>=1 && numToTest<=n){
                for(int j=0; j<i; j++){
                    if(nums[j]>nums[j+1]){
                        hulm=false;
                        break;
                    }
                }
                for(int j=i; j<n-1; j++){
                    if(nums[j]<nums[j+1]){
                        hulm = false;
                        break;
                    }
                }
            } else hulm = false;
            if(hulm) return hulm;
    }
    return false;
}
    int main(){
    int n;
    std::cin>>n;
    // Валидация за n ти трябва. n < 0?
    // Така не можеш да декларираш статичен масив.
    // Трябва размерът му да е константно число.
    int a[n];
    for(int i=0; i<n; i++){
        std::cin>>a[i];
    }
    std::cout<<isHulm(a,n);
}