#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<tuple>
#define MAX 100'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    map<char, queue<int>> frq; // 문자, 들어온 인덱스
    fse(0,N,1){
        string cmd;
        cin>>cmd;
        
        if(cmd=="enqueue"){
            char c;
            cin>>c;
            frq[c].push(i);
        }else{
            // 빈도 높고, 빨리 적재
            // 없으면 *
            tuple<int,int,char> candi={0,MAX,'*'}; // 참조횟수, 순서, 알파벳
            for(auto data: frq){
                auto q=data.second;
                if(get<0>(candi) < q.size()){
                    candi = {q.size(), q.front(), data.first};
                }else if(get<0>(candi) == q.size()){
                    if(get<1>(candi)>q.front()){
                        candi = {q.size(), q.front(), data.first};
                    }
                }
            }
            char tmp=get<2>(candi);
            if(tmp!='*'){
                frq[tmp].pop();
                if(frq[tmp].empty()) frq.erase(tmp);
            }
            cout<<tmp<<" ";
        }
        
    }
}