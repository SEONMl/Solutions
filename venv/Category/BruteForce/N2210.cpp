#include<iostream>
#include<set>
#include<string>
using namespace std;
int a[5][5];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
set<string> ans;
void dfs(int x,int y,string tmp){
    tmp+=to_string(a[x][y]);
    if(tmp.length()==6){
        ans.insert(tmp);
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(0<=nx&&nx<5&&0<=ny&&ny<5){
            dfs(nx,ny,tmp);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            dfs(i,j,"");
        }
    }
    cout<<ans.size();
return 0;
}