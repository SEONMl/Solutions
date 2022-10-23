#include<iostream>
#include<algorithm>
using namespace std;
int N,x,y;
pair<int,int> a[100000];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int ans=9e8;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>x>>y;
        a[i]=make_pair(x,y);
    }
    int total=0;
    for(int i=1;i<N;i++){
        total+=abs(a[i].first-a[i-1].first)+abs(a[i].second-a[i-1].second);
    }
    for(int i=1;i<N-1;i++){
        int tmp=0;
        tmp+=abs(a[i].first-a[i-1].first)+abs(a[i].second-a[i-1].second)+
            abs(a[i].first-a[i+1].first)+abs(a[i].second-a[i+1].second)-
            (abs(a[i+1].first-a[i-1].first)+abs(a[i+1].second-a[i-1].second));
        ans=min(ans,total-tmp);
    }
    cout<<ans;
return 0;
}