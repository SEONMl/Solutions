#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string S;
    int N;
    cin>>S>>N;
    vector<int> eng_index[26];
    for(int i=0;i<S.length();i++){
        eng_index[S[i]-'a'].push_back(i);
    }

    for(int i=0;i<N;i++){
        char tmp;
        int l,r;
        cin>>tmp>>l>>r;
        int idx=tmp-'a';
        auto l_pos=lower_bound(eng_index[idx].begin(),eng_index[idx].end(),l);
        auto r_pos=upper_bound(eng_index[idx].begin(),eng_index[idx].end(),r);
        cout<<r_pos-l_pos<<'\n';
    }
}