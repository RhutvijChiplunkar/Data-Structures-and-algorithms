//============================================================================
// Name        : Linked List.cpp
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

void Iterative_DisplayLL(Node* temp){

	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

/*Here the pointer prints the value and then moves to stack*/
void Recursive_DisplayLL(Node* temp){

	if(temp!=NULL){
		cout<<temp->data<<" ";
		Recursive_DisplayLL(temp->next);
	}

}

/*Here the pointer moves to stack and then prints the values, hence we get reverse order*/
void Reverse_Recursive_DisplayLL(Node* temp){

	if(temp!=NULL){
		Reverse_Recursive_DisplayLL(temp->next);
		cout<<temp->data<<" ";
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
/*Recursive method to count no of nodes*/
int Recursive_count_nodes(Node *temp){
	if(temp!=NULL){
		return Recursive_count_nodes(temp->next)+1;
	}
	else{
		return 0;
	}
}

int sum(Node *temp){
	int s=0;
	while(temp!=NULL){
		s+=temp->data;
		temp=temp->next;
	}
	return s;
}

int Recursive_sum(Node *temp){
	if(temp==NULL){
		return 0;
	}
	else{
		return Recursive_sum(temp->next)+temp->data;;
	}
}

void Analysis(){
	cout<<"\n======================================================"<<endl;
	cout<<"********** ANALYSIS OF DISPLAY LINKED LIST ***********"<<endl;
	cout<<"========================================================"<<endl;
	cout<<"Time complexity of display=O(n)"<<endl;
	cout<<"Space complexity of display=O(n)"<<endl;
	cout<<"======================================================"<<endl;
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
	Iterative_DisplayLL(first);
	CreateLL(arr,n);
	cout<<"\nThe linked list by recursive display is::"<<endl;
	Recursive_DisplayLL(first);
	cout<<"\nThe reverse of linked list by recursive display is::"<<endl;
	Reverse_Recursive_DisplayLL(first);
	cout<<"\n\nThe number of nodes in a linked list::"<<endl;
	cout<<"By iterative method::"<<count_nodes(first)<<endl;
	cout<<"By recursive method::"<<Recursive_count_nodes(first)<<endl;
	cout<<"\nThe sum of elements in a linked list::"<<endl;
	cout<<"By iterative method::"<<sum(first)<<endl;
	cout<<"By recursive method::"<<Recursive_sum(first)<<endl;
	Analysis();

	return 0;
}

