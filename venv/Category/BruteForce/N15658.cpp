#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define INF 1'000'000'001
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,minA=INF,maxA=-INF;
vector<int> arr;
vector<int> giho;
int calculate(int i, int a, int b){
    switch (i)
    {
    case 0: return a+b;
    case 1: return a-b;
    case 2: return a*b;
    case 3: return a/b;
    }
}
void dfs(int idx, int now){
    if(idx==N){
        minA=min(minA, now);
        maxA=max(maxA, now);
        return;
    }

    fse(0,4,1){
        if(giho[i]==0)continue;
        giho[i]--;
        dfs(idx+1, calculate(i, now, arr[idx]));
        giho[i]++;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    int tmp;
    fse(0,N,1){
        cin>>tmp;
        arr.push_back(tmp);
    }
    fse(0,4,1){
        cin>>tmp;
        giho.push_back(tmp);
    }
    dfs(1,arr[0]);

    cout<<maxA<<'\n'<<minA;
}