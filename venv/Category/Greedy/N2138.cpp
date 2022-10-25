#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int N,cnt;
string a,b,tmp;
void swap(int i){
    tmp[i]=(tmp[i]=='0')?'1':'0';
    if(i!=0)tmp[i-1]=(tmp[i-1]=='0')?'1':'0';
    if(i!=N-1)tmp[i+1]=(tmp[i+1]=='0')?'1':'0';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>a>>b;
    int ans=9e8;
    for(int k=0;k<2;k++){
        tmp=a;
        cnt=0;
        if(k==1){swap(0);cnt++;}
        for(int i=1;i<N;i++){
            if(tmp[i-1]!=b[i-1]){
                swap(i);
                cnt++;
            }
        }
        if(tmp==b)ans=min(ans,cnt);
    }
    if(ans!=9e8)cout<<ans;
    else cout<<-1;
return 0;
}
// 왼쪽부터 확인
// 첫 번째 index가 중요