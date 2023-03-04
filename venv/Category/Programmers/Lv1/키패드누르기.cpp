#include <string>
#include <vector>

using namespace std;
pair<int,int> num[10]={{3,1},{0,0},{0,1},{0,2},
                {1,0},{1,1},{1,2},
                {2,0},{2,1},{2,2}};


int calculateDistance(pair<int,int> to, pair<int,int> from){
    return abs(to.first-from.first)+abs(to.second-from.second);
}
string solution(vector<int> numbers, string hand) {
    pair<int,int> left,right;
    string answer = "";
    left={3,0}; right={3,2};
    for(auto next:numbers){
        auto to=num[next];
        if(next==1 || next==4 ||next==7){
            answer+="L";
            left=to;
        }else if(next==3||next==6||next==9){
            answer+="R";
            right=to;
        }else{
            // 가까운 손 계산
            int l_dis=calculateDistance(to, left);
            int r_dis=calculateDistance(to, right);
            if(l_dis<r_dis){
                answer+="L";
                left=to;
            }else if(r_dis<l_dis){
                answer+="R";
                right=to;
            }
            else{
                if(hand=="right"){
                    answer+="R";
                    right=to;
                }else{
                    answer+="L";
                    left=to;
                }
            }
        }
    }
    return answer;
}