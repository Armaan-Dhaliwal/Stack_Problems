//{ Driver Code Starts
// Initial Template for C++
#include<iostream>
#include<stack>
#include<climits>
using namespace std;
//{ Driver Code Starts
// Initial Template for C++

class Solution{
public:
    int maxLength(string S){
        stack <int>s;
        int count=0;
        int max_count=0;
        s.push(-1);
        for(int i=0;i<S.length();i++){
            if(S[i]=='('){
                s.push(i);
            }
            
            else if(S[i]==')'){
                s.pop();
                if(s.empty()){
                    s.push(i);
                }
                else {
                    count=i-s.top();
                    if(count>max_count){
                        max_count=count;
                    }
                }
            }
        }
    
        return max_count;
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends