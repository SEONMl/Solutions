#include <string>
#include <vector>
#include<algorithm>
using namespace std;
typedef long long ll;
long long solution(vector<int> seq) {
    int N=seq.size();
    vector<ll> arr;
    arr.push_back(seq[0]);

    for(int i(1);i<N;i++){
        if(i%2) arr.push_back(arr[i-1]+(-1)*seq[i]);
        else arr.push_back(arr[i-1]+seq[i]);
    }
    ll maxValue=*max_element(arr.begin(),arr.end());
    ll minValue=*min_element(arr.begin(),arr.end());
    
    ll answer = abs(maxValue-minValue);
    answer=max(abs(maxValue), answer);
    answer=max(abs(minValue), answer);
    return answer;
}