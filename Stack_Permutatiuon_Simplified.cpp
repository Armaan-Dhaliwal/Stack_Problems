//{ Driver Code Starts
//Initial Template for C++

#include<iostream>
#include<stack>
#include<climits>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int> s;
        int sb=0;
        for(int sa=0;sa<N;){
            s.push(A[sa]);
            while(!s.empty() && s.top()==B[sb]){
                s.pop();
                sb++;
            }
            sa++;
        }
        if(s.empty()){
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends