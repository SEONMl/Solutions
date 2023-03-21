#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(), score.end(), greater<>());
    int idx=0;
    int answer = 0;
    if(score.size()<m) return 0;
    while(idx<=score.size()-m){
        int minValue = *min_element(score.begin()+idx, score.begin()+idx+m);
        answer+=minValue*m;
        idx+=m;
    }
    return answer;
}