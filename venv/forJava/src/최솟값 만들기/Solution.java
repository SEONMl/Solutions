import java.util.*;
class Solution
{
    public int solution(int []A, int []B)
    {
        Arrays.sort(A);
        Arrays.sort(B);
        int N=A.length;
        int answer = 0;
        for(int i=0;i<N;i++){
            int a=A[i], b=B[N-1-i];
            answer+=a*b;
        }

        return answer;
    }
}