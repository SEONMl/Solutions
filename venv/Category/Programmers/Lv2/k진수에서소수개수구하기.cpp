#include <string>
#include <vector>
#define MAX 1'000'000
using namespace std;
bool prime[MAX];
void primeChae(){
    for(int i(2);i<MAX;i++) prime[i]=true;
    prime[0]=prime[1]=false;
    for(int i(2);i<MAX*0.5+1;i++){
        if(!prime[i]) continue;
        for(int j(i*2);j<MAX;j+=i){
            prime[j]=false;
        }
    }
}
bool isPrime(long long num){ //이게 더 빠름
    if(num==1)return false;
    for(long long i=2; i*i<=num; i++){
        if(num%i==0) return false;
    }
    return true;
}
string trans(int n,int k){
    vector<char> v;
    while(n){
        if(n>k){
            v.push_back(n%k+'0');
        }else{
            v.push_back(n+'0');
        }
        n/=k;
    }
    string kjinsu="";
    for(int i(v.size()-1);i>-1;i--){
        kjinsu+=v[i];
    }
    return kjinsu;
}
#include<iostream>
int findPrime(string jin){
    int cnt=0;
    size_t pos=0;
    while((pos=jin.find('0'))!=string::npos){
        string sub=jin.substr(0,pos);
        if(sub.length()>0 && isPrime(stol(sub))) cnt++;
        jin.erase(0,pos+1);
    }
    if(jin.length()>0 && isPrime(stol(jin))) cnt++;
    return cnt;
}

int solution(int n, int k) {
    return findPrime(trans(n,k));
}
int main(){
    cout<<solution(36,2);
}