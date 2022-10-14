#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int N,M,L,K,cnt,ans;
vector<pair<int,int>> v;
int main(){
    scanf("%d%d%d%d",&N,&M,&L,&K);
    for(int i=0;i<K;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        v.push_back(make_pair(a,b));
    }
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            cnt=0;
            int x=v[i].first;
            int y=v[j].second;
            for(int k=0;k<K;k++){
                if(x<=v[k].first&&v[k].first<=x+L&&y<=v[k].second&&v[k].second<=y+L)cnt++;
            }
            ans=max(ans,cnt);
        }
    }
    printf("%d",K-ans);
    return 0;
}