//============================================================================
// Name        : Searching in a linked list.cpp
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

Node* Iterative_LSearch(Node *temp,int key){
	while(temp!=NULL){
		if(key==temp->data){
			return temp;
		}
		temp=temp->next;
	}
	return NULL;
}

Node* Recursive_LSearch(Node *temp,int key){
	if(temp==NULL){
		return NULL;
	}
	if(temp->data==key){
		return temp;
	}
	return Recursive_LSearch(temp->next,key);
}

/*Moving the element found to the front to speed up search next time*/
Node* Move_to_front_Iterative_LSearch(Node *temp,int key){

	Node *q=NULL;	//tail pointer-->pointer before current

	while(temp!=NULL){

		if(key==temp->data){
			q->next=temp->next;			//assign previous pointer to next of the found key
			temp->next=first;			//found node assigned as head node
			first=temp;
			return temp;
		}
		q=temp;
		temp=temp->next;
	}

	return NULL;
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

	cout<<"\n======================================================"<<endl;
	cout<<"******** Searching in a linked list ********"<<endl;


	int key;
	cout<<"\nEnter element to be searched:";
	cin>>key;

	cout<<"\nA) Iterative Linear Search"<<endl;
	Node *res=Iterative_LSearch(first,key);
	if(res){
		cout<<res->data<<" is found in the linked list"<<endl;
	}
	else{
		cout<<"Key not found in the linked list"<<endl;
	}

	cout<<"\nB) Recursive Linear Search"<<endl;
	Node *res1=Recursive_LSearch(first,key);
	if(res1){
		cout<<res1->data<<" is found in the linked list"<<endl;
	}
	else{
		cout<<"Key not present found in the linked list"<<endl;
	}
	cout<<"\n======================================================"<<endl;

	cout<<"******** Move to front linear search ********"<<endl;
	int k;
	cout<<"\nEnter element to be searched:";
	cin>>k;

	Node *res2=Move_to_front_Iterative_LSearch(first,k);
	if(res2){
		cout<<res2->data<<" is found in the linked list"<<endl;
	}
	else{
		cout<<"Key not found in the linked list"<<endl;
	}
	DisplayLL(first);
	cout<<"\n======================================================"<<endl;

}
