#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define MAX 10'001
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
int maxHeight;
void getMaxHeight(int depth, vector<int> tree[], int cur){
    maxHeight=max(maxHeight, depth);
    for(auto next: tree[cur]){
        getMaxHeight(depth+1, tree, next);
    }
}
int parent[MAX][MAX];
int depth[MAX]; // 해당 노드의 높이
void init(int cur, int h, int pa, vector<int> tree[]){
    depth[cur]=h;
    for(auto next: tree[cur]){
        init(next, h+1, cur, tree);
        parent[next][0]=cur;
    }
}
void dp(int V){
    for(int i=1;i<maxHeight;i++){
        for(int j=1;j<V+1;j++){
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
}
int getLCA(int a,int b){
    int ah = depth[a];
    int bh = depth[b];
    if(ah < bh) { // a가 더 깊은 노드
		int tmp = a;
		a = b;
		b = tmp;
	}
    // 높이 맞추기
    for(int i=maxHeight-1;i>=0;i--){
        if(((int) pow(2,i)) <= depth[a] - depth[b]){
            a=parent[a][i];
        }
    }
    if(a==b) return a;

    for(int i=maxHeight-1; i>=0; i--){
        if(parent[a][i] != parent[b][i]){
            a=parent[a][i];
            b=parent[b][i];
        }
    }
    return parent[a][0];
}
int getTreeSize(int cur, int &size, vector<int> tree[]){
    size++;
    for(auto next: tree[cur]){
        getTreeSize(cur, size, tree);
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test_case, T;

	cin>>T;
    // freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int V,E, child1,child2;
        cin>>V>>E>>child1>>child2;
        vector<int> tree[MAX];

        fse(0,E,1){
            int a,b;
            cin>>a>>b;
            tree[a].push_back(b);
        }
        getMaxHeight(1, tree, 1);
        init(1,1,0,tree);
        dp(V);

        int lca,size=0;
        lca=getLCA(child1, child2);
        getTreeSize(lca,size,tree);

        cout<<"#"<<test_case<<" "<<lca<<" "<<size<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
