#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int N,M,H;
int dp[51][1001];
vector<int> v[51];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin>>N>>M>>H;
    cin.ignore(1);
    for(int i=1;i<=N;i++){
        string tmp;
        getline(cin,tmp,'\n');
        for(int j=0;j<tmp.size();j++){
            if(tmp[j]==' '||j==0){
                v[i].push_back(stoi(&tmp[j]));
            }
        }
    }
    for(int i=0;i<=N;i++) dp[i][0]=1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=H;j++){
            for(int k=0;k<v[i].size();k++){
                if(j>=v[i][k]){
                    dp[i][j]+=dp[i-1][j-v[i][k]];
                    dp[i][j]%=10007;
                }
            }
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=10007;
        }
    }
    cout<<dp[N][H]<<'\n';
    return 0;
}