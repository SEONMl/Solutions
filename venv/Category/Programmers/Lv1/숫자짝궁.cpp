#include <string>
#include <vector>
#include<algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int number[10]={0};
    for(char i('0');i<='9';i++){
        int x=count(X.begin(),X.end(),i);
        int y=count(Y.begin(),Y.end(),i);
        number[i-'0']=min(x,y);
    }
    for(char i('9');i>='0';i--){
        for(int j(0);j<number[i-'0'];j++){
            if(i=='0' && answer.length()==0){
                answer="0";
                break;
            }
            answer.push_back(i);
        }
    }
    if(answer.length()==0) return "-1";
    return answer;
}