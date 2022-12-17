//package 메뉴리뉴얼;
//
//import java.util.*;
//
//public class Solution {
//    private static final int N = 21;
//    private Map<String, Integer> combination;
//
//    public void dfs(int start, int bit, int depth, String target) {
//        if(depth>1){
//            String tmp=bitToString(bit);
//            combination.put(tmp, combination.getOrDefault(tmp,0)+1);
//            return;
//        }
//        for(int i=start;i<N;i++){
//            dfs(start+1,bit|(1<<i),depth+1,target);
//        }
//    }
//
//    String bitToString(int bit){
//        StringBuilder sb = new StringBuilder();
//        for(int i=0;i<N;i++){
//            if((bit|(1<<i))==bit) {
//                sb.append((char) (i + 'A'));
//            }
//        }
//        return sb.toString();
//    }
//
//    public String[] solution(String[] orders, int[] course) {
//        combination=new HashMap<>();
//        for(String str: orders){
//            dfs(0,0,0,str);
//        }
//
//        for(Map.Entry<String, Integer> entry: combination.entrySet()){
//
//        }
//        return ;
//    }
//
//    public static void main(String[] args) {
//        String[] or = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
//        int[] co = {2, 3, 4};
//        new Solution().solution(or, co);
//    }
//}
