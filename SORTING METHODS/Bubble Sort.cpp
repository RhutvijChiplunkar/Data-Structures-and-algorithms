//============================================================================
// Name        : BUBBLE SORT.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
using namespace std;

void Bubble_Sort(int arr[],int n){

	for(int i=0;i<n-1;i++){
		int flag=0;		//variable used to check for pass 1 (ADAPTIVE)
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				flag=1;
				int temp;
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
		// If NO SWAPPING IN PASS 1--> ARRAY IS ALREADY SORTED
		if(flag==0){
			return;
		}
	}

}

void Analysis(){
	cout<<"\n======================================================"<<endl;
	cout<<"********** ANALYSIS OF BUBBLE SORT ***********"<<endl;
	cout<<"========================================================"<<endl;
	cout<<"\n********** TIME COMPLEXITY ***********"<<endl;
	cout<<"BEST CASE :: O(n) already sorted array--> "<<endl;
	cout<<"AVERAGE CASE :: O(n^2) --> elements are partially sorted"<<endl;
	cout<<"WORST CASE :: O(n^2) --> elements are in descending order"<<endl;
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

	//Bubble sort
	Bubble_Sort(arr,n);

	cout<<"\nThe sorted array is::"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	Analysis();
	return 0;
}
