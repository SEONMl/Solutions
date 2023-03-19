#include <string>
#include <vector>
#include<algorithm>
#include<deque>

using namespace std;
int solu(vector<int> stones, int k){
    deque<int> dq;
    for(int i=0;i<k;i++){
        if(dq.empty()) dq.push_back(stones[i]);
        
    }
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    int N=stones.size();
    int left=0,right=k-1;
    vector<int> v;
    while(right<N){
        int m=0;
        for(int i=left;i<=right;i++){
            m=max(m,stones[i]);
        }
        v.push_back(m);
        left++; right++;
    }
    return *min_element(v.begin(),v.end());
}