#include<iostream>
#include<queue>
#include<algorithm>
#define INF 20171109
#define fse(A,B,C) for(int i=A;i<B;i+=C) 
using namespace std;

void calculate(int middle, int tmp, priority_queue<int> &min, priority_queue<int> &max){
    if(middle<tmp){
        min.push(-tmp);
    }else{
        max.push(tmp);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int test_case, T;

	cin>>T;
    // freopen("C:\\Dev\\projects\\Solutions\\venv\\Category\\.vscode\\input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int answer=0;
        int N, middle;
        cin>>N>>middle;
        priority_queue<int> minHeap;
        priority_queue<int> maxHeap;

        fse(0,N,1){
            int x,y;
            cin>>x>>y;

            calculate(middle, x, minHeap, maxHeap);
            calculate(middle, y, minHeap, maxHeap);


            while(minHeap.size()!=maxHeap.size()){
                int tmp=middle;
                if(minHeap.size()>maxHeap.size()){
                    middle=-minHeap.top();
                    minHeap.pop();
                    maxHeap.push(tmp);
                }else{
                    middle=maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(-tmp);
                }
            }
            
            answer = (answer+middle)%INF;
        }


        cout<<"#"<<test_case<<" "<<answer<<'\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}