#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define MAX 51
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,M;
int parent[MAX];
vector<int> party[MAX];
int find(int a){
    if(parent[a]!=a) return find(parent[a]);
    return parent[a];
}
void makeunion(int a,int b){
    int x=find(a);
    int y=find(b);
    if(x<y) parent[y]=x;
    else parent[x]=y;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M; // 사람, 파티수
    int tmp,p;
    cin>>tmp;
    set<int> knowTruth;
    fse(0,tmp,1){
        cin>>p;
        knowTruth.insert(p);
    }
    fse(1,N+1,1){
        parent[i]=i;
    }

    set<int> party[M];
    fse(0,M,1){
        cin>>tmp>>p;
        party[i].insert(p);
        for(int j(1);j<tmp;j++){
            int q;
            cin>>q;
            party[i].insert(q);
            makeunion(p,q);
        }
    }

    int answer=0;
    bool unavailable[M]={0};
    
    for(auto each:knowTruth){
        for(int i(0);i<M;i++){
            if(unavailable[i]) continue;

            for(int person:party[i]){
                if(find(person)==find(each)){
                    unavailable[i]=true;
                    break;
                }
            }
        }
    }
    fse(0,M,1){
        if(unavailable[i]) continue;
        answer++;
    }
    cout<<answer;
}
