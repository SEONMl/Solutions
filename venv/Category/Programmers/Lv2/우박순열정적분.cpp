#include <string>
#include <vector>
#include<iostream>
using namespace std;
vector<int> ubacSeq(int k){
    vector<int> v;
    v.push_back(k);
    while(k!=1){
        if(k%2){
            k=k*3+1;
        }else{
            k/=2;
        }
        v.push_back(k);
    }
    return v;
}
vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> seq=ubacSeq(k);
    vector<double> integral;
    
    integral.push_back((double)((seq[0]+seq[1]))/2);
    for(int i(1);i<seq.size()-1;i++){
        double tmp=(double)((seq[i]+seq[i+1]))/2;
        integral.push_back(tmp+integral.back());

    }
    int N=integral.size();
    for(auto range:ranges){
        int a=range[0], b=range[1];
        if(a>N+b){
            answer.push_back((double)(-1));
            continue;
        }
        if(a==0){
            answer.push_back(integral[N-1+b]);
        }else{
            answer.push_back(integral[N-1+b]-integral[a-1]);
        }
    }
    return answer;
}