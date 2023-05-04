import java.util.*;
class Solution {
    public int[] solution(int[] prog, int[] speeds) {
        int N=speeds.length;
        Queue<Integer> q= new LinkedList();
        List<Integer> list=new ArrayList();
        
        for(int i=0;i<N;i++){
            int day= (100-prog[i])/speeds[i] + (((100-prog[i])%speeds[i]!=0)?1:0);
            q.offer(day);   
        }
        
        while(!q.isEmpty()){
            int top=q.poll();
            int cnt=1;
            while(!q.isEmpty()&& q.peek()<=top){
                cnt++;
                q.poll();
            }
            list.add(cnt);
        }
        return list.stream().mapToInt(i->i).toArray();
    }
}