#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100000
using namespace std;
vector<int> v;
bool isBaesoo(string str){
    int tmp=0;
    bool zeroFlag=false;
    for(auto s:str){
        int num=s-'0';
        tmp+=num;
        if(num==0) zeroFlag=true;
        v.push_back(num);
    }
    if(tmp%3==0&&zeroFlag) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string N;
    cin>>N;
    if(!isBaesoo(N)) cout<<-1;
    else{
        sort(v.begin(),v.end());
        string answer="";
        for(int i=v.size()-1;i>=0;i--) answer.push_back(v[i]+'0');
        cout<<answer;
    }
}