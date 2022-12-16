package 아이템줍기;

import java.util.*;

class Solution {
    int N=102;
    int[] dx={0,1,0,-1};
    int[] dy={1,0,-1,0};
    class Position {
        int x;
        int y;
        int dis;

        public Position(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public Position(int x, int y, int dis) {
            this.x = x;
            this.y = y;
            this.dis=dis;
        }
        public boolean isSame(int x,int y){
            if(this.x==x && this.y==y) return true;
            return false;
        }
    }
    int bfs(int[][] g,int a,int b,int t_a,int t_b){
        Queue<Position> q = new LinkedList<>();
        q.add(new Position(a*2,b*2,0));
        boolean[][] visit = new boolean[N][N];
        visit[a*2][b*2]=true;

        int ans=987654321;
        while(!q.isEmpty()){
            Position cur = q.poll();
            if(cur.isSame(t_a*2,t_b*2)){
                ans= Math.min(ans,cur.dis);
            }

            for(int i=0;i<4;i++){
                int nx= cur.x+dx[i];
                int ny= cur.y+dy[i];

                if(0<=nx&&nx<N&&0<=ny&&ny<N &&!visit[nx][ny] && g[nx][ny]==1){
                    visit[nx][ny]=true;
                    q.add(new Position(nx,ny,cur.dis+1));
                }
            }
        }
        return ans/2;
    }

    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        int[][] g=new int[N][N];
        for(int i=0;i<rectangle.length;i++){
            int sx=rectangle[i][0]*2;
            int sy=rectangle[i][1]*2;
            int ex=rectangle[i][2]*2;
            int ey=rectangle[i][3]*2;
            // 테두리는 두 배를 하자

            for(int j=sx;j<=ex;j++){
                for(int k=sy;k<=ey;k++){
                    if(sx<j&&j<ex && sy<k&&k<ey) {
                        g[j][k]=-1;
                    }else if(g[j][k]!=-1){
                        g[j][k]=1;
                    }
                }
            }
        }
        return bfs(g,characterX,characterY,itemX,itemY);
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] a={{1,1,5,7}};
        int k=s.solution(a,1,1,4,7);
        System.out.println(k);
    }
}