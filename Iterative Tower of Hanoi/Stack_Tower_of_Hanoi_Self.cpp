#include<iostream>
#include<stack>
#include<vector>
#include<math.h>
using namespace std;

vector<stack<int>> stacks(3);
char poles[]={'S','A','D'};

void move(int a,int b){
    if(stacks[b].empty() || (!stacks[a].empty() && stacks[a].top()<stacks[b].top())){
        cout<<"move disc from: "<<poles[a]<<" to "<<poles[b]<<endl;
        stacks[b].push(stacks[a].top());
        stacks[a].pop();
    }
    else{
        move(b,a);
    }
}

int main(){
    
    int n;
    cout<<"Enter number of discs: "<<endl;
    cin>>n;

    int src=0,aux=1,des=2;
    int moves = pow(2,n) - 1;
    if(moves%2==0){
        swap(aux,des);
    }

    for(int i=n;i>0;i--){
        stacks[src].push(i);
    }
    for(int i=1;i<=moves;i++){
        if(i%3==1){
            move(src,des);
        }
        else if(i%3==2){
            move(src,aux);
        }
        else{
            move(aux,des);
        }
    }
    while(!stacks[des].empty()){
        cout<<stacks[des].top()<<endl;
        stacks[des].pop();
    }
}
