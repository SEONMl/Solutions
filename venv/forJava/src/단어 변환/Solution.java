import java.util.*;
import java.lang.*;
class Solution {
    Map<String,List<String>> list;
    int N;
    final int INF =99999999;
    int answer=INF;
    String target;
    Set<String> visit= new HashSet();
    
    void dfs(int depth, String cur){
        if(cur.equals(target)){
            answer=Math.min(answer, depth);
            return;
        }
        if(depth>N+2) return;
        for(String s: list.get(cur)){
            if(visit.contains(s)) continue;
            visit.add(s);
            dfs(depth+1, s);
            visit.remove(s);
        }
    }
    
    boolean diffOne(String a, String b){
        if(a.equals(b)) return false;
        int cnt=0;
        for(int i=0;i<a.length();i++){
            if(a.charAt(i)!=b.charAt(i)) cnt++;
            if(cnt>=2) return false;
        }
        return true;
    }
    public int solution(String begin, String tar, String[] words) {
        N=words.length;
        list=new HashMap();
        target=begin;
        boolean check1=false;
        boolean check2=false;
        
        for(int i=0;i<N;i++){
            List<String> tmp=new ArrayList();
            check1 |= words[i].equals(tar);
            
            for(int j=0;j<N;j++){
                if(diffOne(words[i], begin)) {
                    tmp.add(begin);
                    check2=true;
                }
                if(diffOne(words[i], words[j])) tmp.add(words[j]);
            }
            list.put(words[i],tmp);
        }
        
        if(!check1 || !check2) return 0;
        dfs(0,tar);
        return (answer==INF)?0:answer;
    }
}