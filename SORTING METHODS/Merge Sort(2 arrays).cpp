//============================================================================
// Name        : Merge.cpp
// Author      : Rhutvij Chiplunkar
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int A[10],B[10],C[10];
	int m,n,l;
	int i,j,k;

	cout<<"Enter the number of elements in array A::";
	cin>>n;

	for(int i=0;i<n;i++){
		cout<<"Enter element arr["<<i<<"]::";
		cin>>A[i];
	}

	cout<<"\nEnter the number of elements in array B::";
	cin>>m;

	for(int i=0;i<m;i++){
		cout<<"Enter element arr["<<i<<"]::";
		cin>>B[i];
	}

	cout<<"\nThe array A is::"<<endl;
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;

	cout<<"\nThe array B is::"<<endl;
	for(int i=0;i<m;i++){
		cout<<B[i]<<" ";
	}
	cout<<endl;

	for(int k=0;k<n-2;k++){
		for(l=k+1;l<=n-1;l++){
			if(A[k]>A[l]){
				int temp=A[k];
				A[k]=A[l];
				A[l]=temp;
			}
		}
	}

	for(int k=0;k<m-2;k++){
		for(l=k+1;l<=m-1;l++){
			if(B[k]>B[l]){
				int temp=B[k];
				B[k]=B[l];
				B[l]=temp;
			}
		}
	}

	for(i=j=k=0;i<n+m;){
		if(A[j]<=B[k]){
			C[i++]=A[j++];
		}
		else{
			C[i++]=B[k++];
		}
		if(j==m || k==n){
			break;
		}
	}

	for(;j<n;){
		C[i++]=A[j++];
	}
	for(;k<m;){
		C[i++]=B[k++];
	}


	cout<<"\nSORTED ARRAY IS::"<<endl;
	for(int i=0;i<m+n;i++){
		cout<<C[i]<<" ";
	}
	cout<<endl;
}
