#include<iostream>
#include<time.h>
using namespace std;

void swap(int *num1,int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void selectionSort(int arr[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)		//Starts from 0 as it will store min elements
	{
		min = i;			//Assignment of min
		for(j=i+1;j<n;j++)	//j=i+1
		{
			if(arr[min]>arr[j]) min = j;
		}
		if(min!=i) swap(&arr[min],&arr[i]);
	}
	cout<<"\n\nSorted Array is: ";
	for(i=0;i<n;i++) cout<<arr[i]<<" ";
}

int main()
{
	int i,lim,n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	cout<<"Enter the limit of the array: ";
	cin>>lim;
	int arr[n];
	cout<<"\nGenerated array is: ";
	for(i=0;i<n;i++)
	{
		arr[i] = rand()%(lim+1);
		cout<<arr[i]<<" ";
	}
	selectionSort(arr,n);
	return 0;
}
