package 삼각달팽이;

import java.util.ArrayList;
import java.util.List;

class Solution {
    int dx[]={1,0,-1};
    int dy[]={0,1,-1};

    public int[] solution(int n) {
        int[][] g=new int[n][n];
        int x=-1;
        int y=0;
        int dir=2;
        int value=0;
        int cnt=n;
        while(cnt>0) {
            dir=(dir+1)%3;
            for(int i=0;i<cnt;i++){
                x+=dx[dir];
                y+=dy[dir];
                value++;
                g[x][y]=value;
            }
            cnt--;
        }

        int[] answer=new int[(n+1)*n/2];
        int idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]!=0){
                    answer[idx++]=g[i][j];
                }
            }
        }
        return answer;
    }

    public static void main(String[] args) {
        new Solution().solution(4);
    }
}
