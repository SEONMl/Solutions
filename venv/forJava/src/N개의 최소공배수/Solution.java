class Solution {
    int GcdFunc(int a,int b){
        if(b==0) return a;
        else return GcdFunc(b, a%b);
    }
    public int solution(int[] arr) {
        int ans=arr[0];
        for(int k:arr){
            int gcd=GcdFunc(ans, k);
            ans=ans*k/gcd;
        }
        return ans;
    }
}