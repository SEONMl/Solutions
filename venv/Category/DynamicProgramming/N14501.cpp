#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 16
using namespace std;
int N;
vector<pair<int,int>> v;
int dp[MAX];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N;
    v.push_back(make_pair(0,0));
    for(int i=0;i<N;i++){
        int t,p;
        cin>>t>>p;
        v.push_back(make_pair(t,p));
    }
    
    dp[1]=0;
    for(int i=2;i<=N;i++){
        dp[i]=dp[i-1];
        for(int j=1;j<=N;j++){
            if(i==j+v[j].first){
                dp[i]=max(dp[i],dp[j]+v[j].second);
            }
        }
        cout<<dp[i]<<endl;
    }
    cout<<dp[N];
}