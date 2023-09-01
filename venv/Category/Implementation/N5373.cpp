#include<iostream>
#include<vector>
#include<algorithm>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
vector<vector<vector<char>>> initCube(){ // {윗면, 오른쪽, 앞, 왼쪽, 뒤, 밑면}
    vector<vector<vector<char>>> cube={
        {{'w','w','w'},{'w','w','w'},{'w','w','w'}},
        {{'b','b','b'},{'b','b','b'},{'b','b','b'}},
        {{'r','r','r'},{'r','r','r'},{'r','r','r'}},
        {{'g','g','g'},{'g','g','g'},{'g','g','g'}},
        {{'o','o','o'},{'o','o','o'},{'o','o','o'}},
        {{'y','y','y'},{'y','y','y'},{'y','y','y'}},
    };
    return cube;
}
vector<vector<char>> rotateClock(vector<vector<char>> side, int flag){ // 1 반시계
    vector<vector<char>> rotated;
    for(int i(0);i<3;i++){
        if(flag){
            rotated.push_back({side[2-i][i],side[2-i][i],side[2-i][i]});
            continue;
        }
        rotated.push_back({side[2][i],side[1][i],side[0][i]});
    }
    return rotated;
}
vector<vector<vector<char>>> left(vector<vector<vector<char>>> cube){

}
vector<vector<vector<char>>> leftOrRight(vector<vector<vector<char>>> cube, bool left, int flag){
    int idx=(left)?0:2;
    int next[]={0,2,5,4,0};

    vector<vector<char>> tmp, prev = cube[next[0]];

    for(int i(0);i<4;i++){
        tmp=((left&&(flag==1)) || (!left&&(flag==0)))? cube[next[3-i]] : cube[next[i+1]];

        for(int j(0);j<3;j++){
            if((left&&(flag==1)) || (!left&&(flag==0))){ // 왼반, 우시
                cube[next[3-i]][j][idx]=prev[j][idx];
                continue;
            }
            cube[next[i+1]][j][idx]=prev[j][idx];
        }
        prev=tmp;
    }

    return cube;
}
vector<vector<vector<char>>> upOrDown(vector<vector<vector<char>>> cube, bool up, int flag){ 
    int idx=(up)?2:0;
    int next[]={4,1,2,3,4};

    vector<vector<char>> tmp, prev=cube[next[0]];
    for(int i(0);i<4;i++){ 
        tmp=((up&&(flag==1)) || (!up&&(flag==0)))? cube[next[3-i]] : cube[next[i+1]];

        for(int j(0);j<3;j++){
            if((up&&(flag==1)) || (!up&&(flag==0))){
                cube[next[3-i]][idx][j]=prev[idx][j];
                continue;
            }
            cube[next[i+1]][idx][j]=prev[idx][j];
        }
        prev=tmp;
    }

    return cube;
}
vector<vector<vector<char>>> cubing(vector<vector<vector<char>>> cur, char side, int flag){
    switch (side)  // U: 윗 면 0, D: 아랫 5, F: 앞 2, B: 뒷 4, L: 왼쪽 3, R: 오른쪽 1
    {
    case 'L':
        /* code */
        cur=leftOrRight(cur, true, flag);
        cur[3] = rotateClock(cur[3], flag);
        break;
    case 'R':
        cur=leftOrRight(cur, false, flag);
        cur[1]= rotateClock(cur[1], flag);
        break;
    case 'U':
        cur=upOrDown(cur, true, flag);
        cur[0]= rotateClock(cur[0], flag);
        break;
    case 'D':
        cur=upOrDown(cur, false, flag);
        cur[5]=rotateClock(cur[5], flag);
        break;
    case 'F':
        // cur[2]=rotateClock(cur[2], flag);
        break;
    case 'B':
        // cur[4]=rotateClock(cur[4], flag);
        break;
    
    default:
        break;
    }
    return cur;
}
void printAnswer(vector<vector<vector<char>>> cube, int side){
    for(int i(0);i<3;i++){
        for(int j(0);j<3;j++){
            cout<<cube[side][i][j];
        }cout<<'\n';
    }
}
int main(){
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    fse(0,T,1){
        int N;
        cin>>N;
        auto cube=initCube();
        for(int j(0);j<N;j++){
            char side,d;
            cin>>side>>d;
            int dir=(d=='+')? 0 : 1; // 0일 때 시계, 1일 때 반시계

            cube=cubing(cube, side, dir);
        }

        // printAnswer(cube,1);
        // printAnswer(cube,3);
        printAnswer(cube,4);
        printAnswer(cube,0);
        printAnswer(cube,2);
        // printAnswer(cube,5);
    }

}