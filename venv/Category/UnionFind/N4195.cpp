#include<iostream>
#include<algorithm>
#include<map>
#define MAX 200'004
using namespace std;
int parent[MAX];
int friends[MAX];
map<string, int> id;
int find(int x){
    if(x!=parent[x]) return find(parent[x]);
    return parent[x];
}
int _union(int a,int b){
    int x=find(a);
    int y=find(b);

    if(x!=y) {
        parent[y]=x;
        friends[x]+=friends[y];
        return friends[x];
    }
    return friends[x];
}
void saveName(string name){
    if(id.find(name)!=id.end()) return;
    id[name]=id.size();
}
void init(){
    for(int i(0);i<MAX;i++){
        parent[i]=i;
        friends[i]=1;
    }
    id.clear();
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        init();
        for(int i(0);i<N;i++){
            string name[2];
            cin>>name[0]>>name[1];
            
            saveName(name[0]);
            saveName(name[1]);
            int ans=_union(id[name[0]], id[name[1]]);
           
            cout<<ans<<'\n';
        }
    }
}