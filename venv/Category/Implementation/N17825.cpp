#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define MAX 33
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int dice[10];
int score[MAX];
int answer=0;
int getNextPos(int cur,bool start){
    if(cur==5 && start) return 21;
    if(cur==10 && start) return 25;
    if(cur==15 && start) return 27;
    if(cur==26||cur==29) return 24;
    if(cur==24) return 30;
    if(cur==31) return 20;
    if(cur==20) return 32;
    if(cur==32) return 32;
    return cur+1;
}
bool isNotEmpty(int idx, vector<int> &zzol){
    if(idx==0 || idx==32) return false;
    for(int z:zzol){
        if(z==idx) return true;
    }return false;
}
int go(int cur, int count){
    cur=getNextPos(cur,true);
    count--;
    while(count--){
        cur=getNextPos(cur,false);
    }
    return cur;
}
void dfs(int depth, int total, vector<int> zzol){
    if(depth==10){
        answer=max(answer, total);
        return;
    }
    for(int i(0);i<4;i++){
        int next=go(zzol[i], dice[depth]);
        if(isNotEmpty(next, zzol)) continue;
        int tmp=zzol[i];
        zzol[i]=next;
        dfs(depth+1, total+score[next], zzol);
        zzol[i]=tmp;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fse(0,10,1) cin>>dice[i];

    vector<int> zzol(4,0); // 위치
    fse(0,21,1) score[i]=i*2;
    score[21]=13; score[22]=16; score[23]=19; score[24]=25;
    score[25]=22; score[26]=24; score[27]=28; score[28]=27; score[29]=26;
    score[30]=30; score[31]=35; score[32]=0;//도착

    dfs(0,0,zzol);
    cout<<answer;
}