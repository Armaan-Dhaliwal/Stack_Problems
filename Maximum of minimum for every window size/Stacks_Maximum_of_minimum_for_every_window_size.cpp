
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Solution
{
    public:
    
    vector<int> Right_Smaller(int arr[],int n){
        vector<int> res(n+1);
        res[n]=-1;
        stack<int> s;
        s.push(-1);
        s.push(n);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.top()==-1){
                res[i]=n;
            }
            else{
                res[i]=s.top();
            }
            s.push(i);
        }
        return res;
    }
    
    vector<int> Left_Smaller(int arr[],int n){
        vector<int> res(n+1);
        res[0]=-1;
        stack<int> s;
        s.push(-1);
        s.push(0);
        for(int i=1;i<n+1;i++){
            while(s.top()!=-1 && arr[s.top()]>=arr[i]){
                s.pop();
            }
            res[i]=s.top();
            s.push(i);
        }
        return res;
    }
    
    //Function to find maximum of minimums of every window size.  
    vector <int> maxOfMin(int arr[], int n)
    {
        vector<int> left=Left_Smaller(arr,n);
        vector<int> right =Right_Smaller(arr,n);
        // int size=left.size();
        // for(int i=0;i<size;i++){
        //     cout<<left[i]<<" "; 
        // }
        //cout<<endl;
        vector<int> res(n,0);
        vector<int> length(n);
        for(int i=0;i<n;i++){
            if(left[i]!=-1){
                length[i]=right[i]-left[i]-1;
            }
            else{
                length[i]=right[i];
            }
        }
        // int size=length.size();
        // for(int i=0;i<size;i++){
        //     cout<<length[i]<<" "; 
        // }
        // cout<<endl;
        
        for(int i=0;i<n;i++){
            if(res[length[i]-1]<arr[i]){
                res[length[i]-1]=arr[i];
            }
        }
        for(int i=n-2;i>=0;i--){
            //if(res[i]==0){
            if(res[i]<res[i+1])
                res[i]=res[i+1];
           // }
        }
    
       return res; 
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends