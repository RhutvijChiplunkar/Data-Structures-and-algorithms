//============================================================================
// Name        : BINARY SEARCH.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
using namespace std;

int Binary_Search(int arr[],int n, int key){
	int low=0;
	int high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(key==arr[mid]){
			return mid;
		}
		else if(key>arr[mid]){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return -1;
}

void Analysis(){
	cout<<"\n======================================================"<<endl;
	cout<<"********** ANALYSIS OF BINARY SEARCH ***********"<<endl;
	cout<<"========================================================"<<endl;
	cout<<"\n********** TIME COMPLEXITY ***********"<<endl;
	cout<<"BEST CASE :: O(1) --> Found at middle position"<<endl;
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
	cout<<"\nPlease enter array elements in ASCENDING ORDER"<<endl;
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

	int result=Binary_Search(arr,n,k);

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
