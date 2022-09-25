#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
using namespace std;
int N,a,b,c,cnt;
int arr[101];
int main(){
    cin>>N;
    vector<tuple<int,int,int>> v;
    for(int i=0;i<N;i++){
        cin>>a>>b>>c;
        v.push_back(make_tuple(c,b,a));
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<v.size();i++){
        if(cnt==3) break;
        if(arr[get<2>(v[i])]==2) continue;
        cout<<get<2>(v[i])<<" "<<get<1>(v[i])<<endl;
        arr[get<2>(v[i])]++;
        cnt++;
    }
    return 0;
}
// 전역변수는 0으로 초기화 되는듯