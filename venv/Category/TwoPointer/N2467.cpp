#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int N,a[100001],ans[2];
void bs(){
    int s=0;
    int e=N-1;
    int m=INT32_MAX;
    int tmp;
    while (s<e){
        tmp=a[s]+a[e];
        if(abs(tmp)<m){
            m=abs(tmp);
            ans[0]=a[s];
            ans[1]=a[e];
        }
        if(tmp>0) e--;
        else s++;
    }
}
int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    bs();
    printf("%d %d",ans[0],ans[1]);
return 0;
}


/*
자료형 크기 및 범위
int(4byte) : -21억 ~ 21억
long(4byte) : -21억 ~ 21억
char(1byte) : -128 ~ 127
long long(8byte) : ? 셀 수 없음(대충 1000해?)
1차원 배열 메모리 : 최대 258,000
2차원 배열 : 508*508
3차원 배열 : 63*63*63

typedef (자료형) ()
*/