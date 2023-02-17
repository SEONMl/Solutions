#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int returnTimeToInt(string str_time){
    return (str_time.at(0)-'0')*1000 + (str_time.at(1)-'0')*100 + (str_time.at(3)-'0')*10 + (str_time.at(4)-'0');
}
bool comp(vector<string> a, vector<string> b){
    if(a[0] < b[0]) return true;
    else if (a[0]==b[0]) {
        if (a[1]<=b[1]) return true;
        return false;
    }
    return false;
}
int endTime(string t){
    int time=returnTimeToInt(t)+10;
    if(time%100>=60) {
        time-=60;
        time+=100;
    }
    return time;
}
int solution(vector<vector<string>> book_times) {
    priority_queue<int> heap;
    
    sort(book_times.begin(), book_times.end(), comp);
    heap.push(-endTime(book_times[0][1]));

    for(int i(1);i<book_times.size();i++){
        int top = -heap.top();
        int next_start=returnTimeToInt(book_times[i][0]);
        int next_end=endTime(book_times[i][1]);

        if(top<=next_start) {
            heap.pop();
        }
        heap.push(-next_end);
    }
    return heap.size();
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout<<solution({{"15:00", "17:50"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"}});
    cout<<endl<<solution({{"09:00", "23:59"},{"00:20", "01:00"}});
    cout<<endl<<solution({{"00:00", "23:59"}});
}

/*
19번 
segmentation fault (core dumped) : 런타임중에 엉뚱한(혹은 널) 메모리를 참조했거나 조작해서 발생
어디서 틀렸는지 모르겠네 =.=
*/