#include<iostream>
#include<vector>
#include<algorithm>
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
typedef long long ll;
int N;
vector<ll> positive;
vector<ll> negative;
int zeroCnt;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    fse(0,N,1) {
        int tmp;
        cin>>tmp;
        if(tmp==0) {
            zeroCnt++;
            continue;
        }
        if(tmp>0) positive.push_back(tmp);
        else negative.push_back(tmp);
    }

    sort(begin(positive),end(positive));
    sort(begin(negative),end(negative),greater<int>()); //내림차순
    ll answer=0;
    while(positive.size()>=2){
        ll fst=positive.back();
        positive.pop_back();
        ll snd=positive.back();
        positive.pop_back();

        if(snd!=1){
            answer+=fst*snd;
        }else{
            answer+=fst+snd;
        }
    }
    while(negative.size()>=2){
        ll fst=negative.back();
        negative.pop_back();
        ll snd=negative.back();
        negative.pop_back();
        
        answer+=fst*snd;
    }

    if(!positive.empty() && negative.empty()){
        answer+=positive.back();
    }
    else if(positive.empty() && !negative.empty()){
        if(zeroCnt>0) zeroCnt--;
        else answer+=negative.back();
    }
    else if(!positive.empty() && !negative.empty()){
        if(zeroCnt>0){
            zeroCnt--;
            answer+=positive.back();
        }else{
            answer+=positive.back()+negative.back();
        }
    }
    cout<<answer;
}