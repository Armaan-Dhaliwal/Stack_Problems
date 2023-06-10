#include<iostream>
#include<stack>
#include<vector>
using namespace std;
#define MAX 1000

class Solution{
  public:
    
vector<int> nextSmallerElement(int *arr, int m)
    {
        int size= m;  
        int temp=0;
        vector<int> result(size);
        stack<int> s;
        s.push(-1);
        
    for(int i=size-1;i>=0;i--){
        temp = arr[i];

        if(s.top()!=-1){
            while (s.top()!=-1 && arr[s.top()] >= temp ) {
                s.pop();
            }
        }
        result[i]=s.top();
        if(result[i]==-1){
            result[i]=size;
        }
        s.push(i);
    }
    return result;
    }

vector<int> prevSmallerElement(int *arr, int m)
    {
        int size= m;  
        int temp=0;
        vector<int> result(size);
        stack<int> s;
        s.push(-1);
        
    for(int i=0;i<size;i++){
        temp = arr[i];
        if(s.top()!=-1){
            while (s.top()!=-1 && arr[s.top()] >= temp ) {
                s.pop();
            }
        }
        
        result[i]=s.top();
        s.push(i);
        
    }
    return result;
    }

    int largestRectangleArea(int *heights,int n,int m) {
        int size = m;
        vector<int> areas(size);
        vector<int> prev;
        vector<int> next;
        prev = prevSmallerElement(heights,m);
        next = nextSmallerElement(heights,m);
        int temp;

        for(int i=0;i<size;i++){
            temp = heights[i];
            int area = temp*(next[i]-prev[i]-1);
            areas[i] = area;
        } 

        int max=-99;
        for(int i=0;i<size;i++){
           if(areas[i]>max){
               max = areas[i];
           }
        } 
        return max;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        vector<int> res;
        int temp = largestRectangleArea(M[0],n,m);
        res.push_back(temp);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
               if(M[i][j]!=0){
                    M[i][j]+=M[i-1][j];
                   }
               }
            temp=largestRectangleArea(M[i],n,m);
            res.push_back(temp);
        }
    
    int maxx=-99;
    for(int i=0;i<n;i++){
        if(res[i]>maxx){
            maxx = res[i];
        }
    }

    return maxx;
        
    }
};


int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
