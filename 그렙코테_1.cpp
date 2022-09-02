#include <string> 
#include <vector>
#include <iostream>
using namespace std;

string solution(int n, string text, int second) {
    string answer = "";
    int t_size=text.size();
    int cutted_cnt=(second-1)%n+1; // 오른쪽부터 나타나는text 개수

    if(n==1){
        int cutted_one=(second-1)%t_size+1;
        if(second==0 && t_size==1) cutted_one=0;
        cout << cutted_one;
        text="_"+text;
        answer+=text[cutted_one];
        return answer;
    }

    string cutted_text=text.substr(0, cutted_cnt);
    int j=0;
    for(int i=0; i<n; i++){
        if(n-1-cutted_cnt+1<=i){
            if(cutted_text[j]==' ') answer+="_";
            else answer+=cutted_text[j];
            j++;
        }
        else answer+='_';
    }

    return answer;
}
