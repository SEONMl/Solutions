#include<iostream>
#include<string>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;

int solution(int storey) {
    int cnt=0;
    while(storey>0){
        int last=storey%10;
        if(last>5){
            cnt+=10-last;
            storey+=10;
        }else if(last<5){
            cnt+=last;
        }else{
            cnt+=5;
            if((storey/10)%10>=5) storey+=10;
        }
        storey/=10;
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cout<<solution(16)<<endl;
    cout<<solution(2554)<<endl;
    cout<<solution(999)<<endl;
    cout<<solution(678);
}