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

BSTNode* Rec_Insert(BSTNode *p,int key){

	BSTNode *t=NULL;

	//when we reach leaf node
	if(p==NULL){
		t=new BSTNode;
		t->data=key;
		t->lchild=t->rchild=NULL;
		return t;
	}
	else if(key<p->data){
		p->lchild=Rec_Insert(p->lchild,key);
	}
	else if(key>p->data){
		p->rchild=Rec_Insert(p->rchild,key);
	}
	//if root node is equal
	/*else if(key==p->data){
		return p;
	}*/
	return p;

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

//to find height of the tree
int Height(BSTNode *p){
	int x,y;
	if(p==NULL){
		return 0;
	}
	x=Height(p->lchild);
	y=Height(p->rchild);

	return x>y? x+1:y+1;
}


//to find inorder predecessor
BSTNode* InPre(BSTNode* p){
	while(p!=NULL && p->rchild!=NULL){
		p=p->rchild;
	}
	return p;
}

//to find inorder successor
BSTNode* InSucc(BSTNode* p){
	while(p!=NULL && p->lchild!=NULL){
		p=p->lchild;
	}
	return p;
}

//delete operation on BST
BSTNode* Delete(BSTNode *p, int key){

	BSTNode *q;

	//if tree is null
	if(p==NULL){
		return NULL;
	}
	//for LEAF NODE --> lchild and rchild are NULL
	if(p->lchild==NULL && p->rchild==NULL){
		if(p==root){
			return NULL;
		}
		free(p);
		return NULL;
	}

	//below 2 are for searching an element
	if(key<p->data){
		p->lchild=Delete(p->lchild,key);
	}
	else if(key>p->data){
		p->rchild=Delete(p->rchild,key);
	}

	//if element is found, we further go for delete operation
	else{
		//temp node is useful to delete a particular node
		//BSTNode *temp=root;

		//below 2 are for node with 1 child

		/*
		//if right child is null, then set the node as left child
		if(p->rchild==NULL){
			p=p->lchild;
			delete temp;
		}
		//if left child is null, then set the node as right child
		else if(p->lchild==NULL){
			p=p->rchild;
			delete temp;
		}
		*/
		//If NODE HAS 2 CHILDREN

			if(Height(p->lchild)>Height(p->rchild)){
				q=InPre(p->lchild);
				p->data=q->data;
				p->lchild=Delete(p->lchild,q->data);
			}
			else{
				q=InPre(p->rchild);
				p->data=q->data;
				p->rchild=Delete(p->rchild,q->data);
			}
	}

	return p;
}

//Inorder traversal gives the
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
		cout<<"\n--------------------------------------------------"<<endl;
		cout<<"BINARY SEARCH TREE WITH OPERATIONS"<<endl;
		cout<<"--------------------------------------------------"<<endl;
		cout<<"1)INSERT\n2)SEARCH\n3)DELETE\n4)INORDER TRAVERSALS\n5)RECURSSIVE FUNCTION FOR INSERT EXAMPLE\n6)EXIT"<<endl;


		cout<<"Enter your choice::";
		cin>>opn;
		switch(opn){
		case 1:{
			int key;
			cout<<"Insert element to be added in the tree::";
			cin>>key;
			Insert(key);
			break;
		}
		case 2:{
			int s;
			cout<<"Enter element to be searched::";
			cin>>s;
			BSTNode* x=Search(s);
			if(x!=NULL){
				cout<<"\nElement "<<x->data<<" found in the tree"<<endl;
			}
			else{
				cout<<"\nElement "<<s<<" not present in the tree"<<endl;
			}
			break;
		}
		case 3:{
			int del;
			cout<<"Enter element to be deleted::";
			cin>>del;
			BSTNode* y=Search(del);
			if(y!=NULL){
				Delete(root,del);
				cout<<"Element "<<del<<" successfully deleted from the tree"<<endl;
			}
			else{
				cout<<"\nThis element is not present in the tree"<<endl;
			}

			break;
		}
		case 4:{
			cout<<"INORDER TRAVERSAL TO BST :: ";
			Inorder(root);
			cout<<endl;
			break;
		}
		case 5:{
			cout<<"------RECURSSIVE INSERT FUNCTION--------"<<endl;
			root=Rec_Insert(root,20);
			Rec_Insert(root,10);
			Rec_Insert(root,30);
			Rec_Insert(root,5);
			Rec_Insert(root,15);
			Rec_Insert(root,25);
			Rec_Insert(root,35);

			Delete(root,25);
			Delete(root,10);
			Inorder(root);
			cout<<"\n--------------------------------"<<endl;
			break;
		}
		case 6:{
			cout<<"Thank you!!"<<endl;
			break;
		}
		default:{
			cout<<"Enter correct option!!"<<endl;
			break;

		}
		}

	}while(opn!=6);



}
