#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,L;
int g[MAX][MAX]; // 원본
int transposed[MAX][MAX]; // 전치 행렬
bool ROW= true, COL=false, FRONT=true, BACK=false;
bool isParallel(bool row,int idx){
    if(row){
        return ((*max_element(g[idx], g[idx]+N)-*min_element(g[idx], g[idx]+N))==0);
    }
    return ((*max_element(transposed[idx], transposed[idx]+N)-*min_element(transposed[idx], transposed[idx]+N))==0);
}
bool isParallelWhileL(bool row, bool front, int i,int idx){
    if(row){
        if(front){
            return ((*max_element(g[i]+idx, g[i]+idx+L)-*min_element(g[i]+idx, g[i]+idx+L))==0);
        }
        return ((*max_element(g[i]+idx-L, g[i]+idx)-*min_element(g[i]+idx-L, g[i]+idx))==0);
    }
    if(front){
        return ((*max_element(transposed[i]+idx, transposed[i]+idx+L)-*min_element(transposed[i]+idx, transposed[i]+idx+L))==0);
    }
    return ((*max_element(transposed[i]+idx-L, transposed[i]+idx)-*min_element(transposed[i]+idx-L, transposed[i]+idx))==0);
}
bool canInstall(bool *already, bool front, int idx){
    if(front) return ((*max_element(already+idx, already+idx+L))==0);
    return ((*max_element(already+idx-L, already+idx))==0);
}
int row(){
    int answer=0;
    fse(0,N,1){
        if(isParallel(true,i)){
            answer++;
            continue;
        }
        int prev=g[i][0];
        bool possible=true;
        bool alreadyInstalled[MAX]={0};
        for(int j(1);j<N;j++){
            if(prev==g[i][j]) continue;
            else if(abs(prev-g[i][j])>1) {
                possible=false;
                break;
            }
            else if(prev<g[i][j]){ // 1 2
                if(j>=L && canInstall(alreadyInstalled, BACK, j) && isParallelWhileL(ROW, BACK, i,j)) {
                    for(int k(0);k<L;k++){
                        alreadyInstalled[j-k-1]=true;
                    }
                    prev=g[i][j];
                }
                else {
                    possible=false;
                    break;
                }
            }else if(prev>g[i][j]){
                if(j+L<=N && canInstall(alreadyInstalled, FRONT, j) && isParallelWhileL(ROW, FRONT, i,j)){
                    for(int k(0);k<L;k++){
                        alreadyInstalled[j+k]=true;
                    }
                    prev=g[i][j];
                }else{
                    possible=false;
                    break;
                }
            }
        }

        if(possible){
            answer++;
        }
    }
    return answer;
}
int col(){
    int answer=0;
    fse(0,N,1){
        if(isParallel(false,i)){ //col
            answer++;
            continue;
        }
        int prev=transposed[i][0];
        bool possible=true;
        bool alreadyInstalled[MAX]={0};
        for(int j(1);j<N;j++){
            if(prev==transposed[i][j]) continue;
            else if(abs(prev-transposed[i][j])>1) {
                possible=false;
                break;
            }
            else if(prev<transposed[i][j]){ // 1 2
                if(j>=L && canInstall(alreadyInstalled, BACK, j) && isParallelWhileL(COL, BACK, i,j)) {
                    for(int k(0);k<L;k++){
                        alreadyInstalled[j-k-1]=true;
                    }
                    prev=transposed[i][j];
                }
                else {
                    possible=false;
                    break;
                }
            }else if(prev>transposed[i][j]){
                if(j+L<=N && canInstall(alreadyInstalled, FRONT, j) && isParallelWhileL(COL, FRONT, i,j)){
                    for(int k(0);k<L;k++){
                        alreadyInstalled[j+k]=true;
                    }
                    prev=transposed[i][j];
                }else{
                    possible=false;
                    break;
                }
            }
        }
        if(possible){
            answer++;
        }
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N>>L;
    for(int i(0);i<N;i++){
        for(int j(0);j<N;j++){
            cin>>g[i][j];
            transposed[j][i]=g[i][j];
        }
    }

    int answer=0;
    answer += row();
    answer += col();
    
    cout<<answer;
}