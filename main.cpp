#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x[5]={0.4,0.5,0.6,0.7,0.8};//x
    double lnx[5]={-0.9163,-0.6931,-0.5108,-0.3567,-0.2231};//y
    int num;
    double xi;
    cout<<"请输入样本点个数:";
    cin>>num;
    cout<<"请输入一个值:";
    cin>>xi;
    double result=0;
    for(int i=0;i<num;i++){
        double formal=0;
        for(int k=0;k<=i;k++){
            double xn=1;
            for(int j=0;j<=i;j++){
                if(k!=j){
                    xn*=(x[k]-x[j]);
                }
            }
            formal+=(lnx[k]/xn);
        }
        double last=1;
        for(int c=0;c<i;c++){
            last*=(xi-x[c]);
        }
        result+=(formal*last);
    }
    cout<<result<<endl;
}

