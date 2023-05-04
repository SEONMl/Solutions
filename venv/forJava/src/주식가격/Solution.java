import java.util.*;

class Solution {
    class Pair{
        int value;
        int enterTime;
        Pair(int v,int e){
            this.value=v; this.enterTime=e;
        }
        boolean isBigger(int p){
            return value>p;
        }
    }
    public int[] solution(int[] prices) {
        Stack<Pair> stk = new Stack<Pair>();
        int N=prices.length;
        int[] answer = new int[N];
        
        for(int i=0;i<N;i++){
            int cur=prices[i];
            while(!stk.empty() && stk.peek().isBigger(cur)){
                Pair tmp =stk.pop();
                answer[tmp.enterTime] = i-tmp.enterTime;
            }
            stk.push(new Pair(cur, i));
        }
        while(!stk.empty()){
            Pair tmp = stk.pop();
            answer[tmp.enterTime] = N-1-tmp.enterTime;
        }
        return answer;
    }
}