#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> id_list, int k) {
    int day=id_list.size();
    vector<set<string>> idOfDay;

    for(int i(0);i<day;i++){
        set<string> newSet;
        idOfDay.push_back(newSet);

        int current = id_list[i].find(' ');
        int previous =0;
        while(current!=string::npos){
            string substring=id_list[i].substr(previous,current-previous);
            cout<<substring<<" ";
            idOfDay[i].insert(substring);
            previous = current+1;
            current= id_list[i].find(' ', previous);
        }
    }

    map<string, int> coupon;
    int totalCoupon=0;
    for(int i(0);i<day;i++){
        for(auto id:idOfDay[i]){
            if(coupon.find(id)!=coupon.end() && coupon[id]<k){
                coupon[id]=coupon[id]+1;
                totalCoupon++;
            }else if(coupon.find(id)==coupon.end()){
                coupon.insert({id,1});
                totalCoupon++;
            }
        }
    }

    return totalCoupon;
}
int main(){
    vector<string> v;
    v.push_back("A B C D");
    v.push_back("A D");
    v.push_back("A B D");
    v.push_back("B D");
    cout<<solution(v, 2);
}

// string split 하는 법
// c++ map, set 사용법