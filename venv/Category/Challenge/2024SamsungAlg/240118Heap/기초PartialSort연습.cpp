#define MAX_USER 10
#define INF 987654321
using namespace std;
int N;
struct Pair{
    int income;
    int uID;
    Pair():income(0), uID(0){}
};
Pair arr[MAX_USER+2];
void init()
{
    N=0;
}

void addUser(int uID, int income) 
{
    if(N>=10 && income<arr[9].income) return;

    int i=N-1;
    while(i>=0){
        if(arr[i].income >= income) break;
        i--;
    }
    for(int j=N;j>i;j--){
        arr[j+1]=arr[j];
    }

    arr[i+1].uID= uID;
    arr[i+1].income=income;
    
    if(N<10)N++;
}
#include<iostream>
int getTop10(int result[10]) 
{
    for(int i(0);i<N;i++){
        result[i]=arr[i].uID;
    }
    return N;
}







#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_INPUT 10000
#define MAX_NUM 30000

extern void init();
extern void addUser(int uID, int income);
extern int getTop10(int result[10]);

static int input[MAX_INPUT];

static unsigned int seed = 13410;

static unsigned int pseudoRand() {
	seed = seed * 214013 + 2531011;
	return (unsigned int)(seed >> 11) % MAX_NUM;
}

static void makeInput(int inputLen) {
	for (int i = 0; i < inputLen; i++) {
		input[i] = pseudoRand();
	}
}

static int run() {
	int N, userNum, uID = 0;
	int score = 100, result[10], cnt;
	int sum, check;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &userNum);
		makeInput(userNum);
		for (int j = 0; j < userNum; j++) {
			addUser(uID++, input[j]);
		}
		cnt = getTop10(result);

		sum = 0;
		for (int j = 0; j < cnt; j++)
			sum += result[j];
		scanf("%d", &check);
		if (check != sum)
			score = 0;
	}
	return score;
}

int main(void) {
	setbuf(stdout, NULL);
	//freopen("partial_sort_input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		init();
		printf("#%d %d\n", tc, run());
	}
	return 0;
}