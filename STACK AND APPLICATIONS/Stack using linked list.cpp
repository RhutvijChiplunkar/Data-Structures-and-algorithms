//============================================================================
// Name        : Stack using linked list.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
}*top=NULL;

int isFull(){
	Node *t=new Node;
	//if node not created then stack is full
	if(t==NULL){
		return 1;
	}
	return -1;
}
//NOTE:genrally does not show full as maximum size is not defined in linked list implementation

int isEmpty(){
	if(top==NULL){
		return 1;
	}
	return -1;
}

void push(int x){
	Node *t=new Node;
	//If node is not created
	if(t==NULL){
		cout<<"\nStack is Full. Cannot insert more elements!!"<<endl;
	}
	else{
		t->data=x;
		t->next=top;
		top=t;
	}
}

int pop(){
	int x=-1;
	if(top==NULL){
		x=-1;
		cout<<"\nCannot pop more elements. Stack is Empty!!"<<endl;
	}
	else{
		Node *p;
		p=top;
		top=top->next;
		x=p->data;
		delete p;
		cout<<"Top element popped from stack"<<endl;
	}
	return x;
}

int StackTop(){
	if(top){
		return top->data;
	}
	return -1;
}

//It returns garbage value
int peep(int pos){
	Node *p=new Node;

	//loop and find value till i is not null
	for(int i=0;i<pos-1;i++){
		if(i!=NULL){
			break;
		}
		p=p->next;
	}

	if(p!=NULL){
		return p->data;
	}
	else{
		return -1;
	}
}

void Display(){
	Node *p;
	p=top;
	cout<<"Elements from top are::\n";
	while(p!=NULL){
		cout<<p->data<<endl;
		p=p->next;
	}
}
int main() {

	 int opn=0;
	 do{
	 	 cout<<"\n------------STACK-----------"<<endl;
	 	 cout<<"1)PUSH\n2)POP\n3)IS FULL\n4)IS EMPTY\n5)TOP OF STACK\n6)DISPLAY\n7)EXIT"<<endl;
	 	 cout<<"--------------------------------"<<endl;
	 	 cout<<"YOUR CHOICE::";
	 	 cin>>opn;

	 switch(opn){
	 case 1:
		 int k;
		 cout<<"Enter the number you want to insert::";
		 cin>>k;
		 push(k);
		 break;
	 case 2:
		 pop();
		 break;
	 case 3:{
		 int b=isFull();
		 if(b==1){
			 cout<<"Stack is Full -->OVERFLOW"<<endl;
		 }
		 else{
			 cout<<"Stack is not Full"<<endl;
		 }
	 }
		 break;
	 case 4:{
		 int c=isEmpty();
		 if(c==1){
			 cout<<"Stack is Empty --> UNDERFLOW"<<endl;
		 }
		 else{
			 cout<<"Stack is not Empty"<<endl;
		 }
	 }
		 break;

	 case 5:{
		 int e=StackTop();
		 if(e==-1){
			 cout<<"Stack Empty"<<endl;
		 }
		 else{
			 cout<<"Top of stack currently is::"<<e<<endl;
		 }
		 break;
	 }
	 case 6:{
		 Display();
		 break;
	 }
	 case 7:{
		 cout<<"Thank You!!!"<<endl;
		 break;
	 }
	 default:{
		 cout<<"Enter correct option"<<endl;

		 break;
	 }
	 }
	 }while(opn<7);
}
