// Много добре е задачата!
// Минимални проблеми.
// 22т.
#include<iostream>
#include<cstring>
using namespace std;
void sort(char texts[][30],int size){
    char swap[30];
    for (int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size-i-1; j++){
            char s1[30];
            for(int k=0; texts[j][k]!='\0'; k++){
                s1[k]=tolower(texts[j][k]);
            }
            char s2[30];
            for(int k=0; texts[j+1][k]!='\0'; k++){
                s2[k]=tolower(texts[j+1][k]);
            }
            if(strcmp(s1,s2)>0){
                strncpy(swap, texts[j+1],30);
                strncpy(texts[j+1],texts[j],30);
                strncpy(texts[j],swap,30);
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    if(n>50){ // n < 0 Също.
        cout<<"Nekorekten vhod";
        return 0;
    }
char texts[n][30]; // Не можеш да правиш статичен масив с динамичен размер.
cin.ignore(1,'\n');
for(int i=0; i<n; i++){
    cin.getline(texts[i],30);
}
sort(texts,n);
cout<<endl;
for(int i=0; i<n; i++){
    printf(texts[i]);
    cout<<endl;
}
return 0;
}