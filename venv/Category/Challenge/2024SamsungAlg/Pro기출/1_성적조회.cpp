#include<vector>
#include<map>
#include<set>
#include<string>
#include<tuple>
using namespace std;
struct Student{
	int id, score;
	Student(){}
	Student(int id,int s): id(id), score(s) {}
	~Student(){}
};
bool operator<(const Student &a, const Student &b){
	if(a.score != b.score) return a.score < b.score;
	return a.id < b.id;
}
map<int, tuple<int,int,int>> idx;
set<Student> combi[7];
bool isMale(char gender[]){
	return gender[0]=='m';
}
int getType(int grade, bool gender){
	return grade+((gender)?0:3);
}

void init() {
	idx.clear();
	for(int i=0;i<7;i++) combi[i].clear();
	return;
}
// grade&gender-score, 
int add(int mId , int mGrade, char mGender[7], int mScore) {
	Student stdt = Student(mId, mScore);
	idx.insert({mId, {mGrade, isMale(mGender), mScore}});

	int type = getType(mGrade, isMale(mGender));
	auto &tmp = combi[type];
	tmp.insert(stdt);
	return combi[type].rbegin()->id;
}

int remove(int mId) { // 10억 2만*6만 1'200'000'000
	if(idx.find(mId)==idx.end()) return 0;

	int grade, gender, score;
	tie(grade, gender, score)= idx[mId];

	set<Student> &tmp = combi[getType(grade, gender)];
	tmp.erase({mId, score});
	idx.erase(mId);

	if(tmp.empty()) return 0;
	return tmp.begin()->id;

	//삭제 후에 mId 학생의 학년과 성별이 동일한 학생 중에서 점수가 가장 낮은 학생의 ID를 반환한다.
	// 점수가 가장 낮은 학생이 여러 명이라면, 그 중에서 ID가 가장 작은 값을 반환한다.
    //삭제 후에, 학년과 성별이 동일한 학생이 없다면, 0을 반환한다.
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore) {
	Student ret(0, 987654321);
	for(int i=0;i<mGradeCnt; i++){
		for(int j=0;j<mGenderCnt;j++){
			int type = getType(mGrade[i], isMale(mGender[j]));
			set<Student> &tmp = combi[type];

			auto it = tmp.lower_bound({0,mScore});

			if(it != tmp.end() && *it<ret){
				ret = *it;
			}
		}
	}
	return ret.id;
	//mGrade 학년 집합과 mGender 성별 집합에 속하면서, 점수가 mScore 이상인 학생 중에서 점수가 가장 낮은 학생의 ID를 반환한다.
	// 6가지 lowerbound 중 min값
}
// mid <= 10억, score<=30만    score[300K] -> 이분탐색 ;







#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init();
extern int add(int mId, int mGrade, char mGender[7], int mScore);
extern int remove(int mId);
extern int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 100
#define CMD_ADD 200
#define CMD_REMOVE 300
#define CMD_QUERY 400

static bool run() {
	int q;
	scanf("%d", &q);

	int id, grade, score;
	char gender[7];
	int cmd, ans, ret;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				init();
				okay = true;
				break;
			case CMD_ADD:
				scanf("%d %d %s %d %d", &id, &grade, gender, &score, &ans);
				ret = add(id, grade, gender, score);
				if (ans != ret)
					okay = false;
				// printf("add ---------------- %d %d\n ", ans, ret);
				break;
			case CMD_REMOVE:
				scanf("%d %d", &id, &ans);
				ret = remove(id);
				if (ans != ret)
					okay = false;
				// printf("remove ---------------- %d %d \n", ans, ret);
				break;
			case CMD_QUERY: {
				int gradeCnt, genderCnt;
				int gradeArr[3];
				char genderArr[2][7];
				scanf("%d", &gradeCnt);
				if (gradeCnt == 1) {
					scanf("%d %d", &gradeArr[0], &genderCnt);
				} else if (gradeCnt == 2) {
					scanf("%d %d %d", &gradeArr[0], &gradeArr[1], &genderCnt);
				} else {
					scanf("%d %d %d %d", &gradeArr[0], &gradeArr[1], &gradeArr[2], &genderCnt);
				}
				if (genderCnt == 1) {
					scanf("%s %d %d", genderArr[0], &score, &ans);
				} else {
					scanf("%s %s %d %d", genderArr[0], genderArr[1], &score, &ans);
				}
				ret = query(gradeCnt, gradeArr, genderCnt, genderArr, score);
				if (ans != ret)
					okay = false;
				// printf("query ---------------- %d %d\n ", ans, ret);
				break;
			}
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}