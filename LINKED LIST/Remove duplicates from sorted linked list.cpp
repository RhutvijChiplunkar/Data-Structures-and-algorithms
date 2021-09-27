//============================================================================
// Name        : Remove duplicates from sorted linked list.cpp
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

void RemoveDuplicates(Node *temp){
	Node *q=temp->next;		//pointer to next node that is useful for comparing values
	while(q!=NULL){
		if(temp->data!=q->data){
			temp=q;
			q=q->next;
		}
		else{
			temp->next=q->next;
			//delete the repeating element
			delete q;
			q=temp->next;
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

	CreateLL(arr,n);

	cout<<"\n======================================================"<<endl;
	cout<<"******** DISPLAY ********"<<endl;
	cout<<"The linked list by iterative display is::"<<endl;
	DisplayLL(first);

	cout<<"\n\n--Removing duplicates from the linked list--"<<endl;
	RemoveDuplicates(first);
	cout<<"**After removing duplicates**"<<endl;
	DisplayLL(first);
	cout<<"\n======================================================"<<endl;
	return 0;
}
