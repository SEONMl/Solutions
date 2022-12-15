package 양궁대회;

public class Solution {
    int ans=0;
    int[] ansArr={-1};
    void dfs(int k,int[] ryan,int[] apeach){
        if (k == 0) {
            int score=getDiff(ryan, apeach);
            if(ans<=score && score!=0) {
                ans=score;
                ansArr=ryan.clone();
            }
            return;
        }
        for(int i=0;i<11 && ryan[i]<=apeach[i];i++){
            ryan[i]++;
            dfs(k-1,ryan,apeach);
            ryan[i]--;
        }
    }

    public int getDiff(int[] ryan, int[] apeach) {
        int ryScore=0;
        int apSocre=0;
        for(int i=0;i<11;i++){
            if(ryan[i]>apeach[i]) ryScore+=10-i;
            else if(apeach[i]>0) apSocre+=10-i;
        }
        return ryScore - apSocre;
    }

    public int[] solution(int n, int[] info) {
        int[] ryan = new int[11];
        dfs(n, ryan, info);
        return ansArr;
    }

    public static void main(String[] args){
        Solution solution = new Solution();
        int[] info={2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
        int[] sdf = solution.solution(5, info);
        for(int k:sdf){
            System.out.print(k+" ");
        }
    }
}
