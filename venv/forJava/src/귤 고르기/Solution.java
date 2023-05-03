import java.util.*;

class Solution {
    public int solution(int k, int[] tangerine) {
        Map<Integer,Integer> map =new HashMap<>();
        for(int t: tangerine){
            map.put(t,map.getOrDefault(t,0)+1);
        }

        List<Integer> keySetList = new ArrayList<>(map.keySet());
        Collections.sort(keySetList, (o1, o2) -> (map.get(o2).compareTo(map.get(o1))));

        int answer = 0;
        for(int key: keySetList){
            k-=map.get(key);
            answer++;
            if(k<=0) break;
        }
        return answer;
    }
}

