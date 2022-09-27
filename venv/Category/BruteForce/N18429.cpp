#include<stdio.h>
#include<iostream>
using namespace std;
int N,K,cnt;
int a[9];
int visit[9];
void dfs(int d,int c){
    if(d==N-1){
        if(c>=0)
            cnt++;
    }
    if(c<0) return ;
    for(int i=0;i<N;i++){
        if(visit[i]==0){
            visit[i]=1;
            dfs(d+1,c+a[i]-K);
            visit[i]=0;
        }
    }
}
int main(){
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    dfs(0,0);
    printf("%d",cnt);
return 0;
}
// c++과 친해지는 중...