//{ Driver Code Starts
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> vec(n);
        vec[n-1]=-1;
        stack<int> s;
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            while( !s.empty() && arr[s.top()]<=arr[i]){
                s.pop();
            }
            if(!s.empty()){
                vec[i]=arr[s.top()];
            }
            else{
                vec[i]=-1;
            }
            s.push(i);
        }
        return vec;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends