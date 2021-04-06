//============================================================================
// Name        : Parenthesis Matching using Stack.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
#include<stack>
using namespace std;

stack<char> S;
int ParenthesisMatch(string exp){
	//for until char is null
	for(int i=0;exp[i]!='\0';i++){
		if(exp[i]=='('){
			S.push(exp[i]);
		}
		else if(exp[i]==')'){
			//if '(' is not present
			if(S.empty()){
				return 0;
			}
			//one '(' is popped
			S.pop();
		}
	}
	//if empty->matching
	if(S.empty()){
		return 1;
	}
	//else ->not matching
	else{
		return 0;
	}

}
int main() {

	int opn=0;
	do{
	string expression;
	cout<<"\nEnter a mathematical expression with parenthesis::";
	cin>>expression;

	int x=ParenthesisMatch(expression);
	if(x==1){
		cout<<"PARENTHESIS MATCHING!!!"<<endl;
	}
	else{
		cout<<"PARENTHESIS NOT MATCHING!!!"<<endl;
	}
	cout<<"\nDo you want to check more expressions::"<<endl;
	cout<<"1)YES\n2)NO"<<endl;
	cout<<"Your choice::";
	cin>>opn;

	if(opn==2){
		cout<<"Thank you!!"<<endl;
	}
	}while(opn<2);

	return 0;
}
