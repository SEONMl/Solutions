#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;
char giho[]={'+','-',' '};
int calculate(int idx,int a,int b){
    switch (idx)
    {
    case 0: return a+b;
    case 1: return a-b;
    case 2: return a*10+b;
    
    default:
        break;
    }
}
void dfs(int start, int cur, string susic){
    if(start==N){
        if(cur==0){
            cout<<susic<<'\n';
        }
        return;
    }

    fse(0,3,1){
        string tmp=susic+giho[i]+to_string(start+1);
        dfs(start+1, calculate(i, start, start+1), tmp);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        dfs(1, 1, "1");
        cout<<'\n';
    }
}

// 1-23+4+5+6+7 23