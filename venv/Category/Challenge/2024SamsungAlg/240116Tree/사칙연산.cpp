#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define MAX 10'000
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
struct Node{
    string value;
    int left, right;
    public:
    Node() : value(), left(-1), right(-1) {}

    Node(string c,int left,int right){
        this->value=c;
        this->left=left;
        this->right=right;
    }
};
int calculate(string oper,double a,double b){
    if (oper== "+") return a+b;
    else if(oper=="*") return a*b;
    else if(oper=="/") return a/b;
    else return a-b;
}
bool isOper(string c){
    return c=="+"||c=="-"||c=="*"||c=="/";
}
double postorder(vector<Node> tree, int cur){
    auto curNode=tree[cur];
    if(!isOper(curNode.value)) return stoi(curNode.value);
    return calculate(curNode.value, postorder(tree, curNode.left), postorder(tree, curNode.right));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test_case, T=10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin>>N;
        vector<Node> tree(N+1);
        fse(0,N,1){
            int idx,left=-1,right=-1;
            string c;
            cin>>idx>>c;
            if(isOper(c)){
                cin>>left>>right;
            }
            tree[idx]=Node(c,left,right);
        }

        int answer=postorder(tree, 1);

        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}