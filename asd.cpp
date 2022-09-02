#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int alp, cop, alp_max, cop_max, problems_size, alp_dif, cop_dif;
vector<vector<int>> problems;
vector<vector<float> > arr;
bool able[100];

bool compare(vector<int> a, vector<int> b){
	return a[0]>b[0];
}

void init(){
    problems_size=problems.size();
    for(int i=0; i<problems_size; i++){
        if(alp_max<problems[i][0]) alp_max=problems[i][0];
        if(cop_max<problems[i][1]) cop_max=problems[i][1];
    }

    return ;
}

void check(){
    for(int i=0; i<problems_size; i++){
        if(alp>=problems[i][0] && cop>=problems[i][1]) able[i]=true;
    }
}

bool allCheck(){
    for(int i=0; i<problems_size; i++){
        if(able[i]) continue;
        return false;
    }
    return true;
}

void update(){
    alp_dif=alp_max-alp;    cop_dif=cop_max-cop;
    if(alp_dif<0) alp_dif=0;
    if(cop_dif<0) cop_dif=0;
    
    for(int i=0; i<problems_size; i++){        
		if(alp_dif<problems[i][2]) problems[i][2]=alp_dif;  
        if(cop_dif<problems[i][3]) problems[i][3]=cop_dif;  

        float val=(problems[i][2]+problems[i][3])/problems[i][4];
        arr.push_back({val, (float)i});
    }
    sort(arr.begin(), arr.end(), compare);

    return ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int alp_, cop_, n;
	vector<vector<int>> problems_(4, vector<int>(5, 0));
	
	cin >> alp_ >> cop_ ;
	cin>> n;
	for(int i=0; i<n; i++){
		int a[5];
		for(int j=0; j<5; j++){
			cin >> problems_[i][j];
		}		
	}

    alp=alp_;
    cop=cop_;
    problems.assign(problems_.begin(), problems_.end());
    int answer = 0;

	init();
    while(!allCheck()){
		check();

        update();
        for()
        int pro_idx=int(arr[0][1]);
		
		if(!able[pro_idx]) continue;
        alp+=problems[pro_idx][2];
        cop+=problems[pro_idx][3];
        answer+=problems[pro_idx][4];
    }
    
    cout << answer;
    
    return 0;
}



