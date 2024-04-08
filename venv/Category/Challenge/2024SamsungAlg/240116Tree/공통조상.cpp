#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define MAX 10'000
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
struct Node{
    int parent, left, right;
    public:
    Node():parent(0), left(0), right(0) {}
    Node(int p,int l,int r):parent(p), left(l), right(r) {}
};
int getTreeSize(int cur, vector<Node> tree){
    int res=1;
    if(tree[cur].left!=0) res += getTreeSize(tree[cur].left, tree);
    if(tree[cur].right!=0) res += getTreeSize(tree[cur].right, tree);
    return res;
}
int findLCA(vector<Node> tree, int a,int b){
    bool visit[MAX+1];
    fill_n(visit, MAX+1, false);
    int cur=tree[a].parent;
    while(cur!=0){
        visit[cur]=true;
        cur=tree[cur].parent;
    }
    cur=tree[b].parent;
    while(!visit[cur]){
        cur=tree[cur].parent;
    }
    return cur;
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
        vector<Node> tree(V+1);

        fse(0,E,1){
            int a,b;
            cin>>a>>b;
            if(tree[a].left == 0){
                tree[a].left=b;
            }else tree[a].right=b;
            tree[b].parent = a;
        }

        int lca, size;
        lca=findLCA(tree, child1, child2);
        size=getTreeSize(lca, tree);
        cout<<"#"<<test_case<<" "<<lca<<" "<<size<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
