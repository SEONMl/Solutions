#include<iostream>
#include<algorithm>
using namespace std;
int N;
int a[20000];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    sort(a,&a[N]);
    pair<int,int> ans=make_pair(9e8,0);
    for(int i=0;i<N;i++){
        int tmp=0;
        if(i>0&&a[i-1]==a[i]) continue;
        for(int j=0;j<N;j++){
            tmp+=abs(a[i]-a[j]);
        }
        if(ans.first>tmp){
            ans.first=tmp;
            ans.second=a[i];
        }
    }
    cout<<ans.second;
    return 0;
}