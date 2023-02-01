#include<iostream>
#include<time.h>
using namespace std;

void swap(int *num1,int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void insertionSort(int arr[],int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)		//i starts from 1 because j must be 1 less than it
	{
		temp = arr[i];		
		j = i-1;			//1 less than i
		while(j>=0&&arr[j]>temp)
		{
			arr[j+1] = arr[j--];	//decrementing j
		}
		swap(&temp,&arr[j+1]);		//note j+1
	}
	cout<<"\n\nSorted array is: ";
	for(i=0;i<n;i++) cout<<arr[i]<<" ";
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
	for(i=0;i<n;i++)
	{
		arr[i] = rand()%(lim+1);
		cout<<arr[i]<<" ";
	}
	insertionSort(arr,n);
	return 0;
}
