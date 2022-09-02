#include <iostream>
#define MAX 50
using namespace std;
int w, h;
int map[MAX][MAX], visit[MAX][MAX];
int dx[8]={1, 1, 1, 0, -1, -1, -1, 0}, dy[8]={1, 0, -1, -1, -1, 0, 1, 1};

void dfs(int x, int y){
	visit[x][y]=1;
	
	for(int i=0; i<8; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(nx>=0 && nx<h && ny>=0 && ny<w && map[nx][ny]==1 && !visit[nx][ny]){
			dfs(nx, ny);
	}   
		}
}

int main(){
	while(1){
		cin >> w >> h;
		if(w==0 && h==0) break;

		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				cin >> map[i][j];
				visit[i][j]=0;	
			}
		}
		
		int cnt=0;
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if(map[i][j]==1 && !visit[i][j]){
					dfs(i, j);
					cnt++;	
				}
			}
		}	
		
		cout << cnt << endl;
	}
	
	return 0;
} 



////////////////////////////////////////////////////////

// 메모리 최적화
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int** matrix;
int** visited;
int dir_x[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dir_y[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };
int ctr = 0;

void DFS(int row, int col, int height, int width) {
	visited[row][col] = 1;
	
	for (int i = 0; i < 8; i++) {
		int newR = row + dir_x[i];
		int newC = col + dir_y[i];
		if (newR >= 0 && newR < height && newC >= 0 && newC < width && !visited[newR][newC] && matrix[newR][newC]) {
			
			DFS(newR, newC, height, width);
			
		}
	}

}




int main() {
	
	int w, h;
	int num1, num2;

	while (1) {
		scanf("%d %d", &w, &h);
		num1 = w;
		num2 = h;
		if (num1 == 0 && num2 == 0) break;

		matrix = (int**)malloc(sizeof(int*) * h);
		visited = (int**)malloc(sizeof(int*) * h);
		for (int i = 0; i < h; i++) {
			matrix[i] = (int*)malloc(sizeof(int) * w);
			visited[i] = (int*)malloc(sizeof(int) * w);
			for (int j = 0; j < w; j++) {
				scanf("%d", &matrix[i][j]);
				visited[i][j] = 0;
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (matrix[i][j] == 1 && !visited[i][j]) {
					DFS(i, j, h, w);
					ctr++;
				}
			}
		}
		printf("%d\n", ctr);
		ctr = 0;


	}
	
	for (int i = 0; i < h; i++) {
		free(matrix[i]);
		free(visited[i]);
	}

	free(matrix);
	free(visited);
	
	
	
	return 0;

}


 
