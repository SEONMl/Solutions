#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 51
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    int g[MAX][MAX], dp[MAX][MAX];
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            cin>>g[i][j];
            dp[i+1][j+1]=g[i][j];
        }
    }
    for(int i(2);i<=N;i++){
        for(int j(1);j<=N;j++){
            dp[i][j]+=dp[i-1][j];
        }
    }
    for(int i(2);i<=N;i++){
        for(int j(1);j<=N;j++){
            dp[j][i]+=dp[j][i-1];
        }
    }
    // cout<<endl;
    // for(int i(1);i<=N;i++){
    //     for(int j(1);j<=N;j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }
    int answer=0;
    for(int i(1);i<=N;i++){
        for(int j(1);j<=N;j++){

            for(int p(1);p<=i;p++){
                for(int q(1);q<=j;q++){
                    int a=dp[i][j] - (dp[p-1][j]+dp[i][q-1])+dp[p-1][q-1];
                    
                    // 왼 하단, 오 상단
                    for(int x(i+1);x<=N;x++){
                        for(int y(j+1);y<=N;y++){
                            int b= dp[x][y] - (dp[i][y]+dp[x][j]) +dp[i][j];
                            if(a==b) answer++;
                        }
                    }
                    // 왼 상단, 오 하단
                    for(int x(i+1);x<=N;x++){
                        for(int y(q-1);y>0;y--){
                            int b= dp[x][q-1]-(dp[i][q-1]+dp[x][y-1])+dp[i][y-1];
                            if(a==b) answer++;
                        }
                    }
                }
            }
        }
    }
    cout<<answer;
}