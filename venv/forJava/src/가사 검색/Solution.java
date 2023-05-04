import java.util.*;
class Solution {
    class Trie{
        int count=0;
        Trie[] child=new Trie[26];
        boolean terminal=false;
        
        void insert(String str){
            Trie head=this;
            for(int i=0;i<str.length();i++){
                char c=str.charAt(i);
                int idx= c-'a';
                head.count++;
                
                if(head.child[idx]==null) head.child[idx]=new Trie();
                head=head.child[idx];
            }
            head.terminal=true;
        }
        
        int search(String str){
            Trie head=this;
            int prev=head.count;
            for(int i=0;i<str.length();i++){
                char c=str.charAt(i);
                if(c=='?') break;
                
                int idx= c-'a';
                if(head.child[idx]==null) return 0;
                head=head.child[idx];
                prev=head.count;
            }
            return prev;
        }
    }
    
    public int[] solution(String[] words, String[] queries) {
        Trie[] root = new Trie[10001];
        Trie[] revRoot= new Trie[10001];
        List<Integer> list=new ArrayList();
        int N=words.length;
        // 저장
        for(String word:words){
            StringBuilder sb=new StringBuilder();

            int len=word.length();
            if(root[len]==null) {
                root[len]=new Trie();
                revRoot[len]=new Trie();
            }
            
            root[len].insert(word);
            sb.append(word);
            revRoot[len].insert(sb.reverse().toString());
        }
        
        // 조회
        for(String query: queries){
            int len=query.length(), tmp;
            StringBuilder sb=new StringBuilder();
            if(root[len]==null) {
                list.add(0);
                continue;
            }
            
            if(query.charAt(0)=='?'){
                sb.append(query);
                tmp= revRoot[len].search(sb.reverse().toString());
            }else{
                tmp= root[len].search(query);
            }
            list.add(tmp);
        }
        return list.stream().mapToInt(i->i).toArray();
    }
}