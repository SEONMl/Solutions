import java.util.*;
import java.util.stream.Collectors;

public int solution(int[] queue1, int[] queue2) {
    int N=queue1.length;
    Queue<Integer> q1 = new LinkedList<>();
    Queue<Integer> q2 = new LinkedList<>();
    long sum1 = Arrays.stream(queue1).sum();
    long sum2 = Arrays.stream(queue2).sum();

    for(int i=0;i<N;i++){
        q1.offer(queue1[i]);
        q2.offer(queue2[i]);
    }

    int maxLoop=4*N;
    int count=0;
    while(sum1!=sum2){
        if(count>maxLoop) return -1;
        if(sum1<sum2) {
            int tmp=q2.poll();
            sum2-=tmp;
            sum1+=tmp;
            q1.offer(tmp);
        }else{
            int tmp=q1.poll();
            sum1-=tmp;
            sum2+=tmp;
            q2.offer(tmp);
        }
        count++;
    }

    return count;
}