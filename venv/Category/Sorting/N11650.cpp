#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,a,b;
vector<pair<int,int>> v;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end()); // 오름차순
    for(int i=0;i<n;i++){
        printf("%d %d \n",v[i].first,v[i].second);
    }
    return 0;
}

/*
2차원 벡터 
vector<vector<T>> v;
vector<pair<T,T>> v;

초기화
    std::vector<int> v(크기, 초기화값);
    std::vector<std::vector<int>> matrix(M, v);
or  
    vector<vector<int>> matrix(M, vector<int>(N, default_value));

Sort
sort(v.begin(), v.end()); // 오름차순
sort(v.begin(), v.end(), less<>()); // 오름차순
sort(v.begin(), v.end(), greater<>()); // 내림차순
*/