#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void removeUpper (char *s){
    int i = 0;
    while(s[i] != '\0'){
        if(!isupper(s[i]))cout<<s[i];
        i++;
    }
    cout<<endl;
}

int main(){
    //Da izberem goleminata na char array-a
    const int size = 100;
    char *c[size];
    cin.getline(*c, 100);
    removeUpper(*c);
    return 0;
}