//{ Driver Code Starts
//Initial Template for C++
#include<iostream>
#include<stack>
#include<climits>
#include<vector>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
public: 
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int>s;
        int sa=0;
        int sb=0;
        int res=0;
        while(sa<N){
            if(A[sa]!=B[sb]){
                while(A[sa]!=B[sb] && sa<N){
                    s.push(A[sa]);
                    sa++;
                }
            }
            sa++;
            sb++;
            while(!s.empty() && s.top()==B[sb] ){
                s.pop();
                sb++;
            }

        }
        if(s.empty()){
            res=1;
        }
        return res;
        
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