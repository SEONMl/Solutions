#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
int N,M,X,Y,K;
int g[21][21],cmd[1001];
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0}; // 우 좌 상 하
vector<int> dice(7);
void roll(int k){
    switch(k){
    case 1:
        dice={0,dice[4],dice[2],dice[1],dice[6],dice[5],dice[3]};
        break;
    case 2:
        dice={0,dice[3],dice[2],dice[6],dice[1],dice[5],dice[4]};
        break;
    case 3:
        dice={0,dice[5],dice[1],dice[3],dice[4],dice[6],dice[2]};
        break;
    case 4:
        dice={0,dice[2],dice[6],dice[3],dice[4],dice[1],dice[5]};
        break;
    }
}
int main(){
    scanf("%d%d%d%d%d",&N,&M,&X,&Y,&K);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&g[i][j]);
        }
    }
    for(int i=0;i<K;i++) {
        scanf("%d",&cmd[i]);
        if(X+dx[cmd[i]-1]>=N||X+dx[cmd[i]-1]<0||Y+dy[cmd[i]-1]>=M||Y+dy[cmd[i]-1]<0) continue;
        X+=dx[cmd[i]-1];
        Y+=dy[cmd[i]-1];
        roll(cmd[i]);
        printf("%d\n",dice[1]);
        if(g[X][Y]==0) g[X][Y]=dice[6];
        else {
            dice[6]=g[X][Y];
            g[X][Y]=0;
        }
    }
    return 0;
}