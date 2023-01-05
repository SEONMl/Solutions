#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int x,y;
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    string day[7]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    cin>>x>>y;
    int during=y;
    for(int i(0);i<x-1;i++){
        during+=month[i];
    }
    cout<<day[during%7];
}