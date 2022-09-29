#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,H,a,b;
int main(){
    scanf("%d %d",&N,&H);
    vector<int> top(H+1,0);
    vector<int> btm(H+1,0);
    vector<int> ans(H+1,0);
    for(int i=0;i<N/2;i++){
        scanf("%d %d",&a,&b);
        btm[a]++;
        top[H+1-b]++;
    }
    for(int i=H-1;i>0;i--){
        btm[i]+=btm[i+1];
    }
    int m=999999999;
    int cnt=0;
    for(int i=1;i<=H;i++){
        top[i]+=top[i-1];
        ans[i]+=top[i]+btm[i];
        if(m>ans[i]){
            cnt=1;
            m=ans[i];
        }
        else if(ans[i]==m) cnt++;
    }
    printf("%d %d",m,cnt);
    return 0;
}

/*
짝수: 밑
홀수: 위
*/