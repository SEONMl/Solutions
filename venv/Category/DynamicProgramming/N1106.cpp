#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100001
using namespace std;
int C,N;
vector<pair<int,int>> v;
int dp[MAX];
int main(){
    scanf("%d %d",&C,&N);
    int a,b;
    for(int i=0;i<N;i++){
        scanf("%d %d",&a,&b);
        v.push_back(make_pair(a,b));
    }
    for(int i=0;i<N;i++){
        int cost=v[i].first;
        int per=v[i].second;
        for(int j=1;j<=MAX;j++){
            if(j-cost>=0) dp[j]=max(dp[j],dp[j-cost]+per);
        }
    }
    for(int i=1;i<=MAX;i++){
        if(dp[i]>=C) {
            printf("%d",i);
            break;
        }
    }
    return 0;
}