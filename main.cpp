#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x[5]={0.4,0.5,0.6,0.7,0.8};//x
    double lnx[5]={-0.9163,-0.6931,-0.5108,-0.3567,-0.2231};//y
    double y=0;
    double num;
    int a;
    cout<<"请输入样本个数:";
    cin>>a;
    cout<<"请输入一个值:";
    cin>>num;
    for(int k=0;k<a;k++){
        double t=1;
        for(int i=0;i<a;i++){
            if(i==k){
                if(i==k&&k==a-1){
                    break;
                }
                i++;
                t*=(num-x[i])/(x[k]-x[i]);
            }else{
                t*=(num-x[i])/(x[k]-x[i]);
            }
        }
        y+=t*lnx[k];
    }
    cout<<y<<endl;
}