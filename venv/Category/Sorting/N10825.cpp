#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
struct Student{
    string name;
    int kor, eng, math;
};
bool compare(Student a, Student b) {
    if (a.kor == b.kor && a.eng == b.eng && a.math == b.math) return a.name < b.name;
    if (a.kor == b.kor && a.eng == b.eng) return a.math > b.math;
    if (a.kor == b.kor) return a.eng < b.eng;
    return a.kor > b.kor;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    vector<Student> student(N);

    for(int i(0);i<N;i++){
        cin>>student[i].name>>student[i].kor>>student[i].eng>>student[i].math;
    }

    sort(student.begin(),student.end(),compare);
    for(int i(0);i<N;i++){
        cout<<student[i].name<<'\n';
    }
}
