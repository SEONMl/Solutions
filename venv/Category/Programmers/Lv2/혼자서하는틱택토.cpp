#include <string>
#include <vector>
#define SIZE 3
using namespace std;

bool hasCorrectCount(int o,int x){
    if(o-x==0 || o-x==1) return true;
    return false;
}
int dx[]={0,1,1,1};
int dy[]={1,0,1,-1};

bool isOver(vector<string> board,int x,int y,int idx){
    char c=board[x][y];
    while(0<=x&&x<SIZE && 0<=y&&y<SIZE && board[x][y]==c){
        x+=dx[idx];
        y+=dy[idx];
    }
    if(x==SIZE ||y==SIZE){
        return true;
    }
    return false;
}

int solution(vector<string> board) {
    int Ocnt=0;
    int Xcnt=0;
    for(auto row : board){
        for(char ch: row){
            if(ch=='O') Ocnt++;
            else if(ch=='X') Xcnt++;
        }
    }
    if(!hasCorrectCount(Ocnt,Xcnt)) return 0;

    if(Ocnt>=SIZE){
        int Ores=0;
        int Xres=0;
        for(int i(0);i<SIZE;i++){
            if(board[i][0]=='O') Ores+=isOver(board,i,0,0);
            if(board[0][i]=='O') Ores+=isOver(board,0,i,1);
            
            if(board[i][0]=='X') Xres+=isOver(board,i,0,0);                
            if(board[0][i]=='X') Xres+=isOver(board,0,i,1);
        }
        if(board[0][0]=='O') Ores+=isOver(board,0,0,2);
        if(board[0][0]=='X') Xres+=isOver(board,0,0,2);
        if(board[0][SIZE-1]=='O') Ores+=isOver(board,0,SIZE-1,3);
        if(board[0][SIZE-1]=='X') Xres+=isOver(board,0,SIZE-1,3);

        if(Ores>0 && Xres==0 && Ocnt>Xcnt) return 1;
        if(Ores==0 && Xres>0 && Ocnt==Xcnt) return 1;
        if(Ores==0&&Xres==0) return 1;
        return 0;
    }
    return 1;
}