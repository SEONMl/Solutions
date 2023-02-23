#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int solution(vector<int> people, int limit) {
    sort(people.begin(),people.end());
    int N=people.size();
    deque<int> q;
    fse(0,N,1) q.push_back(people[i]);

    int answer = 0;
    while(!q.empty()){
        answer++;
        int heavy=q.back();
        q.pop_back();
        if(!q.empty() && q.front() + heavy<=limit){
            q.pop_front();
        }
    }

    return answer;
}

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout<<solution({50,50,70,80}, 100);
}