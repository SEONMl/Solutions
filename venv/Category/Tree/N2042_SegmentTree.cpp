#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define MAX 1'000'003
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
typedef long long ll;
int N,M,K;
ll arr[MAX], tree[(1 << 22 )];
void init(int node,int start,int end){
    if(start==end){
        tree[node]=arr[start];
        return;
    }
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
    tree[node]=tree[node*2]+tree[node*2+1];
}
void update(int node, int start, int end,int target,ll val){
    if(target<start || end<target){
        return;
    }
    if(start==end){ // start==end <=> start==end==target
        tree[node]=val;
        return;
    }
    update(node*2, start, (start+end)/2, target,val);
    update(node*2+1, (start+end)/2+1, end, target,val);
    tree[node]=tree[node*2]+tree[node*2+1];
}
ll print(int node, int start,int end,int left,int right){
    if(end<left || start>right){
        return 0;
    }
    if(left<=start&&end<=right){
        return tree[node];
    }
    ll lv=print(node*2, start, (start+end)/2, left,right);
    ll rv=print(node*2+1, (start+end)/2+1, end, left, right);
    return lv+rv;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>M>>K;
    int h= (int)ceil(log2(N));
    int tree_size=(1<< (h+1));
    
    fse(1,1+N,1){
        cin>>arr[i];
    }
    init(1,1,N);

    fse(0,M+K,1){
        int a;
        cin>>a;

        if(a==1){// b를 c로 변경
            int b; ll c;
            cin>>b>>c;
            arr[b]=c;
            update(1,1,N, b, c);
        }else{ // b ~ c 구간합
            int b,c;
            cin>>b>>c;
            cout<<print(1,1,N, b, c)<<'\n';
        }
    }
}
