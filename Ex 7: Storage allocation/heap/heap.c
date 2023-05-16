#include<iostream>
using namespace std;
struct Node{
 int data;
 struct Node*next;
 };
 struct Node*top=NULL;
  int ch,val;
void push(int val){
struct Node*newnode=(struct Node*)malloc(sizeof(struct Node));
newnode->data=val;
newnode->next=top;
top=newnode;
}
void pop(){
   struct Node*ptr;
if(top==NULL){
    cout<<"Underflow";
}
else{
    cout<<"The poped elements are"<<top->data;
    top=top->next;
}
}
void display(){
struct Node*ptr;
 if(top==NULL){
    cout<<"Underflow";
}
else{
        ptr=top;
    cout<<"The elements are:";
    while(ptr!=NULL){
cout<<ptr->data<<" ";
ptr=ptr->next;
}
}
}


int main(){
do{

    cout<<"1.Push\n2.Pop\n3.display\n4.Exit\n";
    cout<<"Enter the choices:";
    cin>>ch;
    switch(ch){
    case 1:{
     cout<<"Enter the element to be pushed:";
     cin>>val;
     push(val);
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
