//============================================================================
// Name        : QUICK SORT.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
using namespace std;

/*
int partition(int arr[],int low,int high){
	int pivot=arr[low];
	int i=1,j=high;
	do{
		do{i++;}while(arr[i]<=pivot);
		do{j--;}while(arr[j]>=pivot);

		if(i<j){
			//swap i and j
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}while(i<j);

	//swap low and j
	int temp1=arr[low];
	arr[low]=arr[j];
	arr[j]=temp1;

	return j;
}

void Quick_Sort(int arr[],int low,int high){

	int j;

	if(low<high){
		j=partition(arr,low,high);
		Quick_Sort(arr,low,j-1);
		Quick_Sort(arr,j+1,high);
	}
}
*/

void Quick_Sort(int arr[],int low,int high){
	int pivot=arr[low];
	int i=low+1, j=high;

	while(i<=j){
		while(arr[i]<pivot){
			i++;
		}
		while(arr[j]>pivot){
			j--;
		}
		if(i<j){
			int temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
		}
	}
	arr[low]=arr[j];
	arr[j]=pivot;
	j--;

	if(low<j){
		Quick_Sort(arr,low,j);
	}
	if(i<high){
		Quick_Sort(arr,i,high);
	}
}
void Analysis(){
	cout<<"\n======================================================"<<endl;
	cout<<"********** ANALYSIS OF QUICK SORT ***********"<<endl;
	cout<<"========================================================"<<endl;
	cout<<"\n********** TIME COMPLEXITY ***********"<<endl;
	cout<<"BEST CASE :: O(n*log n)"<<endl;
	cout<<"AVERAGE CASE :: O(n*log n)"<<endl;
	cout<<"WORST CASE :: O(n^2)"<<endl;
	cout<<endl;

	cout<<"********** SPACE COMPLEXITY ***********"<<endl;
	cout<<"Space complexity :: O(log n)"<<endl;
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

	//Quick Sort
	Quick_Sort(arr,0,n-1);

	cout<<"\nThe sorted array is::"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	Analysis();
	return 0;
}
