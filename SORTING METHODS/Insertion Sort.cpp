//============================================================================
// Name        : INSERTION SORT.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
using namespace std;

void Insertion_Sort(int arr[],int n){
	for(int i=1;i<n;i++){
		int j=i-1;
		int temp=arr[i];
		while(j>=0 and arr[j]>temp){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
}
void Analysis(){
	cout<<"\n======================================================"<<endl;
	cout<<"********** ANALYSIS OF INSERTION SORT ***********"<<endl;
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

	//Insertion sort
	Insertion_Sort(arr,n);

	cout<<"\nThe sorted array is::"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	Analysis();
	return 0;
}
