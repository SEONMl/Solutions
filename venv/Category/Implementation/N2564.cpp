#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 101
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int g[MAX][MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;

    for(int i(0);i<N;i++){
        int x,y;
        cin>>x>>y;
        g[x][y]+=1;
        g[x+10][y]+=-1;
        g[x][y+10]+=-1;
        g[x+10][y+10]+=1;
    }
    for(int i(1);i<MAX;i++){
        for(int j(0);j<MAX;j++){
            g[i][j]+=g[i-1][j];
        }
    }
    for(int i(1);i<MAX;i++){
        for(int j(0);j<MAX;j++){
            g[j][i]+=g[j][i-1];
        }
    }
    int cnt=0;
    for(int i(0);i<MAX;i++){
        for(int j(0);j<MAX;j++){
            if(g[i][j]!=0) cnt++;
        }
    }
    cout<<cnt;
}