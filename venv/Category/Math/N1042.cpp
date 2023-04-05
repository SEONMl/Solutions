#include<iostream>
#include<vector>
#include<algorithm>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
typedef unsigned long long ll;

ll getCountOfSide(int idx, ll N){
    switch (idx)
    {
    case 1:
        return (N-2)*(N-1)*4+(N-2)*(N-2);
    case 2:
        return (N-1)*4 +(N-2)*4;
    case 3:
        return 4;
    default:
        break;
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll N;
    cin>>N;
    int dice[6];
    fse(0,6,1) cin>>dice[i];
    if(N==1){
        int t=0;
        fse(0,6,1){
            t+=dice[i];
        }
        cout<< t-*max_element(dice,dice+6);
        return 0;
    }

    int type2arr[][2]={{0,1},{0,2},{0,3},{0,4}, {1,2},{1,3},{2,4},{3,4}, {1,5},{2,5},{3,5},{4,5}};
    int type3arr[][3]={{0,1,2},{0,1,3},{0,3,4},{0,2,4}, {5,1,2},{5,1,3},{5,3,4},{5,2,4}};

    int type1 = *min_element(dice,dice+6);
    int type2 = 9999999;
    int type3 = 99999999; // <= 1250
    for(int i(0);i<8;i++){
        int tmp=0;
        for(int j(0);j<3;j++){
            tmp+=dice[type3arr[i][j]];
        }
        type3=min(type3, tmp);
    }
    for(int i(0);i<12;i++){
        int tmp=0;
        for(int j(0);j<2;j++){
            tmp+=dice[type2arr[i][j]];
        }
        type2=min(type2, tmp);
    }

    ll cnt1=getCountOfSide(1,N);
    ll cnt2=getCountOfSide(2,N);
    ll cnt3=getCountOfSide(3,N);
    
    ll answer = cnt1*type1 + cnt2*type2 + cnt3*type3;
    cout<<answer;
}