//============================================================================
// Name        : POSTFIX EVALUATION.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
#include<stack>
#include<string>
#include<cmath>
using namespace std;

//mathematical operations to be performed
int Operation(int op1,int op2,char c){
	int result;
	switch(c){
	case '+':
		result=op1+op2;
		break;
	case '-':
		result=op1-op2;
		break;
	case '*':
		result=op1*op2;
		break;
	case '/':
		result=op1/op2;
		break;
	case '^':
		result=pow(op1,op2);
		break;
	}
	return result;
}

//check if operator or operand
bool isOperator(char c){
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='^'){
		return true;
	}
	else{
		return false;
	}
}

int PostfixEvaluation(string postfix){
	stack<int> S;
	int op1,op2,result;

	for(int i=0;postfix[i]!='\0';i++){
		//if "operand"
		if(!isOperator(postfix[i])){
			//ASCII code of 0 is subtracted to get integer
			S.push(postfix[i]-'0');
		}
		//if "operator"
		else{
			op2=S.top();		//upper operand
			S.pop();
			op1=S.top();		//lower operand
			S.pop();
			//calculate result and push on stack
			result=Operation(op1,op2,postfix[i]);
			S.push(result);
		}
	}

	return S.top(); 
}

int main() {
	string postfix;

	int opn=0;
	do{
	cout<<"\n--------POSTFIX EVALUATION----------"<<endl;
	cout<<"Enter POSTFIX::";
	cin>>postfix;
	cout<<"RESULT IS::"<<PostfixEvaluation(postfix);
	cout<<"\n-------------------------------------"<<endl;

	cout<<"\nWant to evaluate more expressions?"<<endl;
	cout<<"1)YES\n2)NO"<<endl;
	cout<<"Your choice::";
	cin>>opn;
	if(opn==2){
		cout<<"\nThank you!!"<<endl;
	}
	}while(opn<2);
}
