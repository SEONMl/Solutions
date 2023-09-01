#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100'000
#define INF 2'147'483'647
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
typedef long long ll;
bool comp(pair<int,int> a, pair<int,int> b){
    if(a.second<b.second) { // 가격 적고 무게 많은 순
        return true;
    } else if (a.second==b.second){
        if(a.first>=b.first) return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,M;
    vector<pair<int,int>> meat; //무게,가격
    cin>>N>>M;
    fse(0,N,1){
        int a,b;
        cin>>a>>b;
        meat.push_back({a,b});
    }
    sort(meat.begin(), meat.end(), comp);

    int prevPrice=-1;
    int accumMuge=0; // 현재 가격보다 작은 것들 누적 무게

    int answer=INF;
    fse(0,N,1){
        int muge=meat[i].first;
        int price= meat[i].second;

        if(price == prevPrice) {
            accumMuge+=muge;
            continue;
        };
        prevPrice=price;
        accumMuge+=muge;
        int tmp=(M/accumMuge +((M%accumMuge)?1:0)) * price;
        answer=min(answer, tmp);
    }
    cout<<answer;   
}

/*
5 16
1 1
1 2
1 2
2 2
10 5

1 1000
1 1

5 100
1 0
2 0
4 0
2 0
4 1

3 2147483647
647 10
0 12
2147483000 122


*/