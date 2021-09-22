//============================================================================
// Name        : Inserting in a linked list.cpp
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

void Insert(Node *temp,int index,int value){
	Node *t;
	if(index<0 || index>count_nodes(temp)){
		return;
	}
	t=new Node;
	t->data=value;

	//before the first node
	if(index==0){
		t->next=first;
		first=t;
	}
	else{
		//move first pointer to second last index position
		for(int i=0;i<index-1;i++){
			temp=temp->next;
		}
		t->next=temp->next;
		temp->next=t;
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
	cout<<"******** Inserting in a linked list *********"<<endl;

	int key,pos;
	cout<<"\nEnter element to be inserted:";
	cin>>key;

	cout<<"\nA) Insert at front"<<endl;
	Insert(first,0,key);
	DisplayLL(first);

	cout<<"\n\nB) Insert in between"<<endl;
	cout<<"Enter position at which element is to be inserted:";
	cin>>pos;
	Insert(first,pos,key);
	DisplayLL(first);

	//set index position as count_nodes hence we can insert at last index
	cout<<"\n\nC) Insert at last index"<<endl;
	Insert(first,count_nodes(first),key);
	DisplayLL(first);

	cout<<"\n======================================================"<<endl;

	/*NOTE: We can directly create linked list by using->Insert(first,0,value)*/
}
