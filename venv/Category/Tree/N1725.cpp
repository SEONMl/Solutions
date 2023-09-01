#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'001
#define INF 2'100'000'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
typedef long long ll;
int N,arr[MAX];
ll tree[MAX*3];
ll answer=0;
void init(int node, int start, int end){
    if(start==end){
        tree[node]=arr[start];
        return;
    }
    init(node*2, start, (start+end)/2);
    init(node*2+1, (start+end)/2+1, end);
    tree[node]=min(tree[node*2], tree[node*2+1]);
}
ll find(int node,int start, int end,int left, int right){
    if(end<left || right<start){
        return INF;
    }
    if(left<=start && end<=right){
        return tree[node];
    }
    ll lmin=find(node*2, start, (start+end)/2, left,right);
    ll rmin=find(node*2+1, (start+end)/2+1, end, left, right);
    return min(lmin, rmin);
}
void dfs(int left, int right){
    ll mid=find(1,0,N-1, left,right);
    answer=max(answer, mid*(right-left+1));

}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    fse(0,N,1){
        cin>>arr[i];
    }
    init(1,0,N-1);
    
    cout<<answer;
}