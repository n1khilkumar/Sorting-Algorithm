#include<iostream>
#include<time.h>
using namespace std;

void merging(int A[],int low,int mid,int high)
{
	int B[high+1],i=low,j=mid+1,k=low;	//size of B = high+1, j second array starts from mid+1
	while(i<=mid&&j<=high)				//note k = low
	{
		if(A[i]<A[j]) B[k++] = A[i++];
		else B[k++] = A[j++];
	}
	while(i<=mid) B[k++] = A[i++];		//note <= sign 
	while(j<=high) B[k++] = A[j++];
	for(i=low;i<=high;i++) A[i] = B[i];	//note i is assigned low (do not assign 0)
}

void mergeSort(int A[],int low,int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;			
		mergeSort(A,low,mid);
		mergeSort(A,mid+1,high);
		merging(A,low,mid,high);
	}
}

int main()
{
	int lim,n,i;
	cout<<"Enter the size of the array: ";
	cin>>n;
	cout<<"Enter the limit of the array: ";
	cin>>lim;
	int arr[n];
	cout<<"\nGenerated array is: ";
	srand(time(0));
	for(i=0;i<n;i++)
	{
		arr[i] = rand()%(lim+1);
		cout<<arr[i]<<" ";
	}
	mergeSort(arr,0,n-1);
	cout<<"\n\nSorted array is: ";
	for(i=0;i<n;i++) cout<<arr[i]<<" ";
	return 0;
}
