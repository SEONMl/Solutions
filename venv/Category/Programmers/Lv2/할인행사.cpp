#include <string>
#include <vector>
#include<map>
using namespace std;
map<string, int> shoppingList;
map<string, int> discountItem;
bool isPossible(){
    for(auto item:shoppingList){
        if(discountItem.find(item.first)==discountItem.end()){
            return false;
        }
        if(discountItem[item.first]<item.second){
            return false;
        }
    }
    return true;
}
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for(int i(0);i<want.size();i++){
        shoppingList[want[i]]=number[i];
    }
    
    for(int i(0);i<discount.size();i++){
        string item=discount[i];
        if(discountItem.find(item)==discountItem.end()){
            discountItem[item]=1;
        }
        else discountItem[item]++;
        
        if(i>=10){
            string prevItem=discount[i-10];
            discountItem[prevItem]--;
        }
        if(isPossible()) answer++;
    }
    return answer;
}