#include <string>
#include <vector>
#include <iostream>
using namespace std;

int d[251][251];

int dp(int x, int y){
    if(d[x][y-1]!=0 && d[x-1][y]!=0) return d[x][y]=(d[x-1][y]+d[x][y-1])%10000019;
    else return d[x][y]=(dp(x-1, y)+dp(x, y-1))%10000019;
}

int solution(int width, int height, vector<vector<int>> diagonals) {
    int answer = 0;

    for(int i=1; i<=250; i++){
        d[i][1]=i+1;
        d[1][i]=i+1;
        d[0][i]=1;
        d[i][0]=1;
    }
    dp(250, 250);

    int len=diagonals.size();
    for(int i=0; i<len; i++){
        int x=diagonals[i][0], y=diagonals[i][1];
        long long t1=d[x][y-1]*d[width-x+1][height-y], t2=d[x-1][y]*d[width-x][height-y+1];
        answer=(answer+t1%10000019+t2%10000019)%10000019;
    }

    return answer;
}
