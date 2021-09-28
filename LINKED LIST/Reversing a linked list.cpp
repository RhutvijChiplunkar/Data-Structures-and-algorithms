//============================================================================
// Name        : Reversing a linked list.cpp
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

//By reversing the elements
void ReverseLL1(Node *temp){
	Node *q=temp;
	int *arr,i=0;
	arr=new int[count_nodes(temp)];

	while(temp!=NULL){
		arr[i]=temp->data;
		temp=temp->next;
		i++;
	}

	/*OR
	 * while(q!=NULL){
		arr[i]=q->data;
		q=q->next;
		i++;
	}

	q=temp;*/
	i--;

	while(q!=NULL){
		q->data=arr[i];
		q=q->next;
		i--;
	}
}

//By reversing the links - Sliding pointers
/*NOTE: We prefer this because reversing the data in case of data is very large is not preferable*/
void ReverseLL2(Node *temp){
	Node *q=NULL,*r=NULL;

	while(temp!=NULL){
		//3 steps are for sliding pointers
		r=q;
		q=temp;
		temp=temp->next;

		//to reverse the link
		q->next=r;
	}
	//make new linked list as reversed linked list
	first=q;
}

//reversing a linked list using recursion
void ReverseLL3(Node *q,Node* p){
	////q is trailing pointer
	if(p){
		ReverseLL3(p,p->next);
		p->next=q;
	}
	else{
		//make new linked list as reversed linked list
		first=q;
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
	cout<<"******** Reversing a linked list *********"<<endl;

	cout<<"\nA) By reversing the elements"<<endl;
	ReverseLL1(first);
	DisplayLL(first);

	cout<<"\nB) By reversing the links - Sliding pointers"<<endl;
	CreateLL(arr,n);
	ReverseLL2(first);
	DisplayLL(first);

	cout<<"\nC) Using Recursion"<<endl;
	CreateLL(arr,n);
	ReverseLL3(NULL,first);
	DisplayLL(first);

	cout<<"\n======================================================"<<endl;
}

