#include<iostream>
#include<algorithm>
#define MAX 100000
using namespace std;
int T;
struct Trie{
    Trie *children[10];
    bool terminal;


    Trie(){
        terminal = false;
        for(int i=0;i<10;i++){
            children[i]=NULL;
        }
    }

    void insert(string str){
        Trie *head = this;
        for(auto c:str){
            int s = c-'0';
            
            if(head->children[s]!=NULL){
                head=head->children[s];
            }
            else{
                head->children[s]=new Trie();
                head=head->children[s];
            }
        }
        head->terminal=true;
    }

    bool search(string str){
        Trie *head =this;

        for(auto c:str){
            int s=c-'0';
            if(head->terminal==true){
                return false;
            }
            head=head->children[s];
        }
        return true;
    }

};
void sol(){
    int N;
    cin>>N;
    Trie *root = new Trie();
    string input[N];
    bool flag=true;

    for(int i=0;i<N;i++){
        cin>>input[i];
        root->insert(input[i]);
    }
    for(int i=0;i<N;i++){
        flag&=root->search(input[i]);
    }
    
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>T;
    for(int i=0;i<T;i++) sol();
}