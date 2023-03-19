#include <string>
#include <vector>
#define MAX 100'100

using namespace std;

pair<int,int> dp[MAX];
pair<int,int> compare(pair<int,int> a, pair<int,int> b){
    if(a.first==0 && a.second==0) return b;
    
    if(a.first<b.first){
        return a;
    }else if(a.first==b.first){
        return (a.second>b.second)? a:b;
    }
    return b;
}
vector<int> solution(int target) {
    vector<int> answer(2);
    dp[0]={0,0};
    for(int i(0);i<=target;i++){
        for(int j(1);j<=20;j++){
            dp[i+j]=compare(dp[i+j],{dp[i].first+1, dp[i].second+1});
            dp[i+j*2]=compare(dp[i+j*2],{dp[i].first+1, dp[i].second});
            dp[i+j*3]=compare(dp[i+j*3],{dp[i].first+1, dp[i].second});
        }
        dp[i+50]=compare(dp[i+50], {dp[i].first+1, dp[i].second+1});
    }
    answer[0]=dp[target].first;
    answer[1]=dp[target].second;
    return answer;
}