#include <iostream>
#include <vector>
#define COL 4
#include<algorithm>
using namespace std;
/*
(j!=k)
dp[i][j]=dp[i][j],dp[i-1][j]+arr[i][k] 
*/
int solution(vector<vector<int>> land)
{
    int ROW=land.size();
    for(int i(1);i<land.size();i++){
        for(int j(0);j<COL;j++){
            int tmp=0;
            for(int k(0);k<COL;k++){
                if(j==k) continue;
                tmp=max(tmp, land[i-1][k]+land[i][j]);
            }
            land[i][j]=max(land[i][j], tmp);
        }
    }
    
    return *max_element(land[ROW-1].begin(), land[ROW-1].end());
}