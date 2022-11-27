#include<iostream>
#include<algorithm>
#define ALPHABET 26
using namespace std;
int N,K;
struct Trie{
    Trie *children[ALPHABET];
    bool terminal=false;
    int nodeCount=0;

    public:
    void insert(string str){
        Trie *root = this;
        Trie *head = this;

        for(auto c:str){
            int s=c-'A';
            if(head->children[s]!=NULL){
                head=head->children[s];
            }else{
                head->children[s]=new Trie();
                head=head->children[s];
                root->nodeCount++;
            }
        }
        head->terminal=true;
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>K;
    Trie *root=new Trie();
    Trie *reverseRoot=new Trie();

    for(int i=0;i<N;i++) {
        string input;
        cin>>input;
        root->insert(input.substr(0,K));

        reverse(input.begin(), input.end());
        reverseRoot->insert(input.substr(0,K));
    }

    int cnt=root->nodeCount+reverseRoot->nodeCount;

    cout<<cnt;
}

// 으음... 메모리 초과