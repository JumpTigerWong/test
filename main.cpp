#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    double x[5]={165,123,150,123,141};//x
    double lnx[5]={187,126,172,125,148};//y
//    double x[5]={0.4,0.5,0.6,0.7,0.8};//x
//    double lnx[5]={-0.9163,-0.6931,-0.5108,-0.3567,-0.2231};//y
    double a,b,subx=0,suby=0,subx_2=0,subxy=0;
    for(int i=0;i<5;i++){
        subx+=x[i];
        suby+=lnx[i];
        subx_2+=x[i]*x[i];
        subxy+=x[i]*lnx[i];
    }
    b=(subxy-subx*suby/n)/(subx_2-subx*subx/n);
    a=(suby-b*subx)/n;
    cout<<"拟合函数为:"<<"y="<<b<<"x"<<a<<endl;
}