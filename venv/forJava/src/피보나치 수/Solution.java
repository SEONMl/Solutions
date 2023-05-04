class Solution {
    public int solution(int N) {
        int[] dp=new int[N+1];   
        dp[1]=1;
        for(int i=2;i<=N;i++){
            dp[i]=(dp[i-1]+dp[i-2]) % 1234567;
        }
        return dp[N];
    }
}