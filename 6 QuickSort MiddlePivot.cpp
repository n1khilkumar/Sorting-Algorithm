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
	int pivot = arr[(low+high)/2];	
	int i = low,j = high;			//note there is no low-1 or high-1 assignment
	while(true)
	{
		while(i<=j&&arr[i]<pivot) i++;	//note < sign, probably to skip pivot if encountered 
		while(i<=j&&arr[j]>pivot) j--;
		if(i>j) break;
		else 
		{
			swap(&arr[i],&arr[j]);
			i++;						//additional increment
			j--;
		}
	}								//note no swapping with pivot as it is in its position
	return i;
}

void quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int p = partition(arr,low,high);
		quickSort(arr,low,p-1);		//note high = p-1
		quickSort(arr,p,high);		//note low = p   unlike in left and right pivot
	}
}
int main()
{
	int lim,i,n;
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
	quickSort(arr,0,n-1);
	cout<<"\n\nSorted array is: ";
	for(i=0;i<n;i++) cout<<arr[i]<<" ";
	return 0;
}
