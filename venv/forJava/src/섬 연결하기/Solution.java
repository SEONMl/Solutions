import java.util.*;

class Solution {
    int[] parent;
    int find(int x){
        if(parent[x]!=x) return find(parent[x]);
        return parent[x];
    }
    public int solution(int N, int[][] costs) {
        parent=new int[N];
        for(int i=0;i<N;i++){
            parent[i]=i;
        }

        Arrays.sort(costs, (a,b)-> a[2]-b[2]);
        int total=0;
        for(int[] cost:costs){
            int a=cost[0], b=cost[1], c=cost[2];
            int x=find(a);
            int y=find(b);
            if(x==y) continue;
            else{
                if(x<y) parent[y]=x;
                else parent[x]=y;
                total+=c;
            }
        }
        return total;
    }
}