#include<iostream>
#include<vector>
#include<algorithm>
#include<complex>
#define MAX 100'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    pair<int,int> p[3];
    fse(0,3,1){
        int x,y;
        cin>>x>>y;
        p[i]={x,y};
    }
    complex<int> v[2];
    fse(0,2,1){
        v[i]= {p[i+1].first-p[i].first, p[i+1].second-p[i].second};
    }
    
    int crossproduct = (conj(v[0])*v[1]).imag();
    if(crossproduct>0) cout<<1;
    else if(crossproduct<0) cout<<-1;
    else cout<<0;
}