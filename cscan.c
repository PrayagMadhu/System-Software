#include<stdio.h>

void scan(int arr[], int n, int k)
{
	int i=0, j=0, temp, loc, r=1;
	for (i=1; i<n; i++)
		for (j=0; j<n-i; j++)
			if (arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
	for (i=0; i<n-1; i++)
		if (arr[i]<k && arr[i+1]>k)
		{
			loc=i;
			break;
		}
	while(1)
	{
		if (i>-1 && r==1){
			printf("%d ", arr[i]);
			i--;
			if (i==-1){
				i=n-1;r=0;}}
		else{
			printf("%d ", arr[i]);
			i--;
			if (i==loc) break;}
	}

}


int main()
{
	int f=0, n=8, k=53, i;
	int arr[]={98,183,37,122,14,124,65,67};
	//for (i=0; i<n; i++)
	//	scanf("%d", &arr[i]);
	scan(arr, n, k);
}
