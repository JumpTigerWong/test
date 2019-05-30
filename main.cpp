#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

//double data[9]={1.0000000,0.9973978,0.9896158,0.9767267,0.9588510,0.9361556,0.9088516,0.8771925,0.8414709};
double f(double x){
    if(x==0) return 1;
    else return (sin(x)/x);
}

double FuhuaTixing(int n,double a,double b){
    double h = (b-a)/n;
    double x = a;
    double s = 0;
    for(int k=0; k< n-1; k++){
        x += h;
        s += f(x);
    }
    double T = (f(a)+s*2+f(b))*h/2;
    return T;
}

int main(){
    cout<<"请输入积分区间(a,b)："<<endl;
    double a;
    double b;
    cin>>a>>b;
    cout<<"请输入等分份数n： "<<endl;
    int n; cin>>n;
    cout<<"由复化梯形公式球的结果："<<FuhuaTixing(n,a,b)<<endl;
}

