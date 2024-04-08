#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#define MAX 10'000
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
struct Node{
    char value;
    int left, right;
    public:
    Node() : value(), left(-1), right(-1) {}

    Node(char c,int left,int right){
        this->value=c;
        this->left=left;
        this->right=right;
    }
};
bool find(vector<Node>& nodes,int cur){
    if(cur==-1) return true;
    auto n=nodes[cur];
    if(n.left==-1 && n.right==-1){
        if(n.value>='0' && n.value<='9') return true;
        return false;
    }
    return find(nodes, n.left)&find(nodes,n.right);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test_case, T=10;

    freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer=0, N;
        cin>>N;
        vector<Node> nodes(N+1);
        cin.ignore();
        fse(0,N,1){
            string str;
            getline(cin,str);
            
            istringstream iss(str);
            char c; int id, left=-1, right=-1;
            int cnt=count(str.begin(),str.end(),' ');
            iss>>id>>c;
            if(cnt==2){
                iss>>left;
            }else if(cnt==3){
                iss>>left>>right;
            }
            nodes[id]=Node(c,left,right);
        }

        if(find(nodes, 1)){
            answer = 1;
        }
        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}