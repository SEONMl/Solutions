#include <string>
#include <vector>
#include<set>
#include<iostream>

using namespace std;

int solution(vector<int> elements) {
    int N=elements.size();
    vector<int> v;
    set<int> s;
    v.push_back(elements[0]);
    s.insert(elements[0]);
    for(int i(1);i<N;i++){
        v.push_back(v.back()+elements[i]);
        s.insert(elements[i]);
    }
    
    for(int i(0);i<N;i++){
        v.push_back(v.back()+elements[i]);
    }
    
    int k=2;
    while(k<N){
        int start=0;
        for(int i(start);i<2*N-k;i++){
            if(i==0){
                s.insert(v[i+k]);
            }
            else{
                s.insert(v[i+k]-v[i]);
            }
        }
        k++;
    }
    return s.size();
}