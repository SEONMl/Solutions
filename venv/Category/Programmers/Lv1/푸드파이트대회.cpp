#include <string>
#include <vector>
#include<algorithm>
using namespace std;

string solution(vector<int> food) {
    string tmp = "";
    for(int i(1);i<food.size();i++){
        for(int j(0);j<food[i]/2;j++)
            tmp.push_back((char)(i+'0'));
    }
    string ans=tmp+"0";
    reverse(tmp.begin(),tmp.end());
    ans+=tmp;
    return ans;
}