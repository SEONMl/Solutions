#include <string>
#include <vector>
using namespace std;

int score[8]={3,2,1,0,1,2,3};
int accum[26];
char c[]={'R','T','C','F','J','M','A','N'};
string solution(vector<string> survey, vector<int> choices) {
    for(int i(0);i<survey.size();i++){
        int s1=survey[i].at(0);
        int s2=survey[i].at(1);
        int choice=choices[i]-1;
        
        if(choice<4){
            accum[s1-'A']+=score[choice];
        }else{
            accum[s2-'A']+=score[choice];
        }
    }
    string answer = "";
    for(int i(0);i<8;i+=2){
        int s1=accum[c[i]-'A'];
        int s2=accum[c[i+1]-'A'];
        if(s2>s1){
            answer.push_back(c[i+1]);
        }else answer.push_back(c[i]);
    }
    return answer;
}