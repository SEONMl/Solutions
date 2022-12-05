#include<iostream>
#include<vector>
#include<algorithm>
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
int N;
vector<int> positive;
vector<int> negative;
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
    int answer=0;
    while(positive.size()>=2){
        int fst=positive.back();
        positive.pop_back();
        int snd=positive.back();
        positive.pop_back();

        if(snd!=1){
            answer+=fst*snd;
        }else{
            answer+=fst+snd;
        }
    }
    while(negative.size()>=2){
        int fst=negative.back();
        negative.pop_back();
        int snd=negative.back();
        negative.pop_back();
        
        answer+=fst*snd;
    }

    cout<<positive.size() <<" "<<negative.size()<<endl;
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