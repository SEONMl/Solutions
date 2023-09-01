#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int distance(int x,int y,int a,int b){
    return (x-a)*(x-a)+(y-b)*(y-b);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        int M;
        cin>>M;
        int in=0, out=0;
        fse(0,M,1){
            int x,y,r;
            cin>>x>>y>>r;
            if(distance(x,y,x1,y1)<r*r && distance(x,y,x2,y2)>r*r) out++;
            if(distance(x,y,x1,y1)>r*r && distance(x,y,x2,y2)<r*r) in++;
        }
        cout<<in+out<<'\n';
    }
}