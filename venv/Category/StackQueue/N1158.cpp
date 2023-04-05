#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 5000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,K;
    cin>>N>>K;
    queue<int> q;
    fse(0,N,1){
        q.push(i+1);
    }
    vector<int> answer;
    while(!q.empty()){
        fse(0,K-1,1){
            int a=q.front();
            q.pop();
            q.push(a);
        }
        answer.push_back(q.front());
        q.pop();
    }
    cout<<"<";
    for(int i(0);i<answer.size();i++){
        cout<<answer[i];
        if(i<answer.size()-1) cout<<", ";
    }
    cout<<">";
}