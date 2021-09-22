//============================================================================
// Name        : Inserting in a sorted linked list.cpp
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
Node *first=NULL;

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

void SortedInsert(Node *temp,int x){
	Node *t,*q;		//q is trailing pointer

	t=new Node;
	t->data=x;
	t->next=NULL;

	//if LL is empty insert at first place
	if(first==NULL){
		first=t;
	}
	else{
		while(temp && temp->data<x){
			q=temp;
			temp=temp->next;
		}

		//element is to be inserted before first node
		if(temp==first){
			t->next=first;
			first=t;
		}
		else{
			t->next=q->next;
			q->next=t;
		}

	}
}
int main() {
	int n;
	cout<<"Enter the number of elements in array::";
	cin>>n;

	int arr[n];
	cout<<"Enter "<<n<<" elements"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	//sorting the input
	sort(arr,arr+n);
	CreateLL(arr,n);

	cout<<"\n======================================================"<<endl;
	cout<<"The linked list by iterative display is::"<<endl;
	DisplayLL(first);

	cout<<"\n======================================================"<<endl;
	cout<<"******** Inserting in a sorted linked list *********"<<endl;

	int key;
	cout<<"\nEnter element to be inserted:";
	cin>>key;
	SortedInsert(first,key);
	DisplayLL(first);

	cout<<"\n======================================================"<<endl;

}
