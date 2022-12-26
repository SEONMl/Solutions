package 가장가까운같은글자;

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] solution(String s) {
        Map<Character,Integer> words=new HashMap();
        int[] answer = new int[s.length()];

        int idx=0;
        for(char alpha: s.toCharArray()){
            if(words.containsKey(alpha)){
                answer[idx]=idx-words.get(alpha);
                words.put(alpha,idx);
                idx++;
            }else{
                words.put(alpha,idx);
                answer[idx]=-1;
                idx++;
            }
        }
        return answer;
    }
}