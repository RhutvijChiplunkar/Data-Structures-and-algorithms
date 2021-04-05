//============================================================================
// Name        : SHELL.cpp
// Author      : Rhutvij Chiplunkar
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void Shell_Sort(int arr[],int n){
	int gap,i,j;

	for(gap=n/2;gap>=1;gap/=2){
		for(i=gap;i<n;i++){
			int temp=arr[i];
			j=i-gap;

			while(j>=0 && arr[j]>temp){
				arr[j+gap]=arr[j];
				j=j-gap;
			}
			arr[j+gap]=temp;
		}
	}
}
void Analysis(){
	cout<<"\n======================================================"<<endl;
	cout<<"********** ANALYSIS OF SHELL SORT ***********"<<endl;
	cout<<"========================================================"<<endl;
	cout<<"\n********** TIME COMPLEXITY ***********"<<endl;
	cout<<"BEST CASE :: O(n*log n)"<<endl;
	cout<<"AVERAGE CASE :: O(n*((log n)^2))"<<endl;
	cout<<"WORST CASE :: O(n*((log n)^2))"<<endl;
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

	//Shell sort
	Shell_Sort(arr,n);

	cout<<"\nThe sorted array is::"<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	Analysis();
	return 0;
}
