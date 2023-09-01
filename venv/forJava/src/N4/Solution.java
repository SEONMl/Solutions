package N4;

public class Solution {
    String printTag(String name){
        StringBuilder sb = new StringBuilder();
        sb.append("<");
        sb.append(name);
        sb.append("></");
        sb.append(">");
        return sb.toString();
    }
    public String solution(String input){
        String[] tmp =input.split(" ");
        if(tmp.length==1){
            return printTag(tmp[0]);
        }
        for(int i=1;i<tmp.length-1;i+=2){
            if(!tmp[i].equals("<") || !tmp[i].equals("+") || !tmp.equals("*")){
                return tmp[i] +"is invalid operator";
            }
        }

        return "";
    }
}
