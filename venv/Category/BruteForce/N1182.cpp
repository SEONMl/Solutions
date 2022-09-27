#include<stdio.h>
#include<iostream>
using namespace std;
int N,S,cnt;
int a[21],visit[21];
void dfs(int k,int c,int j){
    if(k!=0&&c==S) cnt++;
    for(int i=j;i<N;i++){
        if(visit[i]==0){
            visit[i]=1;
            c+=a[i];
            dfs(k+1,c,i);
            c-=a[i];
            visit[i]=0;
        }
    }
}
int main(){
    scanf("%d %d",&N,&S);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    dfs(0,0,0);
    printf("%d",cnt);
    return 0;
}