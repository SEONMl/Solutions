#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define MAX 1000
using namespace std;
int N,K;
struct Trie{
    map<string, Trie*> children;

    public:
    void insert(vector<string> str){
        Trie* head = this;
        for(string cur: str){
            if(head->children.find(cur) == head->children.end()){// 존재하지 않음
                head->children.insert({cur, new Trie()});
            }
            head=head->children[cur];
        }
    }

    void print(int depth){
        Trie* head =this;
        for(auto child:children){
            for(int i(0);i<depth ;i++){
                cout<<"--";
            }
            cout<<child.first<<'\n';
            child.second->print(depth+1);
        }
    }

};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;

    Trie* root =new Trie();
    for(int i=0;i<N;i++){
        cin>>K;
        vector<string> tmp;
        for(int j=0;j<K;j++){
            string t;
            cin>>t;
            tmp.push_back(t);
        }
        root->insert(tmp);
    }

    root->print(0);
}