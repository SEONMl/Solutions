#include <string>
#include <vector>

using namespace std;

string solution(vector<string> c1, vector<string> c2, vector<string> goal) {
    int idx1=0,idx2=0,idx3=0;
    while(idx3<goal.size()){
        if(c1[idx1]==goal[idx3]) {
            idx1++; idx3++;
        }
        else if(c2[idx2]==goal[idx3]) {
            idx2++; idx3++;
        }
        else break;
    }
    if(idx3==goal.size()) return "Yes";
    return "No";
}