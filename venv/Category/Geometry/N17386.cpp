#include<iostream>
#include<vector>
#include<algorithm>
#include<complex>
#define MAX 100'000
#define C long long
#define P complex<C>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    C x1,y1,x2,y2;
    C p1,q1,p2,q2;
    cin>>x1>>y1>>x2>>y2;
    cin>>p1>>q1>>p2>>q2;
    P pivot = {x2-x1, y2-y1};
    P a={p1-x1, q1-y1};
    P b={p2-x1, q2-y1};

    C cp1 = (conj(pivot)*a).imag();
    C cp2 = (conj(pivot)*b).imag();

    if((cp1>0&&cp2<0)||(cp1<0&&cp2>0)) cout<<1;
    else cout<<0;

}