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
	int pivot = arr[high];
	int i = low-1, j;			//note i = low - 1  
	for(j=low;j<=high-1;j++)	//j starts from low (do not assign 0)
	{
		if(arr[j]<pivot)		//finds smaller values
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);	//note i+1
	return i+1;					//note i+1
}

void quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int p = partition(arr,low,high);	//same as left pivot
		quickSort(arr,low,p-1);
		quickSort(arr,p+1,high);
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
