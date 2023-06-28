#include<stack>
#include<iostream>
#include<queue>
using namespace std;

class Mid_Stack{
    public:
    stack<int> s;
    deque<int> deq;

    void push(int x){
        if(deq.empty()){
            deq.push_back(x);
        }

        else{
            deq.push_back(x);
            if(deq.size()-s.size()>1){
                s.push(deq.front());
                deq.pop_front();
            }
        }
    }

    int pop(){
        if(deq.empty()){
            return -1;
        }

        int temp=deq.back();
        deq.pop_back();
        if(s.size()-deq.size()==1){
            deq.push_front(s.top());
            s.pop();
        }
        return temp;
    }

    int GetMiddle(){
        if(deq.empty()){
            return -1;
        }

        return deq.front();
    }
};

int main(){
    Mid_Stack S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    cout<<"Middle is :"<<S.GetMiddle()<<endl;
    cout<<"Popped : "<<S.pop()<<endl;
    cout<<"Middle is :"<<S.GetMiddle()<<endl;
    cout<<"Popped : "<<S.pop()<<endl;
    cout<<"Middle is :"<<S.GetMiddle()<<endl;
    cout<<"Popped : "<<S.pop()<<endl;
    cout<<"Middle is :"<<S.GetMiddle()<<endl;
    cout<<"Popped : "<<S.pop()<<endl;
    cout<<"Middle is :"<<S.GetMiddle()<<endl;
    return 0;
}