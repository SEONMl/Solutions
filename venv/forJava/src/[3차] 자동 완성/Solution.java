class Solution {
    class Trie{
        int count=0;
        Trie[] child=new Trie[26];
        
        void insert(String str){
            Trie head=this;
            count++;
            for(int i=0;i<str.length();i++){
                char c=str.charAt(i);
                int idx=c-'a';
                
                if(head.child[idx]==null) head.child[idx]=new Trie();
                head=head.child[idx];
                head.count++;
            }
        }
        int search(String str){
            Trie head=this;
            for(int i=0;i<str.length();i++){
                char c=str.charAt(i);
                int idx=c-'a';
                
                if(head.child[idx]==null) head.child[idx]=new Trie();
                head=head.child[idx];
                
                if(head.count==1) return i+1;
            }
            return str.length();
        }
    }
    public int solution(String[] words) {
        int answer = 0;
        Trie root=new Trie();
        for(String word:words){
            root.insert(word);
        }
        for(String word:words){
            answer += root.search(word);
        }
        return answer;
    }
}