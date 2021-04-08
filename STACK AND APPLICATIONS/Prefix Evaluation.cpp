//============================================================================
// Name        : PREFIX EVALUATION.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
#include<cmath>
#include<stack>
#include<string>
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

int PrefixEvaluation(string prefix){
	stack<int> S;
	int op1,op2,result;

	// *** REVERSE THE PREFIX FOR SCANNING FROM RIGHT TO LEFT***
	string prefix_rev;			//variable to store reverse of prefix
	int len=prefix.length();

	for(int i=len-1;i>=0;i--){
		prefix_rev+=prefix[i];
	}

	prefix=prefix_rev;			//assign reverse to prefix

	for(int i=0;i<len;i++){
		//if "operand"
		if(!isOperator(prefix[i])){
			//ASCII code of 0 is subtracted to get integer
			S.push(prefix[i]-'0');
		}
		else if(isOperator(prefix[i])){
			op1=S.top();
			S.pop();
			op2=S.top();
			S.pop();

			//performing operation
			result=Operation(op1,op2,prefix[i]);
			//push result into stack
			S.push(result);
		}
	}
	return S.top();
}

int main() {
	string prefix;

	int opn=0;
	do{
	cout<<"\n--------PREFIX EVALUATION----------"<<endl;
	cout<<"Enter PREFIX::";
	cin>>prefix;
	cout<<"RESULT IS::"<<PrefixEvaluation(prefix);
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
