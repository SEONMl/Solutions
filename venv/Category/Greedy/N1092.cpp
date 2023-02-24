#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10'000
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;
int N,limit[50],M;
vector<int> box;

int solution(){
    if(limit[0]<box[0]) return -1;
    int minute=0;

    while(!box.empty()){
        fse(0,N,1){
            for(int j(0);j<box.size();j++){
                if(limit[i]>=box[j]){
                    box.erase(box.begin()+j);
                    break;
                }
            }
        }
        minute++;
    }
    return minute;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    fse(0,N,1) cin>>limit[i];
    cin>>M;
    fse(0,M,1){
        int t;
        cin>>t;
        box.push_back(t);
    }

    sort(limit, limit+N, greater<>());
    sort(box.begin(),box.end(),greater<>());
    
    cout<<solution();
}
/*
4
1 2 3 4
8
1 1 2 2 3 3 4 4
*/