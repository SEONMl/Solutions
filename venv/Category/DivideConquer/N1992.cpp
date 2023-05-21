#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 64
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N, g[MAX][MAX];
void dq(int size, pair<int,int> start, pair<int,int> end){
    int x1=start.first, y1=start.second, x2=end.first, y2=end.second;
    int cur=g[x1][y1];
    if(size==1){
        cout<<cur;
        return;
    }

    bool flag=true;
    for(int i(x1);i<x2;i++){
        for(int j(y1);j<y2;j++){
            if(cur==g[i][j]) continue;
            flag=false;
            break;
        }
        if(!flag) break;
    }

    if(flag){
        cout<<cur;
        return;
    }else{
        int midX=(x1+x2)/2;
        int midY=(y1+y2)/2;
        cout<<"(";
        dq(size/2, start, {midX,midY});
        dq(size/2, {x1, midY}, {midX,y2});
        dq(size/2, {midX,y1}, {x2,midY});
        dq(size/2, {midX, midY}, end);
        cout<<")";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    char c;
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            cin>>c;
            g[i][j]=c-'0';
        }
    }
    dq(N, {0,0}, {N,N});
}