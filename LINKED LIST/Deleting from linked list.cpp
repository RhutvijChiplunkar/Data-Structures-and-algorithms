//============================================================================
// Name        : Deleting from linked list.cpp
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

int Delete(Node *temp,int index){
	Node *q=NULL;
	int x=-1; 	//To store value of deleted element

	if(index<1 || index>count_nodes(temp)){
		return -1;
	}
	//only 1 element present
	if(index==1){
		q=first;
		x=first->data;
		first=first->next;
		delete q;
		return x;
	}
	//more than 1 element present
	else{
		//move to a position before
		for(int i=0;i<index-1;i++){
			q=temp;
			temp=temp->next;
		}
		//point previous node to the next
		q->next=temp->next;
		//assign data of node to x
		x=temp->data;
		//delete the node
		delete temp;
		return x;
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

	CreateLL(arr,n);

	cout<<"\n======================================================"<<endl;
	cout<<"The linked list by iterative display is::"<<endl;
	DisplayLL(first);

	cout<<"\n======================================================"<<endl;
	cout<<"******** Deleting from a linked list *********"<<endl;

	int pos;
	cout<<"\nEnter position at which element is to be deleted:";
	cin>>pos;
	int res=Delete(first,pos);
	cout<<res<<" is deleted from the linked list"<<endl;
	DisplayLL(first);
	cout<<"\n======================================================"<<endl;

}

