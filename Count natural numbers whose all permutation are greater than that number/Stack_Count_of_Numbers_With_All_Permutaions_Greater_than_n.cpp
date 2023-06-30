#include<iostream>
#include<stack>
using namespace std;

int Count(int n){
    
    if(n<=9){
        return n;
    }

    int count=0;
    stack<int> s;
    for(int i=1;i<=9;i++){
        s.push(i);
        count++;
    }

    while(!s.empty()){
        int topele=s.top();
        s.pop();
        for(int i=topele%10;i<=9;i++){
            int temp= topele*10 +i;
            if(temp<=n){
                s.push(temp);
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    int res;
    res=Count(n);
    cout<<"Count is: "<<res<<endl;
}