#include<iostream>
#include<vector>
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
int N,T;
vector<int> light;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>N;
    fse(0,N,1) {
        int tmp;
        cin>>tmp;
        light.push_back(tmp);
    }
    cin>>T;
    while(T>0){
        int sex, num;
        cin>>sex>>num;
        if(sex==1){
            int idx=1;
            while(num*idx-1<N){
                light[num*idx-1]=!light[num*idx-1];
                idx++;
            }
        }else{
            num--;
            light[num]=!light[num];
            fse(1,N,1){
                if(num-i<0||num+i>=N|| light[num-i]!=light[num+i])break;
                light[num-i]=!light[num-i];
                light[num+i]=!light[num+i];
            }
        }
        T--;
    }
    int jul=0;
    for(int i:light){
        if(jul!=0&&jul%20==0) cout<<'\n';
        cout<<i<<" ";
        jul++;
    }
}