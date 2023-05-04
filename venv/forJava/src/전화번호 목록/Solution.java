import java.util.*;
class Solution {
    class Trie{
        boolean terminal=false;
        Trie[] child=new Trie[10];
                
        boolean checkAndInsert(String str){
            Trie head=this;
            
            for(int i=0;i<str.length();i++){
                char c=str.charAt(i);
                int k= c-'0';

                if(head.child[k]==null) head.child[k]=new Trie();
                head=head.child[k];
                
                if(head.terminal) return false;
            }
            head.terminal=true;
            return true;
        }
    }
    public boolean solution(String[] phone_book) {
        Trie root= new Trie();
        boolean result= true;
        Arrays.sort(phone_book);
        
        for(String phone:phone_book){
            result &= root.checkAndInsert(phone);
            if(!result) break;
        }
        
        return result;
    }
}