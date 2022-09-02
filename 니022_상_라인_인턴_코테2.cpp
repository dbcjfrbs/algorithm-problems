#include <string>
#include <vector>
using namespace std;

int d[2000], Max=2000000001; // 합이 n-1, 

int solution(int n, vector<int> times) {
    int times_size=times.size();
    for(int i=1; i<=n-1; i++) d[i]=Max; 
  
    d[1]=times[0]; // d[1]은 1개 더 만드는데 걸리는 최소시간 
    for(int i=2; i<n; i++){
        for(int j=1; j<i; j++){
            if(i-j-1>times_size-1 || j+1<i-j) continue;
            if(d[i]>d[j]+times[i-j-1]) d[i]=d[j]+times[i-j-1];           
        }
    }

    return d[n-1];
}
