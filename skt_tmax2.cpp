#include <string>
#include <vector>

using namespace std;
int a, b;

bool isVIP(int period, int payment){
    if(period>=24 && payment>=900000) return true;
    if(period>=60 && payment>=600000) return true;
    return false;
}

bool willVIP(int period, int payment){
    if(period>=24 && payment>=900000) return true;
    if(period>=60 && payment>=600000) return true;
    return false;
}

vector<int> solution(vector<int> periods, vector<vector<int>> payments, vector<int> estimates) {
    vector<int> answer;
    int size=periods.size();
    for(int i=0; i<size; i++){
        int period=periods[i], payment=0, estimate=estimates[i];
        for(int j=0; j<12; j++) payment+=payments[i][j];

        if(isVIP(period, payment) && willVIP(period+1, payment-payments[i][0]+estimate)==false) a++;
        else if(isVIP(period, payment)==false && willVIP(period+1, payment-payments[i][0]+estimate)) b++;
    }    

    answer.push_back(b);
    answer.push_back(a);
    return answer;
}
