#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
vector<int> solution(int n, ll left, ll right) {
    vector<int> answer;
    ll cycle=left%n;
    ll cur=left/n;

    for(ll i=left;i<=right;i++){ //100,000 | int i 선언 시 오버플로우 발생!!!!!!! 바보!!!!!!!!
        if(cycle<cur){
            answer.push_back(cur+1);            
        }else{
            answer.push_back(cycle+1);
        }

        cycle++;
        if(cycle>=n){
            cycle=0;
            cur++;
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solution(3,2,5);
    cout<<endl;
    solution(4,7,14);
}