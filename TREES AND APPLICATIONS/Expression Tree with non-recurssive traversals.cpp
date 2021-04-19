//============================================================================
// Name        : EXPRESSION TREE WITH NON-RECURSSIVE TRAVERSALS.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
#include<string>
#include<stack>
using namespace std;

//check if character is an operator or not
bool isOperator(char c){
	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='^'){
		return true;
	}
	else{
		return false;
	}
}

//check validity of expression
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

struct ExpTree{
	ExpTree *lchild;
	char data;
	ExpTree *rchild;
};

ExpTree* CreateExpTree(string postfix){

	//stack has data type of Expression tree
	stack<ExpTree*> s;

	//new expression tree as root
	ExpTree *root=NULL;
	root=new ExpTree;

	for(int i=0;postfix[i]!='\0';i++){
		//for operands
		if(isalnum(postfix[i])){
			ExpTree *temp=new ExpTree;
			temp->data=postfix[i];
			temp->lchild=temp->rchild=NULL;
			s.push(temp);
		}
		//for operators
		else{
			ExpTree *temp=new ExpTree;
			temp->data=postfix[i];
			temp->rchild=s.top();
			s.pop();
			temp->lchild=s.top();
			s.pop();
			s.push(temp);
		}
	}
	//root will be the final binary tree created, which is at top of stack
	root=s.top();
	return root;
}

//INORDER --> LVR
void nrec_inorder(ExpTree *p){
	//stack of node address type
	stack<ExpTree*> s;

	//while p is not null and stack is not empty
	while(p!=NULL || !s.empty()){

		//if p is not null go to left child
		if(p!=NULL){
			s.push(p);
			p=p->lchild;
		}
		//if p is null, pop a node and go to its right child
		else{
			p=s.top();
			s.pop();
			cout<<p->data;			//print the left child
			p=p->rchild;
		}
	}
}
//PREORDER -->VLR
void nrec_preorder(ExpTree *p){
	//stack of node address type
	stack<ExpTree*> s;

	//while p is not null and stack is not empty
	while(p!=NULL || !s.empty()){

		//if p is not null go to left child
		if(p!=NULL){
			cout<<p->data;		//print the vertex
			s.push(p);
			p=p->lchild;
		}
		//if p is null, pop a node and go to its right child
		else{
			p=s.top();
			s.pop();
			p=p->rchild;
		}
	}
}

//POSTORDER --> LRV
/*void nrec_postorder(ExpTree *p){
	//stack of node address type
	stack<ExpTree*> s;
	long int temp;

	//while p is not null and stack is not empty
	while(p!=NULL || !s.empty()){

		//if p is not null go to left child
		if(p!=NULL){
			s.push(p);
			p=p->lchild;
		}
		//if p is null, pop a node and go to its right child
		else{
			temp=s.top();
			s.pop();
			if(temp>0){
				s.push(ExpTree *temp);
			}
		}
	}
}
*/

int main() {

	string postfix;

	int opn=1;

	while(opn==1){
	cout<<"--------------------------------------------------"<<endl;
	cout<<"EXPRESSION TREE CREATION AND NON-RECURSSIVE TRAVERSALS"<<endl;
	cout<<"--------------------------------------------------"<<endl;
	cout<<"ENTER POSTFIX EXPRESSION:: ";
	cin>>postfix;

	if(ValidExp(postfix)){
		ExpTree *x=CreateExpTree(postfix);
		cout<<"Tree is successfully created!!!"<<endl;
		cout<<"--------------------------------------------------"<<endl;

		cout<<"INORDER EXPRESSION:: ";
		nrec_inorder(x);
		cout<<"\nPREORDER EXPRESSION:: ";
		nrec_preorder(x);
		/*cout<<"\nPOSTORDER EXPRESSION:: ";
		nrec_postorder(x);*/
		cout<<"\n--------------------------------------------------"<<endl;
	}
	else{
		cout<<"\nNot a Valid Postfix Expression"<<endl;
	}
	cout<<"\nWant to construct more expression trees"<<endl;
	cout<<"1)YES\n2)NO"<<endl;
	cout<<"Your choice::";
	cin>>opn;

	if(opn==2){
		cout<<"\nThank you!!"<<endl;
	}

	}//end while

}
