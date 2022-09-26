#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isValid(string s){
    int size=s.size();
    stack<char> stk;
    for(int i=0; i<size; i++){
        if(s[i]=='(') stk.push('(');
        else{
            if(stk.empty()) return false;
            stk.pop();
        }
    }
    
    return true;
}

string reculsive(string s){
    if(s=="") return s;
    
    int size=s.size();
    int sum=0, i=0;
    string u="";
    do{
        if(s[i]=='(') sum+=1;
        else sum-=1;
        u+=s[i];
        i++;
    }while(sum!=0);
    
    string add="";
    if(isValid(u)){
        if(i!=size) add=reculsive(s.substr(i));
        return u+add;
    }
    else{
        if(i!=size) add="("+reculsive(s.substr(i))+")";
        else add="()";
            
        int u_size=u.size();
        u=u.substr(1, u_size-2);
        u_size-=2;
        for(int i=0; i<u_size; i++){
            if(u[i]=='(') u[i]=')';
            else u[i]='(';
        }
        
        return add+u;
    }
}

string solution(string p) {
    return reculsive(p);
}
