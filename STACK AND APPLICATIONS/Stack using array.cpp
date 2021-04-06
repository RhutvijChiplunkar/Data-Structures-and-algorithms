//============================================================================
// Name        : Stack using array.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
using namespace std;

struct Stack{
	int size;
	int top;
	int *s;		//pointer to array
};

void Create(Stack *St){
	cout<<"Enter the size of stack::";
	cin>>St->size;
	St->top=-1;
	St->s=(int *)malloc(St->size*sizeof(int));
}

int isFull(Stack St){
	if(St.top==St.size-1){
		return 1;
	}
	return 0;
}

int isEmpty(Stack St){
	if(St.top==-1){
		return 1;
	}
	return 0;
}

void push(Stack *St,int x){
	if(St->top==St->size-1){
		cout<<"\nStack is Full. Cannot insert more elements!!"<<endl;
		return ;
	}
	else{
		St->top++;
		St->s[St->top]=x;
	}
}

int pop(Stack *St){
	int x=-1;
	if(St->top==-1){
		x=-1;
	}
	else{
		x=St->s[St->top--];		//decrement and assign in same
	}
	return x;
}

int StackTop(Stack St){
	if(!isEmpty(St)){
		return St.s[St.top];
	}
	return -1;
}

int peep(Stack St, int pos){
	int x=-1;
	if(St.top-pos+1<=0)
		x=-1;
	else{
		x=St.s[St.top-pos+1];
	}
	return x;
}

void Display(Stack St){
	cout<<"Elements from top are::\n";
	for(int i=St.top;i>=0;i--){
		cout<<St.s[i]<<endl;
	}
}
int main() {

	 Stack St;					//struct object

	 Create(&St);				//create a stack

	 int opn=0;
	 do{
	 	 cout<<"\n------------STACK-----------"<<endl;
	 	 cout<<"1)PUSH\n2)POP\n3)IS FULL\n4)IS EMPTY\n5)PEEP\n6)TOP OF STACK\n7)DISPLAY\n8)EXIT"<<endl;
	 	 cout<<"--------------------------------"<<endl;
	 	 cout<<"YOUR CHOICE::";
	 	 cin>>opn;

	 switch(opn){
	 case 1:
		 int k;
		 cout<<"Enter the number you want to insert::";
		 cin>>k;
		 push(&St,k);
		 break;
	 case 2:
		 pop(&St);
		 cout<<"Top element popped from stack"<<endl;
		 break;
	 case 3:{
		 int b=isFull(St);
		 if(b==1){
			 cout<<"Stack is Full -->OVERFLOW"<<endl;
		 }
		 else{
			 cout<<"Stack is not Full"<<endl;
		 }
	 }
		 break;
	 case 4:{
		 int c=isEmpty(St);
		 if(c==1){
			 cout<<"Stack is Empty --> UNDERFLOW"<<endl;
		 }
		 else{
			 cout<<"Stack is not Empty"<<endl;
		 }
	 }
		 break;
	case 5:{
		 int pos;
		 cout<<"Enter position from top::";
		 cin>>pos;
		 int d=peep(St,pos);
		 if(d==-1){
			 cout<<"\nNo Element at given index"<<endl;
		 }
		 else{
			 cout<<"Element at give index is::"<<d<<endl;
		 }
		 break;
	}
	 case 6:{
		 int e=StackTop(St);
		 if(e==-1){
			 cout<<"Stack Empty"<<endl;
		 }
		 else{
			 cout<<"Top of stack currently is::"<<e<<endl;
		 }
		 break;
	 }
	 case 7:{
		 Display(St);
		 break;
	 }
	 case 8:{
		 cout<<"Thank You!!!"<<endl;
		 break;
	 }
	 default:{
		 cout<<"Enter correct option"<<endl;

		 break;
	 }
	 }
	 }while(opn<8);
}
