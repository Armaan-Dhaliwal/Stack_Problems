#include<iostream>
#include<stack>
#include<climits>
using namespace std;
bool duplicateParanthesis(string &expr)
{
    stack<char> s;
    bool res=false;
    //cout<<int('b')<<endl;
    for(int i=0;i<expr.length();i++){
        if(expr[i]=='(' || expr[i]=='+' ||expr[i]=='-' || expr[i]=='/' || expr[i]=='*' || (expr[i]>=97 && expr[i]<=122)){
            s.push(expr[i]);
        }
        else if(expr[i]==')' ){
            if(s.top()=='('){
                res=true;
                break;
            }
            else{
                while(s.top()!='(')
                s.pop();
            }
            s.pop();
        }
    }
    return res;
}

int main(){
    string s="((a+(b))+(c+d))";
    if(duplicateParanthesis(s)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

}