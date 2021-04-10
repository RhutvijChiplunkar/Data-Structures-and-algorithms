//============================================================================
// Name        : CIRCULAR QUEUE USING ARRAY.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
using namespace std;

struct Queue{
	int size;		//size of queue
	int front;		//index pointer to front index
	int rear;		//index pointer to rear index
	int *Q;			//pointer to rear
};

//create queue with required size
void CreateQ(Queue *q){
	cout<<"Enter the size of queue::";
	cin>>q->size;
	q->front=q->rear=-1;

	//initialize array of length size
	q->Q=new int[q->size];
}

//check if queue is full
int isFull(Queue *q){
	if(q->front==(q->rear+1)%q->size){
		return 1;
	}
	return 0;
}

//check if queue is empty
int isEmpty(Queue *q){
	if(q->front==-1){
		return 1;
	}
	return 0;
}

//insert element at rear end
void Enqueue(Queue *q,int x){
	if(isFull(q)){
		cout<<"Queue if Full, cannot insert more elements!!"<<endl;
	}
	else{
		q->rear=(q->rear+1)%q->size;
		q->Q[q->rear]=x;
		//for 1-st enqueue operation, increment front by 1(to index 0)
		if (q->front == -1){
			q->front = 0;
		}
	}
}

//remove element from front end
int Dequeue(Queue *q){
	int x=-1;
	if(isEmpty(q)){
		cout<<"Queue is Empty, cannot delete elements!!"<<endl;;
		x=-1;
	}
	else{
		x=q->Q[q->front];
		q->front=(q->front+1)%q->size;

		/*check whether it crosses rear. If so, it means last element is
		   deleted & now the queue is empty. So reset front & rear to -1 */
		if (q->front == (q->rear+1) % q->size){
			q->front = q->rear = -1;
		}

	}
	return x;
}

//output the queue
void Display(Queue *q){
	cout<<"The elements of queue are::"<<endl;

	//If queue is empty it will give garbage value for display
	int i=q->front;
	while(1){
		cout<<q->Q[i]<<" ";
		i=(i+1)%q->size;

		/* check whether it has crossed rear. If so, last element
		  is printed & we need to stop */
		if(i==(q->rear+1)%q->size){
			break;
		}
	}
	cout<<endl;
}

//function to get current front position in queue
int QueueFront(Queue *q){
	return q->front;
}

//function to get current rear position in queue
int QueueRear(Queue *q){
	return q->rear;
}

int main() {
	Queue q;			//struct object
	CreateQ(&q);		//create queue
	 int opn=0;
	 do{
	 	 cout<<"\n----------CIRCULAR QUEUE----------"<<endl;
	 	 cout<<"1)ENQUEUE\n2)DEQUEUE\n3)IS FULL\n4)IS EMPTY\n5)FRONT OF QUEUE\n6)REAR OF QUEUE\n7)DISPLAY\n8)EXIT"<<endl;
	 	 cout<<"--------------------------------"<<endl;
	 	 cout<<"YOUR CHOICE::";
	 	 cin>>opn;

	 switch(opn){
	 case 1:
		 int k;
		 cout<<"Enter the number you want to insert into queue::";
		 cin>>k;
		 Enqueue(&q,k);
		 break;
	 case 2:
		 //display this if element can be removed
		 // function call here itself
		 if(Dequeue(&q)!=-1){
		 cout<<"Front element removed from queue"<<endl;
		 }

		 break;
	 case 3:{
		 int b=isFull(&q);
		 if(b==1){
			 cout<<"Queue is Full"<<endl;
		 }
		 else{
			 cout<<"Queue is not Full"<<endl;
		 }
	 }
		 break;
	 case 4:{
		 int c=isEmpty(&q);
		 if(c==1){
			 cout<<"Queue is Empty"<<endl;
		 }
		 else{
			 cout<<"Queue is not Empty"<<endl;
		 }
	 }
		 break;
	case 5:
		 cout<<"Current Front is at::";
		 cout<<QueueFront(&q);
		 break;
	 case 6:{
		 cout<<"Current Rear is at::";
		 cout<<QueueRear(&q);
		 break;
	 }
	 case 7:{
		 Display(&q);
		 break;
	 }
	 case 8:{
		 cout<<"Thank You!!!"<<endl;
		 break;
	 }
	 default:{
		 cout<<"Enter correct option!!"<<endl;
		 break;
	 }
	 }

	 }while(opn!=8);

}

