//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int n, ans;
//char map[50][51];
//
//void check(){
////  행 계산 
//	for(int i=0; i<n; i++){
//		int cnt=1;
//		for(int j=0; j<n-1; j++){
//			if(map[i][j]!=map[i][j+1]){
//				cnt=1;
//				continue;
//			}
//			
//			cnt++;
//			if(ans<cnt) ans=cnt;
//		}
//		
//	}	
//// 열 계산
//	for(int i=0; i<n; i++){
//		int cnt=1;
//		for(int j=0; j<n-1; j++){
//			if(map[j][i]!=map[j+1][i]){
//				cnt=1;
//				continue;
//			}
//			
//			cnt++;
//			if(ans<cnt) ans=cnt;
//		}		
//	}
//	
//	return ;
//}
//
//int main(){
//	cin >> n;
//	for(int i=0; i<n; i++) cin >> map[i];
//// 행바꾸기 
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n-1; j++){
//			swap(map[i][j], map[i][j+1]);
//			check();			
//			swap(map[i][j], map[i][j+1]);
//		}		
//	}
//// 열바꾸기 
//	for(int i=0; i<n; i++){
//		for(int j=0; j<n-1; j++){
//			swap(map[j][i], map[j+1][i]);
//			check();			
//			swap(map[j][i], map[j+1][i]);
//		}
//	}
//	
//	cout << ans;
//
//	return 0;
//}
////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>

using namespace std;

int N;
char board[50][50];

int cntRow(int y) {
  int ret = 1;
  for (int i = 0; i < N; i++) {
    int j = i + 1, cnt = 1;
    while (j < N && board[y][i] == board[y][j]) {
      j++;
      cnt++;
    }
    i = j - 1;
    ret = max(ret, cnt);
  }
  return ret;
}

int cntCol(int x) {
  int ret = 1;
  for (int i = 0; i < N; i++) {
    int j = i + 1, cnt = 1;
    while (j < N && board[i][x] == board[j][x]) {
      j++;
      cnt++;
    }
    i = j - 1;
    ret = max(ret, cnt);
  }
  return ret;
}

int countCandy(int y, int x, int dir) {
  int ret = 0;
  // 가로
  ret = max(ret, cntRow(y));
  // 세로
  ret = max(ret, cntCol(x));
  // 교체 라인
  if (dir == 0) {
    ret = max(ret, cntCol(x + 1));
  } else {
    ret = max(ret, cntRow(y + 1));
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  int ans = 0;
  // 초기 최대 길이 구하기
  for (int i = 0; i < N; i++) {
    ans = max(ans, cntRow(i));
    ans = max(ans, cntCol(i));
  }
  if (ans == N) {
    cout << N;
    return 0;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (j + 1 < N && board[i][j] != board[i][j + 1]) {
        swap(board[i][j], board[i][j + 1]);
        ans = max(ans, countCandy(i, j, 0));
        swap(board[i][j], board[i][j + 1]);
      }
      if (i + 1 < N && board[i][j] != board[i + 1][j]) {
        swap(board[i][j], board[i + 1][j]);
        ans = max(ans, countCandy(i, j, 1));
        swap(board[i][j], board[i + 1][j]);
      }
    }
  }

  cout << ans;

  return 0;
}
