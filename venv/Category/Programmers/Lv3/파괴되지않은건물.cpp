#include <string>
#include <vector>
#include<algorithm>
#define MAX 1001
#include<iostream>
using namespace std;
/*
0이하 파괴 상태 : 계쏙 내구도 하락
skill[0] 1: -
skill[0] 2: +
최종 상태

누적합 이용하는 미친 풀이
*/
int g[MAX][MAX];
int solution(vector<vector<int>> board, vector<vector<int>> skills) {
    int N=board.size();
    int M=board[0].size();
    
    // skill 처리
    for(auto s: skills){
        int type,x1,y1,x2,y2,deg;
        type=s[0];x1=s[1];y1=s[2];x2=s[3];y2=s[4];deg=s[5];
        if(type==1){
            deg*=(-1);
        }
        g[x1][y1]+=deg;
        g[x1][y2+1]+=-deg;
        g[x2+1][y1]+=-deg;
        g[x2+1][y2+1]+=deg;
    }
    for(int i(0);i<N;i++){
        for(int j(0);j<M-1;j++){
            g[i][j+1]+=g[i][j];
        }
    }
    for(int i(0);i<N-1;i++){
        for(int j(0);j<M;j++){
            g[i+1][j]+=g[i][j];
        }
    }
    
    int answer = 0;
    for(int i(0);i<N;i++){
        for(int j(0);j<M;j++){
            if(g[i][j]+board[i][j]>0) answer++;
        }
    }
    return answer;
}
// 정확성 56점, 효율성 44점