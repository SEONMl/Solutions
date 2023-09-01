#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>
#define MAX 16
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int g[MAX][MAX]={
    {0,0,0,0,0, 0,17,17,17,17, 0,0,0,0,0, 0},
    {0,0,0,0,0, 4,17,17,17,17, 1,0,0,0,0, 0},
    {0,0,0,7,7, 4,4,12,12,1,   1,5,5,0,0, 0},
    {0,0,7,7,7, 4,4,12,12,1,   1,5,5,5,0, 0},
    {0,0,7,7,7, 4,4,12,12,1,   1,5,5,5,0, 0},

    {0,16,16,16,16, 4,4,12,1,  1,13,13,13,13, 0},
    {19,19,16,16,16, 16,4,12,12,1, 13,13,13,13,20, 20},
    {19,19,10,10,10, 10,10,25,25,9, 9,9,9,9,20, 20},
    {19,19,10,10,10, 10,10,25,25,9, 9,9,9,9,20, 20},
    {19,19,15,15,15, 15,3,11,11,2, 14,14,14,14,20, 20},

    {0,15,15,15,15, 3,3,11,11,2, 2,14,14,14,14, 0},
    {0,0,6,6,6, 3,3,11,11,2, 2,8,8,8,0, 0},
    {0,0,6,6,6, 3,3,11,11,2, 2,8,8,8,0, 0},
    {0,0,0,6,6, 3,3,11,11,2, 2,8,8,0,0, 0},
    {0,0,0,0,0, 3,18,18,18,18, 2,0,0,0,0, 0},

    {0,0,0,0,0, 0,18,18,18,18, 0,0,0,0,0, 0}
};
vector<int> condition[9]={{5},{6},{7},{8},{17,18},{9,10},{11,12},{19,20},{25}};
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string dart;
    cin>>dart;
    stringstream ss(dart);

    vector<int> num;
    string tmp;
    while(getline(ss,tmp, ',')){
        num.push_back(stoi(tmp));
    }
    int ROUND = num.size()/6;
    int score=40;
    for(int i(0);i<ROUND;i++){
        int offset=i*6;
        int a1,a2,b1,b2,c1,c2;
        a1=num[offset]; a2=num[offset+1]; b1=num[offset+2]; b2=num[offset+3];
        c1=num[offset+4]; c2=num[offset+5];

        bool hit=false;
        for(auto target:condition[i]){
            if(g[a2][a1]==target){
                score+=target;
                hit=true;
            }
            if(g[b2][b1]==target){
                score+=target;
                hit=true;
            }
            if(g[c2][c1]==target){
                score+=target;
                hit=true;
            }
        }

        if(!hit){
            double tmp=score;
            if(score==1 ||score==0 )score=0;
            else score= round(tmp/2.0);
        }
    }
    cout<<score;
}

#include <iostream>
#include <sstream>
#include <vector>
#include<cmath>
#define MAX 16

using namespace std;
int g[MAX][MAX]={
    {0,0,0,0,0, 0,17,17,17,17, 0,0,0,0,0, 0},
    {0,0,0,0,0, 4,17,17,17,17, 1,0,0,0,0, 0},
    {0,0,0,7,7, 4,4,12,12,1,   1,5,5,0,0, 0},
    {0,0,7,7,7, 4,4,12,12,1,   1,5,5,5,0, 0},
    {0,0,7,7,7, 4,4,12,12,1,   1,5,5,5,0, 0},

    {0,16,16,16,16, 4,4,12,1,1, 1,13,13,13,13, 0},
    {19,19,16,16,16, 16,4,12,12,1, 13,13,13,13,20, 20},
    {19,19,10,10,10, 10,10,25,25,9, 9,9,9,9,20, 20},
    {19,19,10,10,10, 10,10,25,25,9, 9,9,9,9,20, 20},
    {19,19,15,15,15, 15,3,11,11,2, 14,14,14,14,20, 20},

    {0,15,15,15,15, 3,3,11,11,2, 2,14,14,14,14, 0},
    {0,0,6,6,6, 3,3,11,11,2, 2,8,8,8,0, 0},
    {0,0,6,6,6, 3,3,11,11,2, 2,8,8,8,0, 0},
    {0,0,0,6,6, 3,3,11,11,2, 2,8,8,0,0, 0},
    {0,0,0,0,0, 3,18,18,18,18, 2,0,0,0,0, 0},

    {0,0,0,0,0, 0,18,18,18,18, 0,0,0,0,0, 0}
};
vector<int> condition[9]={{5},{6},{7},{8},{17,18},{9,10},{11,12},{19,20},{25}};
int solution(vector<int> num) {
	int ROUND = num.size()/6;
    int score=40;
	
    for(int i(0);i<ROUND;i++){
        int offset=i*6;
        int a1,a2,b1,b2,c1,c2;
        a1=num[offset]; a2=num[offset+1]; b1=num[offset+2]; b2=num[offset+3];
        c1=num[offset+4]; c2=num[offset+5];

        bool hit=false;
        for(auto target:condition[i]){
            if(g[a2][a1]==target){
                score+=target;
                hit=true;
            }
            if(g[b2][b1]==target){
                score+=target;
                hit=true;
            }
            if(g[c2][c1]==target){
                score+=target;
                hit=true;
            }
        }

        if(!hit){
            double tmp=score;
            if(score==1 ||score==0 )score=0;
            else score= round(tmp/2.0);
        }
    }
	return score;
}