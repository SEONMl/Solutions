#include <string>
#include <vector>
#define INF 10007

using namespace std;
int a[100'000], b[100'000];
int solution(int n, vector<int> tops) {
    a[0]=(tops[0])? 3:2;
    b[0]=1;
    for(int i=1;i<n;i++){
        int t= (tops[i])? 3: 2;
        
        a[i]=a[i-1]*t + b[i-1]*(t-1);
        b[i]=a[i-1]+b[i-1];
        
        a[i]%=INF; b[i]%=INF;
    }
    return (a[n-1]+b[n-1])%INF;
}