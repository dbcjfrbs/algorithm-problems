#include <string>
#include <vector>
using namespace std;

int map[1000][1000];

void run(int x, int y, int dir, int cnt, int length, int val){
    if(cnt==1){
        map[x][y]=val++;
        length-=2;
    }
    else if(cnt==2){
        length-=1;
    }
    else length-=2;

    if(length==0) length+=1;
    if(length<1) return ;
    
    if(dir==1){
        int i;
        for(i=1; i<=length; i++) map[x][y+i]=val++;
        run(x, y+length, (dir+1)%4, cnt+1, length, val);
    }
    else if(dir==2){
        int i;
        for(i=1; i<=length; i++) map[x+i][y]=val++;
        run(x+length, y, (dir+1)%4, cnt+1, length, val);
    }
    else if(dir==3){
        int i;
        for(i=1; i<=length; i++) map[x][y-i]=val++;
        run(x, y-length, (dir+1)%4, cnt+1, length, val);
    }
    else{
        int i;
        for(i=1; i<=length; i++) map[x-i][y]=val++;
        run(x-length, y, (dir+1)%4, cnt+1, length, val);
    }
    
    return ;
}

vector<vector<int>> solution(int n, bool clockwise) {
    vector<vector<int>> answer(n);

    run(0, 0, 1, 1, n, 1);
    run(0, n-1, 2, 1, n, 1);
    run(n-1, n-1, 3, 1, n, 1);
    run(n-1, 0, 0, 1, n, 1);

    if(!clockwise){
        for(int i=0; i<n; i++){
            for(int j=0; j<n-j; j++){
                int tmp=map[i][j];
                map[i][j]=map[i][n-1-j];
                map[i][n-1-j]=tmp;
            }
        }
    }    

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            answer[i].push_back(map[i][j]);
        }
    }

    return answer;
}
