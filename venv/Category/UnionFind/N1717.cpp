#include<iostream>
#define MAX 1'000'001
using namespace std;
int parent[MAX];
int N,M;
int find(int x){
    if(parent[x]!=x) parent[x]=find(parent[x]);
    return parent[x];
}
void unionNode(int a,int b){
    a=find(a);
    b=find(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M;
    for(int i(1);i<=N;i++){
        parent[i]=i;
    }
    int cmd,a,b;
    for(int i(0);i<M;i++){
        cin>>cmd>>a>>b;
        if(cmd==0){
            unionNode(a,b);
        }
        else{
            a=find(a);
            b=find(b);
            if(a==b) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}