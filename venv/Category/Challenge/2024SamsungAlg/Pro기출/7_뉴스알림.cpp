using namespace std;
#include<unordered_map>
#include<queue>
#include<set>
#define MAX 501
unordered_map<int, int> userId;
unordered_map<int, int> channelId;
unordered_map<int, int> newsId;
int N, K;
vector<int> channelSub[MAX];
struct NewsInfo {
	int id, originId, time, channel;

public:
	NewsInfo(int i, int oid, int t, int c) :id(i), originId(oid), time(t), channel(c) {}
};

struct cmp {
	bool operator()(const NewsInfo* a, const NewsInfo* b) {
		if (a->time != b->time) return a->time > b->time;
		else return a->originId > b->originId;
	}
};

priority_queue<NewsInfo*, vector<NewsInfo*>, cmp> pq;
bool removed[30000];
vector<NewsInfo*> received[MAX];

void init(int n, int k)
{
	N = n; K = k;
	userId.clear(); channelId.clear(); newsId.clear();
	pq = {};

	for (int i = 0; i < MAX; i++) {
		received[i].clear();
		channelSub[i].clear();
	}

	for (int i = 0; i < 30000; i++) {
		removed[i] = false;
	}
}

int getUserId(int uid) {
	if (userId.find(uid) != userId.end()) return userId[uid];
	userId[uid] = userId.size();
	return userId[uid];
}
int getChannelId(int channel) {
	if (channelId.find(channel) != channelId.end()) return channelId[channel];
	channelId[channel] = channelId.size();
	return channelId[channel];
}
int getNewsId(int news) {
	if (newsId.find(news) != newsId.end()) return newsId[news];
	newsId[news] = newsId.size();
	return newsId[news];
}

void sendNews(int current) {
	while (!pq.empty() && pq.top()->time <= current) {
		auto top = pq.top();

		pq.pop();

		if (removed[top->id]) continue;

		for (auto user : channelSub[top->channel]) {
			received[user].push_back(top);
		}
	}
}

void registerUser(int mTime, int mUID, int mNum, int mChannelIDs[]) // 5000
{
	sendNews(mTime);

	int uId = getUserId(mUID);
	for (int i = 0; i < mNum; i++) {
		int chId = getChannelId(mChannelIDs[i]);
		channelSub[chId].push_back(uId);
	}
}

int offerNews(int mTime, int mNewsID, int mDelay, int mChannelID) // 30000
{
	int chId = getChannelId(mChannelID);
	int neId = getNewsId(mNewsID);

	pq.push(new NewsInfo(neId, mNewsID, mTime + mDelay, chId));

	//mChannelID 뉴스 채널에 알림 등록한 유저의 수
	sendNews(mTime);
	return channelSub[chId].size();
}

void cancelNews(int mTime, int mNewsID) // 3000
{
	sendNews(mTime);

	int nId = getNewsId(mNewsID);
	removed[nId] = true;
}

int checkUser(int mTime, int mUID, int mRetIDs[]) //1000
{
	sendNews(mTime);

	int uId = getUserId(mUID);
	int ret = 0;
	for (int i = received[uId].size() - 1; i >= 0; i--) {
		NewsInfo* tar = received[uId][i];

		if (removed[tar->id]) continue;
		if (ret < 3) mRetIDs[ret] = tar->originId;
		ret++;
	}

	received[uId].clear();
	return ret;
}








#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void init(int N, int K);
extern void registerUser(int mTime, int mUID, int mNum, int mGroupIDs[]);
extern int offerNews(int mTime, int mNewsID, int mDelay, int mGroupID);
extern void cancelNews(int mTime, int mNewsID);
extern int checkUser(int mTime, int mUID, int mRetIDs[]);

/////////////////////////////////////////////////////////////////////////

#define INIT	0
#define REGI	1
#define OFFER	2
#define CANCEL	3
#define CHECK	4

static int gids[30];
static int ansids[3];
static int retids[3];
static bool run()
{
	int N, K;
	int cmd, ans, ret;
	int time, num, uid, gid, nid, delay;

	int Q = 0;
	bool okay = false;

	scanf("%d", &Q);
	for (int q = 0; q < Q; ++q)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case INIT:
			scanf("%d %d", &N, &K);
			init(N, K);
			okay = true;
			break;

		case REGI:
			scanf("%d %d %d", &time, &uid, &num);
			for (int m = 0; m < num; m++) {
				scanf("%d", &gids[m]);
			}
			registerUser(time, uid, num, gids);
			break;

		case OFFER:
			scanf("%d %d %d %d %d", &time, &nid, &delay, &gid, &ans);
			ret = offerNews(time, nid, delay, gid);
			if (ans != ret) {
				okay = false;
			}
			break;

		case CANCEL:
			scanf("%d %d", &time, &nid);
			cancelNews(time, nid);
			break;

		case CHECK:
			scanf("%d %d %d", &time, &uid, &ans);
			ret = checkUser(time, uid, retids);

			num = ans;
			if (num > 3) num = 3;
			for (int m = 0; m < num; m++) {
				scanf("%d", &ansids[m]);
			}
			if (ans != ret) {
				okay = false;
			}
			else {
				for (int m = 0; m < num; m++) {
					if (ansids[m] != retids[m]) {
						okay = false;
					}
				}
			}
			break;

		default:
			okay = false;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}