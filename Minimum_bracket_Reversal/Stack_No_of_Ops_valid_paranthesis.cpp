#include<iostream>
#include<stack>
using namespace std;

int findMinimumCost(string str) {
  string temp="";
  stack<char> s;
  stack<char> temp_stack;
  int cost=0;
  if(str.length()%2!=0){
    return -1;
  }

  else{
    for(int i=0;i<str.length();i++){
      if (!s.empty() &&  str[i] == '}' && s.top() == '{'){
        s.pop();
      }
      else{
        s.push(str[i]);
      }
    }
  }
  
  while(!s.empty()){
    temp+=s.top();
    temp_stack.push(s.top());
    s.pop();
  }
    // cout<<temp<<endl;
    // cout<<temp.length()<<endl; 
  for(int i=0;i<(temp.length()+1)/2;i++){
    char temp_char=temp[i];
    temp[i]=temp[temp.length()-i-1];
    temp[temp.length()-i-1]=temp_char;
  }
  
  int p=0;
  int q=0;
  for(int i=0;i<temp.length();i++){
    if(temp[i]=='}'){
      p++;
    }
    if(temp[i]=='{'){
      q++;
    }
  }

  //cout<<"p is: "<<p<<" q is "<<q<<endl;
  //cout<<temp<<endl;
  if(p%2==0){
    cost+=p/2;
  }
  else{
    cost+=p/2 +2;
  }

  cost+=q/2;

  return cost;
}


int main(){
  string str="{{{}}}}{";
  cout<<findMinimumCost(str)<<endl;
}