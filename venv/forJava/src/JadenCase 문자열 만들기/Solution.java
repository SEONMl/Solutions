class Solution {
    public String solution(String s) {
        StringBuilder sb= new StringBuilder();
        
        char prev=' ';
        for(int i=0;i<s.length();i++){
            char c=s.charAt(i);
            if(prev==' ') {
                sb.append(Character.toUpperCase(c));
            }else{
                sb.append(Character.toLowerCase(c));
            }
            prev=c;
        }
        
        return sb.toString();
    }
}