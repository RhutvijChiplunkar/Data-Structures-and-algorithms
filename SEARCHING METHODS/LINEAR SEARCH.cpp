//============================================================================
// Name        : LINEAR SEARCH.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
using namespace std;

int Linear_Search(int arr[],int n,int key){

	for(int i=0;i<n;i++){
		if(key==arr[i]){
			return i;
		}
	}
	return -1;
}
void Analysis(){
	cout<<"\n======================================================"<<endl;
	cout<<"********** ANALYSIS OF LINEAR SEARCH ***********"<<endl;
	cout<<"========================================================"<<endl;
	cout<<"\n********** TIME COMPLEXITY ***********"<<endl;
	cout<<"BEST CASE :: O(1) --> Found at 1-st position"<<endl;
	cout<<"AVERAGE CASE :: O(n) --> Found in-between "<<endl;
	cout<<"WORST CASE :: O(n) --> Element not found"<<endl;
	cout<<endl;

	cout<<"********** SPACE COMPLEXITY ***********"<<endl;
	cout<<"Space complexity :: O(1)"<<endl;
	cout<<"======================================================"<<endl;

}
int main() {
	int n;

	cout<<"Enter the number of elements in array::";
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){
		cout<<"Enter element arr["<<i<<"]::";
		cin>>arr[i];
	}


	cout<<"\nThe array is::"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	int opn=1;
	do{
	int k;
	cout<<"\nEnter the element to be searched in array::";
	cin>>k;

	int result=Linear_Search(arr,n,k);

	if(result==-1)
		cout<<"ELEMENT NOT PRESENT IN GIVEN ARRAY"<<endl;
	else
		cout<<"ELEMENT FOUND AT INDEX ::"<<result<<endl;

	cout<<"\nDo you want to continue serching? \n1)YES \n2)NO"<<endl;
	cout<<"Your choice::";
	cin>>opn;

	if(opn==2){
		cout<<"Thank you!!"<<endl;
	}
	}while(opn==1);

	Analysis();
}
