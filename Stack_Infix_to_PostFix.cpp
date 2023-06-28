#include<stack>
#include<iostream>
#include<queue>
using namespace std;
//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
      
    bool preceds(char a, char b){

        if(a==b){
            return false;
        }
        
        else if(a=='^'){
            return true;
        }
        
        else if(a=='/'){
            if(b=='^'){
                return false;
            }
            else{
               return true;  
            }
        }
        
        else if(a=='*'){
            if( b=='^'){
                return false;
            }
            else{
                return true;
            }
        }
        
        else if(a=='+'){
            return false;
        }
        
        else if(a=='-'){
             return false;
        }
        
    }
    
    string infixToPostfix(string s) {
        string output="";
        stack<char> S;
        for(int i=0;i<s.length();i++){
            if((S.empty() || S.top()=='(') && (s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*' || s[i]=='^') ){
                S.push(s[i]);
            }
            
            else if(s[i]=='('){
                S.push(s[i]);
            }
            
            else if(s[i]!='+' && s[i]!='-' && s[i]!='/' && s[i]!='*' && s[i]!='^' && s[i]!=')' && s[i]!='('){
                output+=s[i];
            }
            
            else if(!S.empty() && s[i]==')'){
                while(S.top()!='('){
                    output+=S.top();
                    S.pop();
                }
                S.pop();
            }
            
            else if( preceds(s[i],S.top())){
                S.push(s[i]);
            }
            
            else if(!S.empty() && !(preceds(s[i],S.top()))){
                while(!S.empty() && !preceds(s[i],S.top()) && S.top()!='('){
                    output+=S.top();
                    S.pop();
                }
                S.push(s[i]);
            }
        }
        
        while(!S.empty()){
            output+=S.top();
            S.pop();
        }
    return output;
        
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends