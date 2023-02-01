#include<iostream>
#include<time.h>
using namespace std;

void swap(int *num1,int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

int partition(int arr[],int low,int high)
{
	int pivot = arr[low];
	int i = low+1,j = high;		//note i = low+1
	while(true)
	{
		while(i<=j&&arr[i]<=pivot) i++;	//note <= sign (not present in middle pivot)
		while(i<=j&&arr[j]>=pivot) j--;
		if(i>j) break;
		else swap(&arr[i],&arr[j]);
	}
	swap(arr[low],arr[j]);
	return j;					//return j only in left pivot
}

int quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int p = partition(arr,low,high);
		quickSort(arr,low,p-1);
		quickSort(arr,p+1,high);
	}
}

int main()
{
	int i,n,lim;
	cout<<"Enter the size of the array: ";
	cin>>n;
	cout<<"Enter the limit of the array: ";
	cin>>lim;
	int arr[n];
	srand(time(0));
	cout<<"\nGenerated array is: ";
	for(i=0;i<n;i++)
	{
		arr[i] = rand()%(lim+1);
		cout<<arr[i]<<" ";
	}
	quickSort(arr,0,n-1);
	cout<<"\n\nSorted array is: ";
	for(i=0;i<n;i++) cout<<arr[i]<<" ";
	return 0;
}
