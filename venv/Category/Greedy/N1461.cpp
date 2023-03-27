#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,M;
    cin>>N>>M;
    vector<int> pos;
    vector<int> neg;
    fse(0,N,1){
        int tmp;
        cin>>tmp;
        (tmp>0)? pos.push_back(tmp) : neg.push_back(tmp);
    }
    sort(pos.begin(), pos.end(), greater<>());
    sort(neg.begin(), neg.end());
    int answer=0;
    int i=0;
    while(i<pos.size()){
        answer+=pos[i]*2;
        i+=M;
    }
    i=0;
    while(i<neg.size()){
        answer+=abs(neg[i])*2;
        i+=M;
    }

    if(neg.empty() || (!pos.empty()&& abs(neg[0])<=pos[0])){
        answer-=pos[0];
    }else if(pos.empty() || (!neg.empty() && abs(neg[0])>pos[0])){
        answer-=abs(neg[0]);
    }
    cout<<answer;
}