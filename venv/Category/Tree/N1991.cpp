#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 26
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
vector<int> v[MAX];
void preorder(int node){
    cout<<(char)(node+'A');
    for(int next:v[node]){
        if(next=='.'-'A') continue;
        preorder(next);
    }
}
void inorder(int node){
    if(node!='.'-'A'){
        inorder(v[node][0]);
        cout<<(char)(node+'A');
        inorder(v[node][1]);
    }
}
void postorder(int node){
    for(int next:v[node]){
        if(next=='.'-'A') continue;
        postorder(next);
    }
    cout<<(char)(node+'A');
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    fse(0,N,1){
        char c,l,r;
        cin>>c>>l>>r;
        v[c-'A'].push_back(l-'A');
        v[c-'A'].push_back(r-'A');
    }
    preorder(0);
    cout<<endl;
    inorder(0);
    cout<<endl;
    postorder(0);
}