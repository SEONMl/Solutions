#include <string>
#include <vector>
#define MAX 101
#include<algorithm>
using namespace std;

int solution(vector<int> cards) {
    vector<int> p(cards.size()+1);
    
    for(int i(0);i<cards.size();i++){
        int cur=cards[i];
        while(p[cur]==0){
            p[cur]=i+1;
            cur=cards[cur-1];
        }
    }
    
    int k[MAX]={0};
    for(int i(1);i<=cards.size();i++){
        k[p[i]]++;
    }
    
    sort(k,k+MAX,greater<>());
    return k[0]*k[1];
}