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
	int i,j,max;
	for(i=n-1;i>0;i--)		//Starts from n-1 as it will store max no.
	{
		max = i;			//assignment of max
		for(j=0;j<i;j++)	//j<i
		{
			if(arr[max]<arr[j]) max = j;
		}
		if(max!=i) swap(&arr[max],&arr[i]);
	}
	cout<<"\n\nSorted array is: ";
	for(i=0;i<n;i++) cout<<arr[i]<<" ";
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
	cout<<"\nArray generated is: ";
	for(i=0;i<n;i++)
	{
		arr[i] = rand()%(lim+1);
		cout<<arr[i]<<" ";
	}
	selectionSort(arr,n);
	return 0;
}
