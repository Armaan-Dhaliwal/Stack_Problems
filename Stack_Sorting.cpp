#include<iostream>
#include<stack>
using namespace std;

void Sort(stack<int> &s){
    if(s.size()==1){
        return;
    }

    int temp=s.top();
    s.pop();
    Sort(s);
    stack<int> aux;
    while(!s.empty() && s.top()>=temp){
        aux.push(s.top());
        s.pop();
    }
    s.push(temp);
    while(!aux.empty()){
        s.push(aux.top());
        aux.pop();
    }
    
}

int main(){
    stack<int> s;
    s.push(-3);
    s.push(14);
    s.push(18);
    s.push(-5);
    s.push(30);
    cout<<"Initially: "<<endl;
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    s.push(-3);
    s.push(14);
    s.push(18);
    s.push(-5);
    s.push(30);
    Sort(s);
    cout<<"After Sorting: "<<endl;
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}