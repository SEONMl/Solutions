// KMP 알고리즘 O(N+M)
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10'000
#define endl '\n'
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;

vector<int> getPi(string str){
    int size=str.length(), cur=0;
    vector<int> pi(size, 0);

    fse(1,size,1){
        while(cur>0 && str[i]!=str[cur]){
            cur=pi[cur-1];
        }
        if(str[i]==str[cur]) pi[i]=++cur;
    }
    return pi;
}

int kmp(string str, string target){
    int ans=0;
    auto pi = getPi(target);
    int N=str.length(), M=target.length(), cur=0;

    fse(0,N,1){
        while(cur>0 && str[i]!=target[cur]){
            cur=pi[cur-1];
        }
        if(str[i]==target[cur]){
            if(cur==M-1){
                ans++;
                cur=pi[cur];
            }else{
                cur++;
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test_case, T;

	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string book, target;
        cin>>book>>target;
        cout<<"#"<<test_case<<" "<<kmp(book, target)<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}