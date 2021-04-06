//============================================================================
// Name        : Stack using array template.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
using namespace std;

template<class T>
class Stack{
private:
	T *St;		//pointer to stack
	int size;
	int top;
public:
	Stack(){size=10;top=-1;St=new T[size];}
	Stack(int size){this->size=size;top=-1;St=new
	T[this->size];}

	void push(T x);
	T pop();
	T peep(int pos);
	int isEmpty();
	int isFull();
	int StackTop();
	void Display();
};

template <class T>
int Stack<T>::isFull(){
	return top==size-1;
}

template <class T>
int Stack<T>::isEmpty(){
	return top==-1;
}

template<class T>
void Stack<T>::push(T x){
	if(isFull()){
		cout<<"\nStack is Full. Cannot insert more elements!!"<<endl;
	}
	else{
		top++;
		St[top]=x;
	}
}

template<class T>
T Stack<T>::pop(){
	T x=-1;
	if(isEmpty()){
		cout<<"Stack is empty!! Cannot pop more elements";
	}
	else{
		x=St[top];	//decrement and assign in same
		top--;
	}
	return x;
}

template<class T>
int Stack<T>::StackTop(){
	if(isEmpty()){
		return -1;
	}
	return St[top];
}

template<class T>
T Stack<T>::peep(int pos){
	T x=-1;
	if(top-pos+1<=0)
		x=-1;
	else{
		x=St[top-pos+1];
	}
	return x;
}

template <class T>
void Stack<T>::Display(){
	cout<<"Elements from top are::\n";
	for(int i=top;i>=0;i--){
		cout<<St[i]<<endl;				//********IT DISPLAYS ASCII CHARACTERS ******/
	}
}
int main() {

	 Stack<char> St(4);					//struct object with size 4

	 int opn=0;
	 do{
	 	 cout<<"\n------------STACK TEMPLATE-----------"<<endl;
	 	 cout<<"1)PUSH\n2)POP\n3)IS FULL\n4)IS EMPTY\n5)PEEP\n6)TOP OF STACK\n7)DISPLAY\n8)EXIT"<<endl;
	 	 cout<<"--------------------------------"<<endl;
	 	 cout<<"YOUR CHOICE::";
	 	 cin>>opn;

	 switch(opn){
	 case 1:
		 char k;
		 cout<<"Enter the data you want to insert::";
		 cin>>k;
		 St.push(k);
		 break;
	 case 2:
		 St.pop();
		 cout<<"Top element popped from stack"<<endl;
		 break;
	 case 3:{
		 bool b=St.isFull();
		 if(b==1){
			 cout<<"Stack is Full -->OVERFLOW"<<endl;
		 }
		 else{
			 cout<<"Stack is not Full"<<endl;
		 }
	 }
		 break;
	 case 4:{
		 bool c=St.isEmpty();
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
		 int d=St.peep(pos);
		 if(d==-1){
			 cout<<"\nNo Element at given index"<<endl;
		 }
		 else{
			 cout<<"Element at give index is::"<<d<<endl;
		 }
		 break;
	}
	 case 6:{
		 int e=St.StackTop();
		 if(e==-1){
			 cout<<"Stack Empty"<<endl;
		 }
		 else{
			 cout<<"Top of stack currently is::"<<e<<endl;
		 }
		 break;
	 }
	 case 7:{
		 St.Display();
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
