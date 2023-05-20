#include<iostream>
#include<vector>
#include<algorithm>
#define INF 2'100'000'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    vector<pair<int,int>> v;
    fse(0,N,1){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    int start=INF, end=-INF, length=0;
    for(auto cur:v){
        int x=cur.first;
        int y=cur.second;
        if(end>=x){
            end=max(end, y);
        }else{
            if(start!=INF) length+=end-start;
            start=x;
            end=y;
        }
    }
    length+=end-start;
    cout<<length;
}