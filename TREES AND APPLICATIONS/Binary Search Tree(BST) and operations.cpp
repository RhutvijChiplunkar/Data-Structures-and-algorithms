//============================================================================
// Name        : BINARY SEARCH TREE.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
using namespace std;

struct BSTNode{
	BSTNode *lchild;
	int data;
	BSTNode *rchild;
};

BSTNode *root=NULL;
void Insert(int key){
	BSTNode *t=root;
	BSTNode *r,*p;			//r is for following p and p is for creating new node

	//if root is null, then p will be root node
	if(root==NULL){
		p=new BSTNode;
		p->data=key;
		p->lchild=p->rchild=NULL;
		root=p;
		return;
	}
	while(t!=NULL){
		//for serching r will follow t
		r=t;

		if(key==t->data){
			cout<<"Data already present"<<endl;
			return ;
		}
		else if(key<t->data){
			t=t->lchild;
		}
		else if(key>t->data){
			t=t->rchild;
		}

	}
	p=new BSTNode;
	p->data=key;
	p->lchild=p->rchild=NULL;

	if(p->data<r->data){
		r->lchild=p;
	}
	else{
		r->rchild=p;
	}
}

BSTNode* Search(int key){
	BSTNode *t=root;

	if(t==NULL){
		return t;
	}
	while(t!=NULL){
		if(key==t->data){
			return t;
		}
		else if(key<t->data){
			t=t->lchild;
		}
		else if(key>t->data){
			t=t->rchild;
		}
	}
	return NULL;
}
void Inorder(BSTNode *t){
	if(t){
		Inorder(t->lchild);
		cout<<t->data<<" ";
		Inorder(t->rchild);
	}
}
int main() {

	int opn;

	do{
		cout<<"--------------------------------------------------"<<endl;
		cout<<"BINARY SEARCH TREE WITH OPERATIONS"<<endl;
		cout<<"--------------------------------------------------"<<endl;

		//all operations in cout

		cout<<"Enter your choice::";
		cin>>opn;
		switch(opn){
		case 1:
			int key;
			cout<<"Inset ele::";
			cin>>key;
			Insert(key);

			break;
		case 5:
			cout<<"Thank you!!"<<endl;
			break;
		default:
			cout<<"Enter correct option!!"<<endl;
			break;
		}

	}while(opn<5);


	BSTNode* x=Search(20);
	if(x!=NULL){
		cout<<"\nElement "<<x->data<<" found in the tree"<<endl;
	}
	else{
		cout<<"\nElement not found"<<endl;
	}

}
