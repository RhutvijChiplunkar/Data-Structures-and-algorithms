//============================================================================
// Name        : INFIX TO PREFIX.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
#include<stack>
#include<string>
#include<algorithm>
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

//associativity function
int associativity(char c){
	if(c=='^')
		return 1;			//"1" if for "RIGHT TO LEFT"
	else
		return 0;			//"0" if for "LEFT TO RIGHT"
}

string Infix_to_Prefix(stack<char> S,string infix){

	string rev_infix;		//variable to store reverse string

	//reversing a string for scanning in prefix
	int len=infix.length();
	for(int i=len-1;i>=0;i--){
		rev_infix+=infix[i];
	}

	/* INBUILT REVERSE FUNCTION IN "ALGORITHM"
	reverse(infix.begin(),infix.end());
	*/

	//infix assigned to reverse of it
	infix=rev_infix;

	string prefix;							//it is an object of string
	int length=infix.length();

	//traversing through string
	for(int i=0;i<length;i++){
		//any "operand"
		if((infix[i]>='a' && infix[i]<='z')||(infix[i]>='A' && infix[i]<='Z')){
			prefix+=infix[i];
		}

		//for opening bracket
		else if(infix[i]=='('){
			while(S.top()!=')' && (!S.empty())){
				prefix+=S.top();
				S.pop();
			}
			//remove extra brackets
			if(S.top()==')'){
				S.pop();
			}
		}

		//for closing bracket
		else if(infix[i]==')'){
			S.push(infix[i]);
		}

		//For any "Operator"
		else if(isOperator(infix[i])){
			if(S.empty() or S.top()==')' or precedence(S.top())<precedence(infix[i])){
				S.push(infix[i]);
			}
			else if(precedence(S.top())>precedence(infix[i])){
				prefix+=S.top();
				S.pop();
				S.push(infix[i]);
			}
			else if(precedence(S.top())==precedence(infix[i])){
				// right to left
				if(associativity(S.top())==1){
					prefix+=S.top();
					S.pop();
					S.push(infix[i]);
				}
				//left to right
				else if(associativity(S.top())==0){
					S.push(infix[i]);
				}
			}
		}

	}//end for

	while(!S.empty()){
		prefix+=S.top();
		S.pop();
	}

	// prefix is obtained in reverse order, so again reverse it to get PREFIX
	string prefix_rev;
	int l=prefix.length();
	for(int i=l-1;i>=0;i--){
		prefix_rev+=prefix[i];
	}

	//final output
	return prefix_rev;
}
int main() {

	stack<char> S;
	string infix;		//it is an object of string

	int opn=0;
	do{
		cout<<"\n----------INFIX TO PREFIX---------"<<endl;
		cout<<"Enter INFIX expression:";
		cin>>infix;

		if(ValidExp(infix)){
		cout<<"\nValid Expression"<<endl;
		cout<<"INFIX::"<<infix;
		cout<<endl;
		cout<<"PREFIX::";
		cout<<Infix_to_Prefix(S,infix)<<endl;
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
