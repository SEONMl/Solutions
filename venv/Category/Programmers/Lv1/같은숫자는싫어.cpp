#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int N=arr.size();
    for(int i=0;i<N;i++){
        if(!answer.empty() && answer.back()==arr[i])continue;
        answer.push_back(arr[i]);
    }

    return answer;
}