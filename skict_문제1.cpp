#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int coins[6]={1, 5, 10, 50, 100, 500};
vector<pair<double, int> > rates;

int solution(int money, vector<int> costs) {
    int answer = 0;
// 일단 가장 가성비가 좋은 순서대로 그리디 적용
    for(int i=0; i<6; i++){
        rates.push_back({(double)costs[i]/(double)coins[i], i});
    }
    sort(rates.begin(), rates.end());

    int idx=0;
    while(money>0){
        answer+=money/coins[rates[idx].second]*costs[rates[idx].second];
        money%=coins[rates[idx++].second];
    }

    return answer;
}
