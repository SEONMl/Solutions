#include <string>
#include <vector>
#include<algorithm>
using namespace std;
int K;
bool comp(vector<int> a, vector<int> b){
    if(a[K]<b[K]) return true;
    else if(a[K]>b[K]) return false;
    else{
        if(a[0]>b[0]) return true;
        else return false;
    }
}
int getSi(vector<int> data, int i){
    int Si=0;
    for(int k:data){
        Si+=(k%i);
    }
    return Si;
}
int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    K=col-1;
    sort(data.begin(),data.end(),comp);
    int answer = getSi(data[row_begin-1], row_begin);
    for(int i(row_begin+1);i<=row_end;i++){
        answer ^= getSi(data[i-1],i);
    }
    return answer;
}
// 8'00''