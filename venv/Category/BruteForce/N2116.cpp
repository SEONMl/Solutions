// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// int N,t;
// vector<int> dice[10001];
// void rotate(int idx,int k){
//     int a=dice[idx][0],b=dice[idx][1],c=dice[idx][2],d=dice[idx][3],e=dice[idx][4],f=dice[idx][5];
//     switch (k){
//     case 0:
//         dice[idx]={a,b,c,d,e,f};
//         break;
//     case 1:
//         dice[idx]={b,e,f,c,a,d};
//         break;
//     case 2:
//         dice[idx]={c,b,f,d,a,e};
//         break;
//     case 3:
//         dice[idx]={d,c,f,e,a,b};
//         break;
//     case 4:
//         dice[idx]={e,b,f,d,a,c};
//         break;
//     case 5:
//         dice[idx]={f,b,c,d,e,a};
//         break;
//     }
// }
// int main(){
//     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//     cin>>N;
//     for(int i=0;i<N;i++){
//         for(int j=0;j<6;j++){
//             cin>>t;
//             dice[i].push_back(t);
//         }
//     }
//     int res=0;
//     for(int i=0;i<6;i++){
//         rotate(0,i);
//         int tmp=max(max(dice[0][1],dice[0][2]),max(dice[0][3],dice[0][4]));
//         for(int j=1;j<N;j++){
//             for(int k=0;k<6;k++){
//                 if(dice[j][k]==dice[j-1][5]){
//                     rotate(j,k);
//                     tmp+=max(max(dice[j][1],dice[j][2]),max(dice[j][3],dice[j][4]));
//                     break;
//                 }
//             }
//         }
//         res=max(res,tmp);
//     }
//     cout<<res;
//     return 0;
// }
// 흐음...
#include <iostream>
#include <algorithm>

using namespace std;

int N, d[10000][6], ans = 0;


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> d[i][0] >> d[i][1] >> d[i][2] >> d[i][4] >> d[i][5] >> d[i][3];
	}

	for (int i = 0; i < 6; i++){ // first bottom side
		int bot = i, cnt = 0, res = 0;

		while (cnt < N){
			// add maximum value except bottom side & upper side
			int val = 0;
			for (int j = 0; j < 6; j++){
				if ((j != bot && j != (bot + 3) % 6) && val < d[cnt][j])
					val = d[cnt][j];
			}
			res += val;

			// find next dice's bottom
			if (cnt < N - 1){
				int upp = d[cnt][(bot + 3) % 6];

				for (int j = 0; j < 6; j++){
					if (upp == d[cnt + 1][j]){
						bot = j;
						break;
					}
				}
			}
			cnt++;
		}

		ans = max(ans, res);
	}

	cout << ans;

	return 0;
}