#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
string S,T;
bool ans;
int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    cin>>S>>T;
    while(1){
        if(S.size()==T.size()){
            if(S==T)ans=1;
            break;
        }
        if(T[T.size()-1]=='A') T.pop_back();
        else{
            T.pop_back();
            reverse(T.begin(),T.end());
        }

    }
    cout<<ans<<endl;
    return 0;
}