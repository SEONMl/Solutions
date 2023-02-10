#include<iostream>
#include<queue>
#define MAX 1'000'001
using namespace std;
int visit[MAX];
int solution(int x, int y, int n) {
    for(int i=0;i<=MAX;i++){
        visit[i]=9e8;
    }
    queue<int> q;
    q.push(x);
    visit[x]=0;
    while(!q.empty()){
        int cur=q.front();
        int cur_cnt=visit[cur];
        if(cur==y) return cur_cnt;
        q.pop();

        for(int tmp:{cur*3, cur*2, cur+n}) {
            if(visit[tmp]!=9e8) continue;
            if(tmp<=y) {
                q.push(tmp);
                visit[tmp]=cur_cnt+1;
            }
        }
    }
    return -1;
}
int main(){
    cout<<solution(10,40,5); //2
    cout<<solution(10,40,30); //1
    cout<<solution(2,5,4); // -1
}