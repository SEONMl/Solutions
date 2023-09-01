#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<cmath>
#define MAX 100'000
#define INF 1'000'000'000
#define fse(A,B,C) for(int i=A;i<B;i+=C)
using namespace std;
class Point{
    public:
    int x; int y;
    Point(int x,int y){
        this->x=x; this->y=y;
    }
    bool operator < (const Point &v) const {
        if(y == v.y){
            return x < v.x;
        }else{
            return y < v.y;
        }
    }
};
int distance(Point a, Point b){
    int x=a.x-b.x;
    int y=a.y-b.y;
    return x*x + y*y;
}
bool comp(const Point &a, const Point &b){
    return a.x < b.x;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    vector<Point> dots;
    fse(0,N,1){
        int a,b;
        cin>>a>>b;
        dots.push_back(Point(a,b));
    }

    sort(dots.begin(), dots.end(), comp); // x축 정렬

    set<Point> candi={dots[0], dots[1]};
    int min_d=distance(dots[0], dots[1]);
    int index=0;
    for(int i(2);i<N;i++){
        if(min_d==0) break;

        Point now = dots[i];
        while(index < i){ 
            auto target=dots[index];
            int tmp = now.x - target.x;
            if(tmp*tmp > min_d){
                candi.erase(target); // x-d 미만인 애들 삭제
                index++;
            }else{
                break;
            }
        }

        int d = (int)sqrt((double)min_d)+1;
        auto lower_y = candi.lower_bound(Point(-MAX, now.y-d));
        auto upper_y = candi.upper_bound(Point(MAX, now.y+d));
        for(auto it=lower_y; it!=upper_y; it++){
            int d=distance(now, *it);
            min_d=min(min_d, d);
        }
        candi.insert(now);
    }
    cout<<min_d;
}