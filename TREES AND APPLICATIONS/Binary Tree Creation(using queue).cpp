//============================================================================
// Name        : Binary Tree Creation(using queue).cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
using namespace std;

struct TreeNode{
	TreeNode *lchild;		//pointer to left child
	int data;				//data at the given node
	TreeNode *rchild;		//pointer to right child
};

struct Queue{
	int size;			//size of queue
	int front;			//index pointer to front index
	int rear;			//index pointer to rear index
	TreeNode **Q;		//pointer to tree node, 1 pointer for queue and other for Tree-node
};

void CreateQ(Queue *q,int size){
	q->size=size;
	q->front=q->rear=0;

	//initialize array of length size
	q->Q=new TreeNode*[q->size *(sizeof(TreeNode*))];
}

//insert element at rear end
void Enqueue(Queue *q,TreeNode *x){
	if(q->front==(q->rear+1)%q->size){
		cout<<"Queue if Full, cannot insert more elements!!"<<endl;
	}
	else{
		q->rear=(q->rear+1)%q->size;
		q->Q[q->rear]=x;
	}
}

//remove element from front end
TreeNode* Dequeue(Queue *q){
	TreeNode* x=NULL;
	if(q->front==q->rear){
		cout<<"Queue is Empty, cannot delete elements!!"<<endl;;
	}
	else{
		q->front=(q->front+1)%q->size;
		x=q->Q[q->front];
	}
	return x;
}

int isEmpty(Queue q){
	return q.front==q.rear;
}

//root is null ->consider global
TreeNode *root=NULL;
void CreateTree(){
	TreeNode *p,*t;
	int x;
	Queue q;
	CreateQ(&q,100);

	cout<<"Enter the value of root node::";
	cin>>x;
	//create a root node
	root=new TreeNode;

	//data will be x and left and right pointers will be none
	root->data=x;
	root->lchild=root->rchild=NULL;
	Enqueue(&q,root);

	while(!isEmpty(q)){
		p=Dequeue(&q);
		cout<<"\nEnter the value of left child of "<<p->data<< "::";
		cin>>x;

		//if left child is not present, give -1 as value
		if(x!=-1){
			t=new TreeNode;
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			//insert reference of new node to queue
			Enqueue(&q,t);
		}
		cout<<"\nEnter the value of right child of "<<p->data<< "::";
		cin>>x;

		//if right child is not present, give -1 as value
		if(x!=-1){
			t=new TreeNode;
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			//insert reference of new node to queue
			Enqueue(&q,t);
		}

	}//end while

}

//for sample preorder display of tree
void preorder(TreeNode *p){
	if(p){
		cout<<p->data<<" ";
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

//for sample inorder display of tree
void inorder(TreeNode *p){
	if(p){
		preorder(p->lchild);
		cout<<p->data<<" ";
		preorder(p->rchild);
	}
}
//for sample postorder display of tree
void postorder(TreeNode *p){
	if(p){
		preorder(p->lchild);
		preorder(p->rchild);
		cout<<p->data<<" ";
	}
}
int main() {
	cout<<"-----------------------------------"<<endl;
	cout<<"BINARY TREE CREATION AND TRAVERSALS"<<endl;
	cout<<"-----------------------------------"<<endl;
	CreateTree();

	//display
	cout<<"\nPREORDER TREE TRAVERSAL::"<<endl;
	preorder(root);
	cout<<"\nINORDER TREE TRAVERSAL::"<<endl;
	inorder(root);
	cout<<"\nPOSTORDER TREE TRAVERSAL::"<<endl;
	postorder(root);
	return 0;
}
