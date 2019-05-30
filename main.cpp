#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double f(double x){
    if(x==0) return 1;
    else return (sin(x)/x);
}

int main() {
    double T[2]={0};
    double S[2]={0};
    double C[2]={0};
    double R[2]={0,1000};
    double a,b,e,h,x=0;
    int Rk=0;
    cin>>a>>b;
    cin>>e;
    h=b-a;
    T[1]=(f(a)+f(b))*h/2;
    int k=1;
    while (1){
        S[0]=0;
        x=a+h/2;
        while(x<b){
            S[0]+=f(x);
            x+=h;
        }
        T[1]=(T[0]+S[0]*h)/2;
        S[1]=T[1]+(T[1]-T[0])/3;
        h/=2;
        T[0]=T[1];
        S[0]=S[1];
        C[0]=C[1];
        R[0]=R[1];
        if(k==1){
            k++;
            continue;
        }
        C[1]=S[1]+(S[1]-S[0])/15;
        if(k==2){
            k++;
            continue;
        }
        R[1]=C[1]+(C[1]-C[0])/63;
        if(k==3){
            k++;
            continue;
        }
        if(abs(R[1]-R[0])<e)break;
    }
    cout<<k<<endl;
    cout<<R[1]<<endl;
}