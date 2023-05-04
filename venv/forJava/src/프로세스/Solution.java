import java.util.*;

class Solution {
    class Pair{
        int p; int idx;
        Pair(int p, int idx){
            this.p=p; this.idx=idx;
        }
    }
    public int solution(int[] priorities, int location) {
        PriorityQueue<Integer> pq = new PriorityQueue(Collections.reverseOrder());
        Queue<Pair> q=new LinkedList();
        int idx=0;
        for(int i: priorities){
            pq.offer(i);
            q.offer(new Pair(i, idx));
            idx++;
        }
        
        int cnt=0;
        while(true){
            if(pq.peek() == q.peek().p){
                cnt++;
                if(q.peek().idx == location) break;
                pq.poll();
                q.poll();
            }else{
                Pair tmp=q.poll();
                q.offer(tmp);
            }
        }
        return cnt;
    }
}