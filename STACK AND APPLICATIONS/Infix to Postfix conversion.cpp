//============================================================================
// Name        : INFIX TO POSTFIX.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
#include<stack>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int precedence(char c){

	if(c=='^'){
		return 3;
	}

	if(c=='*' || c=='/' || c=='%'){
		return 2;
	}

	if(c=='+' || c=='-'){
		return 1;
	}
	/*if(c=='(' || c==')'){
		return 4;
	}*/
	return -1;
}

bool isOperator(char c){
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='^'){
		return true;
	}
	else{
		return false;
	}
}

//associativity function
int associativity(char c){
	if(c=='^')
		return 1;			//"1" if for "RIGHT TO LEFT"
	else
		return 0;			//"0" if for "LEFT TO RIGHT"
}


//check validity of function
bool ValidExp(string infix){
	int operators=0,operands=0;
	int len=infix.length();

	for(int i=0;i<len;i++){
		if(infix[i]=='(' || infix[i]==')' ){
			continue;
		}
		if(isOperator(infix[i])){
			operators++;
		}
		if(!isOperator(infix[i])){
			operands++;
		}

	}
	//operands-operator should be 1
	if(operands-operators==1){
		return true;
	}
	else{
		return false;
	}
}

string Infix_to_Postfix(stack<char> S,string infix){

	string postfix;				//it is an object of string
	int len=infix.length();

	//traverse string
	for(int i=0;i<len;i++){
		//any "operand"
		if((infix[i]>='a' && infix[i]<='z')||(infix[i]>='A' && infix[i]<='Z')){
			postfix+=infix[i];
		}
		//for opening bracket
		else if(infix[i]=='('){
			S.push(infix[i]);
		}
		//for closing bracket
		else if(infix[i]==')'){
			while(S.top()!='(' && (!S.empty())){
				postfix+=S.top();
				S.pop();
			}
			//remove extra brackets
			if(S.top()=='('){
				S.pop();
			}
		}
		//For any "Operator"
		else if(isOperator(infix[i])){

			if(S.empty() or (associativity(infix[i])==1 and precedence(infix[i])==precedence(S.top()))){
				S.push(infix[i]);
			}
			else if(S.empty() || S.top()=='(' || precedence(infix[i])>precedence(S.top())){
				S.push(infix[i]);		//push operator to stack if it has higher precedence
			}
			else if(!S.empty()){
				postfix+=S.top();
				S.pop();
				S.push(infix[i]);
			}
		}

	}//end for

	while(!S.empty()){
		postfix+=S.top();
		S.pop();
	}
	return postfix;
}//end function
int main() {

	stack<char> S;
	string infix;			//it is an object of string

	int opn=0;
	do{
		cout<<"\n----------INFIX TO POSTFIX---------"<<endl;
		cout<<"Enter INFIX expression:";
		cin>>infix;

		if(ValidExp(infix)){
		cout<<"\nValid Expression"<<endl;
		cout<<"INFIX::"<<infix;
		cout<<endl;
		cout<<"POSTFIX::";
		cout<<Infix_to_Postfix(S,infix)<<endl;
		}
		else{
			cout<<"\nNot a Valid Expression"<<endl;
		}
		cout<<"\nWant to convert more expressions?"<<endl;
		cout<<"1)YES\n2)NO"<<endl;
		cout<<"Your choice::";
		cin>>opn;
		if(opn==2){
			cout<<"\nThank you!!"<<endl;
		}
	}while(opn<2);
}
