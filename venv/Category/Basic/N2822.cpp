#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int total=0;
    int n;
    vector<pair<int,int>> v;
    vector<int> idx;
    for(int i=1;i<9;i++){
        cin>>n;
        v.push_back(make_pair(n,i));
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    for(int i=0;i<5;i++){
        total+=v[i].first;
        idx.push_back(v[i].second);
    }
    cout<<total<<endl;
    sort(idx.begin(),idx.end());
    for(int i=0;i<5;i++){
        cout<<idx[i]<<" ";
    }
    cout<<endl;
   return 0; 
}

// 빌드 Ctrl+Alt+C