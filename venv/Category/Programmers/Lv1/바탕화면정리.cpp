#include <string>
#include <vector>
#include<algorithm>
#define MAX 9999999
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int minX=MAX,minY=MAX,maxX=-MAX,maxY=-MAX;
    for(int i(0);i<wallpaper.size();i++){
        for(int j(0);j<wallpaper[0].length();j++){
            if(wallpaper[i][j]=='#'){
                minX=min(minX,i);
                minY=min(minY,j);
                maxX=max(maxX,i);
                maxY=max(maxY,j);
            }
        }
    }
    return {minX, minY, maxX+1, maxY+1};
}