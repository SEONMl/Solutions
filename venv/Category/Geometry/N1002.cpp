#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T>0){
        int x1,y1,r1,x2,y2,r2, d;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        d=(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        int cond1=(r1+r2)*(r1+r2);
        int cond2=(r1-r2)*(r1-r2);
        int ans;
        if(d==0){
            if(r1==r2) ans=-1;
            else ans=0;
        }
        else if(d==cond1 ||d==cond2) ans=1;
        else if(d>cond2&&d<cond1) ans=2;
        else ans=0;
        
        cout<<ans<<'\n';

        T--;
    }
}