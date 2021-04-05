//============================================================================
// Name        : MERGE SORT.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//Merging two list from a single array
void Merge(int arr[],int low,int mid,int high){
	//for traversing through arrays
	int i=low;		//for sub-array 1
	int j=mid+1;	//for sub-array 2 starting index will be mid+1
	int k=low;		//for merged auxillary array

	int B[100];		//auxillary array;

	while(i<=mid and j<=high){
		//smaller element is from 1-st part
		if(arr[i]<arr[j]){
			B[k++]=arr[i++];
		}
		//smaller element is from 2-nd part
		else{
			B[k++]=arr[j++];
		}
	}
	//add remaining elements from 1-st part
	for(;i<=mid;i++){
		B[k++]=arr[i];
	}
	//add remaining elements from 2-nd part
	for(;j<=high;j++){
		B[k++]=arr[j];
	}

	//add sorted elements from auxillary array to original array(arr)
	for(int i=low;i<=high;i++){
		arr[i]=B[i];
	}
}

void Merge_Sort_iterative(int arr[],int n){
	int p,low,high,mid,i;

	//every time array is split into half
	for(p=2;p<=n;p=p*2){
		//merging the lists
		for(i=0;i+p-1<=n;i=i+p){
			low=i;
			high=i+p-1;
			mid=(low+high)/2;
			Merge(arr,low,mid,high);
		}
	}
	if(p/2<n){
		Merge(arr,0,p/2-1,n);
	}
}
void Merge_Sort_Recursive(int arr[],int low,int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		Merge_Sort_Recursive(arr,low,mid);
		Merge_Sort_Recursive(arr,mid+1,high);
		Merge(arr,low,mid,high);
	}
}
void Analysis(){
	cout<<"\n======================================================"<<endl;
	cout<<"********** ANALYSIS OF MERGE SORT ***********"<<endl;
	cout<<"========================================================"<<endl;
	cout<<"\n********** TIME COMPLEXITY ***********"<<endl;
	cout<<"BEST CASE :: O(n*log n) "<<endl;
	cout<<"AVERAGE CASE :: O(n*log n)"<<endl;
	cout<<"WORST CASE :: O(n*log n)"<<endl;
	cout<<endl;

	cout<<"********** SPACE COMPLEXITY ***********"<<endl;
	cout<<"Space complexity :: O(n)"<<endl;
	cout<<"======================================================"<<endl;

}

void Output(int arr[],int n){
	cout<<"\nThe sorted array is::"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

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


	int opn;
	do{
	cout<<"\nCHOOSE METHOD\n1)ITERATIVE MERGE SORT \n2)RECURSSIVE MERGE SORT"<<endl;
	cout<<"Enter your choice::";
	cin>>opn;
	//Merge Sort
	switch(opn){
	case 1:
		Merge_Sort_iterative(arr,n);
		Output(arr,n);
		break;
	case 2:
		Merge_Sort_Recursive(arr,0,n-1);
		Output(arr,n);
		break;
	}
	}while(opn!=2);

	Analysis();

	return 0;
}
