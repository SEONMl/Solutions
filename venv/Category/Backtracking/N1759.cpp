#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#define MAX 16
using namespace std;
int L,C;
vector<char> a;
bool eng[]={0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1};
string str="";
void dfs(int depth,int k,string tmp){
    if(depth==L) {
        int mo=0; // 모음..
        int ja=0; // 자음...
        for(int i=0;i<L;i++){
            if(eng[tmp[i]-97]) ja++;
            else mo++;
        }
        if(mo>=1&&ja>=2) printf("%s\n",tmp.c_str());//cout<<tmp<<endl;
    }
    for(int i=k+1;i<C;i++){
        dfs(depth+1,i,tmp+a[i]);
    }
}
int main(){
    scanf("%d %d",&L,&C);
    char t;
    for(int i=0;i<C;i++){
        scanf("%s",&t);
        a.push_back(t);
    }
    sort(a.begin(),a.end());
    string tmp="";
    for(int i=0;i<C;i++){
        dfs(1,i,tmp+a[i]);
    }
    return 0;
}


/*
string printf로 찍기
C++의 string은 C에는 정의되어 있지 않은 타입
C-Style로 변환해야 함
*.c_str()

char to string : 생성자 이용 string(size, char)
*/