//============================================================================
// Name        : Concatenating and Merging two linked lists.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* next;
};

//global pointer
Node *first=NULL,*second=NULL,*third=NULL;

void CreateLL(int arr[],int n){
	int i;
	Node *t,*last;		//temp and last pointer

	first=new Node;
	first->data=arr[0];
	first->next=NULL;

	last=first;

	for(i=1;i<n;i++){
		t=new Node;
		t->data=arr[i];
		t->next=NULL;

		last->next=t;
		last=t;
	}
}

void CreateLL2(int arr[],int n){
	int i;
	Node *t,*last;		//temp and last pointer

	second=new Node;
	second->data=arr[0];
	second->next=NULL;

	last=second;

	for(i=1;i<n;i++){
		t=new Node;
		t->data=arr[i];
		t->next=NULL;

		last->next=t;
		last=t;
	}
}


void DisplayLL(Node* temp){

	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int count_nodes(Node *temp){
	int c=0;
	while(temp){
		c++;
		temp=temp->next;
	}
	return c;
}

void ConcatLL(Node *p,Node *q){
	third=p;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=q;
}

//NOTE:Merging -> concatenating 2 sorted linked list into single sorted linked list
void MergeLL(Node *p,Node *q){
	Node *last;
	if(p->data<q->data){
		third=last=p;
		p=p->next;
		third->next=NULL;
	}
	else{
		third=last=q;
		q=q->next;
		third->next=NULL;
	}

	while(p && q){
		if(p->data<q->data){
			last->next=p;
			last=p;
			p=p->next;
			last->next=NULL;
		}
		else{
			last->next=q;
			last=q;
			q=q->next;
			last->next=NULL;
		}
	}
	if(p){
		last->next=p;
	}
	if(q){
		last->next=q;
	}
}


int main() {

	int opn=0;
	do{
		cout<<"\n\n1) Concatenate 2 Linked lists"<<endl;
		cout<<"2) Merge 2 Linked lists"<<endl;
		cout<<"3) Exit"<<endl;
		cout<<"\nYour option::";
		cin>>opn;
		switch(opn){
			case 1:{
				int m,n;
				cout<<"Enter the number of elements in first array::";
				cin>>m;

				int arr[m];
				cout<<"Enter "<<m<<" elements"<<endl;
				for(int i=0;i<m;i++){
					cin>>arr[i];
				}

				cout<<"Enter the number of elements in second array::";
				cin>>n;
				int brr[n];
				cout<<"Enter "<<n<<" elements"<<endl;
				for(int i=0;i<n;i++){
					cin>>brr[i];
				}
				CreateLL(arr,m);
				CreateLL2(brr,n);
				ConcatLL(first,second);
				DisplayLL(third);
				break;
		}
			case 2:{
			int x,y;
			cout<<"Enter the number of elements in first array::";
			cin>>x;

			int a[x];
			cout<<"Enter "<<x<<" elements"<<endl;
			for(int i=0;i<x;i++){
				cin>>a[i];
			}

			cout<<"Enter the number of elements in second array::";
			cin>>y;
			int b[y];
			cout<<"Enter "<<y<<" elements"<<endl;
			for(int i=0;i<y;i++){
				cin>>b[i];
			}
			sort(a,a+x);
			sort(b,b+y);
			CreateLL(a,x);
			CreateLL2(b,y);
			MergeLL(first,second);
			DisplayLL(third);
			break;
			}
		case 3:{
			cout<<"Thank you"<<endl;
			break;
		}
		}
	}while(opn<3);

	/*cout<<"\n======================================================"<<endl;
	cout<<"The linked list by iterative display is::"<<endl;
	cout<<"***Linked list 1 ***"<<endl;
	DisplayLL(first);

	cout<<"\n***Linked list 2 ***"<<endl;

	DisplayLL(second);

	cout<<"\n======================================================"<<endl;


	cout<<"\n======================================================"<<endl;*/
}

