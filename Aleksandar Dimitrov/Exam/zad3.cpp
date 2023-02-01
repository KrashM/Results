#include<iostream>
using std::cin;
using std::cout;
using std::endl;

struct Polynom{
    int deg;
    double coef[100];
};

Polynom sum_poly(Polynom a, Polynom b){
    Polynom c;
    if(a.deg >= b.deg)c.deg = a.deg;
    else c.deg = b.deg;

    for(int i = 0; i <= c.deg;i++){
        if(i > a.deg)c.coef[i] = b.coef[i];
        else if(i > b.deg)c.coef[i] = a.coef[i];
        else c.coef[i] = a.coef[i] + b.coef[i];
    }

    return c;
}

int main(){
    Polynom polynomA, polynomB, polynomC;

    //polynomite se vuvejdat kato zapochvat ot koeficienta pred svobodniqt chlen
    cin>>polynomA.deg;
    for(int i = 0;i <= polynomA.deg;i++)
        cin>>polynomA.coef[i];
    
    cin>>polynomB.deg;
    for(int i = 0;i <= polynomB.deg;i++)
        cin>>polynomB.coef[i];

    polynomC = sum_poly(polynomA, polynomB);

    for(int i = 0;i <= polynomC.deg;i++){
        cout<<polynomC.coef[i]<< " ";
    }

    cout<<endl;
    
    return 0;
}