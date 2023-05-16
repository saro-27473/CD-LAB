#include<iostream>
using namespace std;
int stack[100],ch,x,n,i,top=-1;
void push(int x){
if(top>=n-1)
    cout<<"Overflow";
else
{
    stack[++top]=x;
}
}
void pop(){
if(top==-1)
    cout<<"Underflow";
else{
    cout<<"The poped elements are "<<stack[top];
    top--;
}
}
void display(){
 if(top>=0){
    cout<<"The elements are";
    for(i=top;i>=0;i--)
        cout<<stack[i];
 }
 else
    cout<<"Empty";
}
int main(){
cout<<"Enter the size of stack:";
cin>>n;
do{
    cout<<"1.Push\n2.Pop\n3.display\n4.Exit\n";
    cout<<"Enter the choices:";
    cin>>ch;
    switch(ch){
    case 1:{
     cout<<"Enter the element to be pushed:";
     cin>>x;
     push(x);
     break;
     }
    case 2:{
     pop();
     break;
    }
     case 3:{
     display();
     break;
    }
     case 4:{
         cout<<"Exit";
     break;
    }
    default:{
    cout<<"invalid choice";
    }
}
}while(ch!=4);
return 0;
}
