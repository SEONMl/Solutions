import java.util.*;
class Solution {
    boolean solution(String s) {
        Stack<Character> stk=new Stack();

        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            if(c=='(') stk.push(c);
            else{
                if(stk.isEmpty()) return false;
                else if(stk.peek()=='(') stk.pop();
                else return false;
            }
        }

        return (stk.isEmpty())? true:false;
    }
}