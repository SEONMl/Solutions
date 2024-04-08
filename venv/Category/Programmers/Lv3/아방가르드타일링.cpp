#include <string>
#include <vector>
#define MAX 100001
#define INF 1000000007
using namespace std;
long long  dp[MAX];

int solution(int N) {// 회전 가능!!
    dp[0]=0;
    dp[1]=1; dp[2]=3; dp[3]=10;
    int x[]={4,2,2};
    
    for(int i(4);i<=N;i++){
        dp[i] += (dp[i-2]*2 + dp[i-1] + dp[i-3]*5)% INF;
        dp[i] += x[i%3];
        for(int j=4;j<=i;j+=3){
            dp[i] += (dp[i-j] * x[1]) % INF;
            dp[i] += (dp[i-j-1] * x[2]) % INF;
            dp[i] += (dp[i-j-2] * x[0]) % INF;
            
        }
    }
    
    return dp[N]%INF;
}