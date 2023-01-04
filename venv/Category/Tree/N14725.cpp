#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#define MAX 1000
using namespace std;
int N,K;
vector<pair<int,string[]>> input;
struct Trie{
    set<Trie*> children;
    string value;
    bool terminal;

    Trie(string v=""){
        value=v;
        terminal=false;
    }

    public:
    void insert(string str){
        Trie *head=this;
        
        for(auto child:head->children){
            if(child->value==str){
                head=child;
            }
            else{
                head->children.insert(new Trie(str));
            }
        }
    }

};
bool comp(pair<int,string[]> s1, pair<int,string[]> s2){
    return s1.first < s2.first;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;

    Trie root;
    for(int i=0;i<N;i++){
        cin>>K;
        string tmp[K];
        for(int j=0;j<K;j++){
            cin>>tmp[j];
        }
        input.push_back(make_pair(K,tmp));
    }
    sort(input.begin(), input.end(), comp);
}