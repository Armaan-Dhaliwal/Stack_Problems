//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack <int>s;
        for(int i=0;i<S.length();i++){
            if(S[i]=='*' || S[i]=='+' || S[i]=='-' || S[i]=='/'){
                int num2=s.top();
                s.pop();
                int num1=s.top();
                s.pop();
                int res;
                if(S[i]=='*'){
                    res=num1*num2;
                }
                else if(S[i]=='+'){
                    res=num1+num2;
                }
                else if(S[i]=='-'){
                    res=num1-num2;
                }
                else if(S[i]=='/'){
                    res=num1/num2;
                }
                // cout<<"num1 is "<<num1<<endl;
                // cout<<"num2 is "<<num2<<endl;
                // cout<<"Result is: "<<res<<endl;
                s.push(res);
            }
            else{
                s.push(S[i]-48);
            }
            //  cout<<"S[i] is: "<<S[i]<<endl;
            // cout<<"stack top is : "<<s.top()<<endl;
        }
        
        return s.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends