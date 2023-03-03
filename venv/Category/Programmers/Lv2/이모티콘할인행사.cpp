#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
#define MAX 101

using namespace std;
int percent[]={10,20,30,40};
int N;
vector<int> ans={0,0};
vector<int> calculEmoPremium(vector<vector<int>> users,vector<int> purchase){
    int premium=0;
    int emoProfit=0;
    for(int i(0);i<N;i++){
        if(users[i][1]<=purchase[i]){
            premium++;
        }else{
            emoProfit+=purchase[i];
        }
    }
    return {premium, emoProfit};
}
void dfs(int d, vector<vector<int>> users, vector<int> emo, vector<int> purchase){
    if(d==emo.size()){     // 빡대가리냐 범위 하나때문에 얼마나 시간 날린거야 하...............
        vector<int> res=calculEmoPremium(users, purchase);
        if(ans[0]<res[0]){
            ans=res;
        }else if(ans[0]==res[0]){
            ans[1]=max(ans[1],res[1]);
        }
        return;
    }
    
    for(int i(0);i<4;i++){
        int curPrice=(emo[d]*(100-percent[i]))/100;
        vector<int> tmp_pur=purchase;
        for(int j(0);j<N;j++){
            if(users[j][0]<=percent[i]){
                tmp_pur[j]+=curPrice;
            }
        }
        dfs(d+1, users, emo, tmp_pur);
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    N=users.size();
    vector<int> v;
    for(int i(0);i<N;i++) v.push_back(0);
    dfs(0, users, emoticons, v);
    cout<<ans[0]<<" "<<ans[1];
    return ans;
}


#include<iostream>
int main(){
    solution({{40,2900},{23,10000},{11,5200},{5,5900},{40,3100},{27,9200},{32,6900}},{1300,1500,1600,4900});
    vector<int> ss={0,1,2,3,4};

}