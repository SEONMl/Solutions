#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int dp[1<<20],dp2[1<<20];
int solution(vector<int> money) {
    dp[0]=money[0];
    dp2[1]=money[1];
    int N=money.size();
    
    for(int i=1;i<N-1;i++){
        dp[i] = max(dp[i-1], dp[i-2]+money[i]);
        dp2[i+1] = max(dp2[i], dp2[i-1]+money[i+1]);
    }
    return max(dp[N-2],dp2[N-1]);
}