#include<iostream>
#include<stack>
class SpecialStack {
    stack<int> s;
    int min;

    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        if(s.empty()){
            s.push(data);
            min=data;
        }

        if(data>min){
            s.push(data);
        }
        else{
            int val = 2*data-min;
            s.push(val);
            min=data;
        }
    }

    int pop() {
        if(s.empty()){
            return -1;
        }

        if(s.top()>min){
            int current=s.top();
            s.pop();
            return current;
        }
        
        else{
            int prev_min= min;
            int val = 2*min-s.top();
            min=val;
            s.pop();
            return prev_min;
        }
    }

    int top() {
        if(s.empty()){
            return -1;
        }
        
        if(s.top()>min){
            return s.top();
        }

        else{
            return min;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty()){
            return -1;
        }

        else
        return min;
    }  
};