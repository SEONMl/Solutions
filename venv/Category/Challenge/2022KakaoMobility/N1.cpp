#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(const vector<int>& v1, const vector<int>& v2){
    if(v1[1] == v2[1]) return v1[0]<v2[0];
    else return v1[1]<v2[1];
}
int solution(vector<vector<int>> flowers) {
    int n=flowers.size();
    sort(flowers.begin(), flowers.end(), comp);

    int startDate=flowers[0][0];
    int endDate = flowers[0][1];
    int total = 0;

    for(int i(1);i<n;i++){
        if(flowers[i][0]<=endDate){
            endDate=flowers[i][1];
        }
        else{
            total+=endDate-startDate;
            startDate=flowers[i][0];
            endDate=flowers[i][1];
        }
    }
    total+=endDate-startDate;

    return total;
}

int main() {
    cout<<solution({{3, 4}, {8, 10} , {6, 7},{4,5}});
}