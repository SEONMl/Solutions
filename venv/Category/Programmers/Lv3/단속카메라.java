import java.util.*;
import java.lang.*;
class Solution {
    public int solution(int[][] routes) {
        Arrays.sort(routes, (a,b)-> a[0]-b[0]);
        int limit= -99_999_999;
        int cnt=0;
        for(int[] route:routes){
            int s=route[0], e=route[1];
            if(s<=limit) {
                limit=Math.min(limit, e);
            }else{
                limit=e;
                cnt++;
            }
        }
        return cnt;
    }
}