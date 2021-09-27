//============================================================================
// Name        : Sorted Linked List.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
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

int isSorted(Node *temp){
	int x=INT_MIN;
	while(temp!=NULL){
		if(temp->data<x){
			return 0;
		}
		x=temp->data;
		temp=temp->next;
	}
	return 1;
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

	CreateLL(arr,n);

	cout<<"\n======================================================"<<endl;
	cout<<"******** DISPLAY ********"<<endl;
	cout<<"The linked list by iterative display is::"<<endl;
	DisplayLL(first);

	cout<<"\n\nCheck if linked list is sorted"<<endl;
	if(isSorted(first)){
		cout<<"Linked list is sorted"<<endl;
	}
	else{
		cout<<"Linked list is not sorted"<<endl;
	}

	return 0;
}
