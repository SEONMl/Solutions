#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define MAX 1'000'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;

string solution(string number, int k) {
    N=number.length(); 
    vector<char> stack;
    stack.push_back(number.at(0));
    fse(1,N,1){
        char cur=number.at(i);
        
        while(!stack.empty() && stack.back()<cur && k>0){
            stack.pop_back();
            k--;
        }
        stack.push_back(cur);
    }
    while(k>0){
        stack.pop_back();
        k--;
    }
    string answer="";
    fse(0,stack.size(),1){
        answer+=stack[i];
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout<<solution("1231234",3);
    cout<<endl<<solution("4177252841",4);
    cout<<endl<<solution("1924",2);
}