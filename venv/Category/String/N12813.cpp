#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a,b;
    cin>>a>>b;
    fse(0,MAX,1){
        cout<<((a[i]-'0')&(b[i]-'0'));
    }cout<<'\n';

    fse(0,MAX,1){
        cout<<((a[i]-'0')|(b[i]-'0'));
    }cout<<'\n';

    fse(0,MAX,1){
        cout<<((a[i]-'0')^(b[i]-'0'));
    }cout<<'\n';

    fse(0,MAX,1){
        cout<<(~(a[i]-'0')+2);
    }cout<<'\n';
    
    fse(0,MAX,1){
        cout<<((b[i]-'0')?0:1);
    }cout<<'\n';
}