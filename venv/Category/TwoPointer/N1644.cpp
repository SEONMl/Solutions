#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define MAX 4'000'001
using namespace std;
int N;
bool visit[MAX];
vector<int> prime;
vector<int> accumulate;

void sieveOfEratosthenes(){
    for(int i=2;i<=sqrt(N);i++){
        if(visit[i]==1) continue;

        for(int j=i+i;j<=N;j+=i){
            visit[j]=1;
        }
    }

    int prev=0;
    for(int i=2;i<=N;i++){
        if(visit[i]==false) {
            prime.push_back(i);
            prev+=i;
            accumulate.push_back(prev);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    sieveOfEratosthenes();
    
    int left=0,right=0,cnt=0;
    int tmp;
    while(right<accumulate.size()){
        if(left==0) tmp=accumulate[right];
        else tmp=accumulate[right]-accumulate[left-1];

        if(tmp>N) left++;
        else if(tmp<N) right++;
        else {
            cnt++;
            right++;
        }
    }
    cout<<cnt;
}
//cout<<"left:"<<left<<" right:"<<right<<" tmp:"<<tmp<<endl;