#include<iostream>
#include<string>
using namespace std;
int N;
bool isPali(int n){
    string s=to_string(n);
    int len=s.length();
    if(s[0]!=s[len-1]) return false;
    if(s[1]!=s[len-2]) return false;
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
        if(i<len/2){
            if(s[i]!=s[len-1-i]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    cin>>N;
    while(true){
        if(isPali(N)) {
            break;
        }
        N++;
    }
    cout<<N;
}