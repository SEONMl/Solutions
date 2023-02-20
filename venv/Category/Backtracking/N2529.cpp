#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define MAX 10
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N;
int giho[MAX];
bool visit[MAX];
vector<int> max_vec={0,0,0,0,0,0,0,0,0,0};
vector<int> min_vec={9,9,9,9,9,9,9,9,9,9};
void bt(vector<int> v){
    if(v.size()==N+1) {
        int prev=v[0];
        bool isCorrect=true;
        fse(0,N,1){
            if(!((giho[i]==1 && prev<v[i+1])||(giho[i]==0&&prev>v[i+1]))){
                isCorrect=false;
            }
            prev=v[i+1];
        }
        if (!isCorrect) return;

        string s="";
        for(int num:v){
            s+=to_string(num);
        }
        answer.push_back(s);
        return;
    }
    for(int i=0;i<10;i++){
        if(visit[i]) continue;
        v.push_back(i);
        visit[i]=1;
        bt(v);
        visit[i]=0;
        v.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    fse(0,N,1) {
        char tmp;
        cin>>tmp;
        if(tmp=='>') giho[i]=0;
        else giho[i]=1;
    }
    vector<int> v;
    bt(v);
    sort(answer.begin(),answer.end());
    cout<<answer[answer.size()-1]<<'\n';
    cout<<answer[0];
}