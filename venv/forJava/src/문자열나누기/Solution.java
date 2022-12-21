package 문자열나누기;

class Solution {
    public int solution(String s) {
        int answer = 0;

        char X=s.charAt(0);
        int XCnt=1;
        int notXCnt=0;
        for(int i=1;i<s.length();i++){
            if(s.charAt(i)==X){
                XCnt++;
            }
            else{
                notXCnt++;
                if(XCnt==notXCnt && i<s.length()-1){
                    answer++;
                    X=s.charAt(i+1);
                    XCnt=0;
                    notXCnt=0;
                }
            }
        }
        if(XCnt>0 || notXCnt>0) answer++;
        return answer;
    }
}