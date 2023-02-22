#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int solution(int n, vector<int> lost, vector<int> reserve) {
    set<int> losted;
    bool canReserve[31]={0};
    int N=reserve.size();
    sort(reserve.begin(), reserve.end());
    
    for(int i:lost) losted.insert(i);
    for(int i:reserve){
        canReserve[i]=true;
        // 여분 있고 자기 거 안 가져온 상황
        if(losted.find(i)!=losted.end()){
            losted.erase(i);
            canReserve[i]=false;
        }
    }
    
    for(int i=0;i<N;i++){
        int person=reserve[i];
        if(canReserve[person] && losted.find(person-1)!=losted.end()){
            losted.erase(person-1);    
            canReserve[person]=false;
            continue;
        }
        if(canReserve[person] && losted.find(person+1)!=losted.end()){
            losted.erase(person+1);
            canReserve[person]=false;
            continue;
        }
    }
    return n-losted.size();
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout<<solution(5,{5},{4})<<endl;
    cout<<solution(5,{2,4},{3})<<endl;
    cout<<solution(3,{3},{1});
}