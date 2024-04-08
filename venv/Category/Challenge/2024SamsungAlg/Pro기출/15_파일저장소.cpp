using namespace std;
#include<map>
#include<unordered_map>
#include<vector>
int N;
unordered_map<int, vector<pair<int,int>>> fileIdx;
map<int,int> disk;
int usage;
void init(int n) { // 2천5백만
	N=n; usage=0;
	fileIdx.clear();
	disk.clear();

	disk = {{-1,-1}, {N,N}};
	return;
}

int add(int mId, int mSize) { // 12000
	if(usage+mSize > N) return -1;
	usage+=mSize;

	auto &vec = fileIdx[mId];

	int ret = disk.begin()->second + 1;
	for(auto i = disk.begin(), j = next(disk.begin()); mSize && j != disk.end(); ){
		int from = i->second + 1;
		if(j->first - 1 <= from + mSize - 1){
			int to = j->first-1;
			i->second = j->second;
			j = disk.erase(j);

			mSize -= (to-from + 1);
			vec.push_back({from, to});
		} else{
			i->second = from+mSize-1;
			vec.push_back({from, from+mSize-1});
			break;
		}
	}
	// 저장된 공간의 가장 앞 서는 주소
	return ret+1;
}

int remove(int mId) { // 7000
	auto &vec = fileIdx[mId];
	int ret = (int) vec.size();

	for(auto &pa: vec){
		int s = pa.first, e= pa.second;

		usage -= e - s + 1;
		auto it = --disk.upper_bound(s); // 해당 원소 다음 인덱스 반환
		if(e < it->second){
			disk.insert( {e+1, it->second});
		}

		if(it->first < s){
			it->second = s - 1;
		}else{
			disk.erase(it);
		}
	}

	fileIdx.erase(mId);
	// 저장되어 있던 파일 조각의 개수
	return ret;
}

bool comp(pair<int,int> a, pair<int,int> b){
	return a.second>=b.first;
}
int count(int mStart, int mEnd) { // 1000
	mStart--; mEnd--;

	int ret = 0;
	for(auto &tar: fileIdx)
	{
		int id = tar.first; auto &vec = tar.second;

		int left = 0, right = (int) vec.size();
		while(left<right){
			int mid = (left+right)/2;
			if(vec[mid].first > mStart){
				right = mid;
			}else{
				left = mid+1;
			}
		}

		// 종류당 겹치는 부분이 있는지 없는지 확인
		if(right != (int)vec.size() && vec[right].first <= mEnd) ret++;
		else if(right != 0 && vec[right-1].second >= mStart) ret++;
	}
	
	return ret;

}






#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N);
extern int add(int mId, int mSize);
extern int remove(int mId);
extern int count(int mStart, int mEnd);

/////////////////////////////////////////////////////////////////////////

#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_REMOVE 3
#define CMD_COUNT 4

static bool run() {
	int q;
	scanf("%d", &q);

	int mid, msize, mstart, mend, n;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				scanf("%d", &n);
				init(n);
				okay = true;
				break;
			case CMD_ADD:
				scanf("%d %d %d", &mid, &msize, &ans);
				ret = add(mid, msize);
				if (ans != ret)
					okay = false;
				break;
			case CMD_REMOVE:
				scanf("%d %d", &mid, &ans);
				ret = remove(mid);
				if (ans != ret)
					okay = false;
				break;
			case CMD_COUNT:
				scanf("%d %d %d", &mstart, &mend, &ans);
				ret = count(mstart, mend);
				if (ans != ret)
					okay = false;
				break;
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);    
	freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}