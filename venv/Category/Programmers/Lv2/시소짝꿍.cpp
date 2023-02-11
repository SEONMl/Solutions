#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
int condi[][2]={{3,2},{2,1},{4,3}};
typedef long long ll;
ll solution(vector<int> weights) {
    set<int> original;
    map<int,int> cnt;

    for(int w:weights){
        original.insert(w);
        cnt[w]++;
    }
    ll  answer =0;

    for(int w:original){
        ll wCnt = cnt[w];
        answer+=(wCnt*(wCnt-1))/2;
        
        for(int j(0);j<3;j++){
            if(w%condi[j][1]) continue;
            int tmp = (w/condi[j][1])*condi[j][0];
            ll size = cnt[tmp];
            answer+= wCnt * size *1LL;
        }
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout<<solution({100,180,270,100,360});
}
