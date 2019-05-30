#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

double f(double x,double y){
    return y-2*x/y;
}
int main() {
    double x0,x1,y0,y1,h;
    int N,n=1;
    double yp,yc;
    cin>>x0;
    cin>>y0;
    cin>>h;
    cin>>N;
    double y[50];
    y[0]=1;
    cout<<"xn      yn    "<<endl;
    while(n<N){
        x1=x0+h;
        yp=y0+h*f(x0,y0);
        yc=y0+h*f(x1,yp);
        y1=(yp+yc)/2;
        y[n]=y[n-1]+h*f(x1,y1);
        x0=x1;
        y0=y1;
        n++;
        cout<<x1<<" "<<y1<<endl;
    }
}