#include <iostream>
#define MAX 987654321
using namespace std;

int n, m, b, map[500][500], sum, time=MAX, height;

void init(){
	cin >> n >> m >> b;	
	sum+=b;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
			sum+=map[i][j];
		}
	}
	return ;
}

int calc(int h){
	int ret=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j]<h) ret+=(h-map[i][j]);
			else ret+=(map[i][j]-h)*2;
		}
	}
	
	return ret;	
}

int main(){
	init();
		
	int max_height=sum/(n*m);
	for(int i=max_height; i>=0; i--){
		int t_time=calc(i);
//		cout << t_time << ' ' << i << '\n';
		if(time>t_time){
			time=t_time;
			height=i;
		}
	}	
	
	cout << time << ' ' << height;
	
	return 0;
}





//int n, m, b, map[500][500], ans;
//int max_height, min_height=256, height_cnt[257];

//void init(){
//	cin >> n >> m >> b;
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			cin >> map[i][j];
//			
//			height_cnt[map[i][j]]++;			
//	 		if(max_height<map[i][j]) max_height=map[i][j];
//	 		if(min_height>map[i][j]) min_height=map[i][j];
//		}
//	}
//	return ;
//}

//int main(){
//	init();
//	
//	if(max_height==min_height){
//		cout << 0 << ' ' << min_height;
//		return 0;
//	}
//	
//	while(max_height-min_height>1){
//		if(b>=height_cnt[min_height]){
//			b-=height_cnt[min_height];
//			ans+=height_cnt[min_height];				
//			height_cnt[min_height+1]+=height_cnt[min_height];			
//			height_cnt[min_height++]=0;
//			
//			continue;
//		}
//		height_cnt[min_height++]-=b;	
//		height_cnt[min_height]+=b;			
//		ans+=b;
//		b=0;
//		break;
//	}
//		
//	while(max_height-min_height>1){
//		height_cnt[max_height]--;
//		height_cnt[max_height-1]++;
//		if(height_cnt[max_height]==0) max_height--;
//		height_cnt[min_height]--;
//		height_cnt[min_height+1]++;
//		if(height_cnt[min_height]==0) min_height++;			
//		
//		ans+=3;
//	}	
//	
//// b가 남아있다면
//	if(b>=height_cnt[min_height]){
//		if(ans+height_cnt[min_height]>ans+height_cnt[max_height]*2) cout << ans+height_cnt[max_height]*2 << ' ' << min_height;
//		else cout << ans+height_cnt[min_height] << ' ' << max_height;
//	}	
//	else{
//		ans+=height_cnt[max_height]*2;				
//		cout << ans << ' ' << min_height;
//	}	
//
//	return 0;
//}









