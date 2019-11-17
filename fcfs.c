#include<stdio.h>

void findAvgTimes(int at[], int bt[], int n)
{

	int i=0;
	int stat=0, swt=0;
	int cti=0;
	int tat[n];
	int wt[n];
	int ct[n];
	for (i=0; i<n; i++)
	{
		ct[i]=cti+bt[i];
		cti=ct[i];
	}

	for (i=0; i<n;  i++)
	{
		tat[i]=ct[i]-at[i];
		stat+=tat[i];
	
	}

	for (i=0; i<n;  i++)
	{
		wt[i]=tat[i]-bt[i];
		swt+=wt[i];
	
	}


	printf("avg. tat = %d", stat/n );
	printf("avg. wt = %d", swt/n );

}

void sort(int arr[][5], int n)	
{
	int i=0, j=0, temp=0;
	for (i=0; i<n; i++)
	{
		for (j=1; j<n-i; j++)
		{
			if (arr[j][1]>arr[j+1][1])
			{
				temp=arr[j][1];
				arr[j][1]=arr[j+1][1];
				arr[j+1][1]=temp;
			}
		}	
	}
}





int main()
{
int n=3;
int bt[]={24,3,3};
int at[]={0,1,2};
//int at_bt[][5]={{1,7}, {2,5}, {3,1}, {4,2}, {5,8}};
//sort(at_bt, n);
findAvgTimes(at, bt, n);

}
