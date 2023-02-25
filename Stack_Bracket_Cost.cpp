#include<iostream>
using namespace std;
#include"Stack_Class_Array.cpp"

int Cost(string str){

    int count1=0;
    int count2=0;
    Stack stack(str.length());
    
    if(str.length()%2!=0){
        return -1;
    }

    int i = 0;
    while (str[i]!='\0')
    {
        if(str[i]=='{'){
            stack.push(str[i]);
        }

        if(str[i]=='}'){
            if (!stack.IsEmpty() && stack.peek()=='{')
            {
                stack.pop();
            }
            
            else{
                stack.push(str[i]);
            }     
        }
        i++;
    }

    while (!stack.IsEmpty())
    {
        if (stack.peek()=='{')
        {
            count1++;
        }

        else if(stack.peek()=='}'){
            count2++;
        }
        
        stack.pop();
    }

    int cost = (count2+1)/2 + (count1+1)/2;
    return cost;
}

int main(){
    string str;
    cout<<"Enter your string: "<<endl;
    cin>>str;

    int cost = Cost(str);
    cout<<"Cost would be: "<<cost<<endl;
}