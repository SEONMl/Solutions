#include <string>
#include <vector>
#include<set>
#include<iostream>
#define MAX 999'999'999'999'999
using namespace std;
typedef long long ll;
vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    set<pair<ll,ll>> cross;
    ll x1=MAX, y1=MAX, x2=-MAX, y2=-MAX;
    
    for(int i(0);i<line.size();i++){
        ll a=line[i][0],b=line[i][1],e=line[i][2];
        for(int j(i+1);j<line.size();j++){
            ll c=line[j][0], d=line[j][1], f=line[j][2];
            
            ll mo=a*d-b*c;
            if(mo==0) continue;
            
            ll x=b*f-e*d, y=e*c-a*f;
            if(x%mo==0 && y%mo==0) {
                cross.insert({x/mo,y/mo});
                x1=min(x1,x/mo);
                y1=min(y1,y/mo);
                x2=max(x2,x/mo);
                y2=max(y2,y/mo);
            }
        }
    }
    
    for(ll i(y2);i>=y1;i--){
        string tmp="";
        for(ll j(x1);j<=x2;j++){
            if(cross.find({j,i})!=cross.end()){
                tmp+="*";
            }else {
                tmp+=".";
            }
        }
        answer.push_back(tmp);
    }
    return answer;
}