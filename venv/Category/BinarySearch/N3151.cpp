#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int N,a,b,tmp;
vector<int> v;
ll cnt;
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&tmp);
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            tmp=(-1)*(v[i]+v[j]);
            a=lower_bound(v.begin()+j+1,v.end(),tmp)-v.begin();
            b=upper_bound(v.begin()+j+1,v.end(),tmp)-v.begin();
            if(a==N) continue;
            if(-tmp+v[a]==0)cnt+=b-a;
        }
    }
    printf("%d",cnt);
    return 0;
}