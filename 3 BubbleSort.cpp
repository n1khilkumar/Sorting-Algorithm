#include<iostream>
#include<time.h>
using namespace std;

void swap(int *num1,int *num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void bubbleSort(int arr[],int n)
{
	int i,j;
	for(i=n-1;i>0;i--)		//starts from n-1
	{											//you can also start i = 0 to i<n-1
		for(j=0;j<i;j++)	//j<i				//and j = 0 to j<n-1-i
		{
			if(arr[j]>arr[j+1]) swap(&arr[j],&arr[j+1]);
		}
	}
	cout<<"\n\nSorted array is: ";
	for(i=0;i<n;i++) cout<<arr[i]<<" ";
}

int main()
{
	int lim,i,n;
	cout<<"Enter the size of the array: ";
	cin>>n;
	cout<<"Enter the limit of the array: ";
	cin>>lim;
	cout<<"\nGenerated array is: ";
	int arr[n];
	srand(time(0));
	for(i=0;i<n;i++)
	{
		arr[i] = rand()%(lim+1);
		cout<<arr[i]<<" ";
	}
	bubbleSort(arr,n);
	return 0;
}
