package 롤케이크자르기;

import java.util.*;
import java.util.stream.Collectors;

public class Solution {
    public int solution(int[] topping) {
        int n=topping.length;

        Set<Integer> left = new HashSet<>();
        Map<Integer, Integer> right = new HashMap<>();
        left.add(topping[0]);

        for(int top:topping){
            right.put(top, right.getOrDefault(top,0)+1);
        }
        int answer=0;
        for(int top:topping) {
            left.add(top);
            right.put(top, right.getOrDefault(top,0)-1);
            if(right.get(top)==0){
                right.remove(top);
            }

            if(left.size()==right.size()) answer++;
        }
        System.out.println(answer);
        return answer;
    }

    public static void main(String[] args) {
        int[] t={1,2,1,3,1,4,1,2};
        int[] t2={1,2,3,1,4};
        new Solution().solution(t);
    }
}
