#include<stdio.h>

void findAvgTimes(int arr[][5], int n)
{
	int i=0, j=0, temp=0;
	int stat=0, swt=0;
	int tat[n];
	int wt[n];
	int ct[n];
	ct[0]=arr[0][0]+arr[0][1];
	int cti=ct[0];
	for (i=1; i<n; i++)
	{
		for (j=1; j<n-i; j++)
		{
			if (arr[j][1]> arr[j+1][1])
			{
				temp=arr[j][1];
				arr[j][1]=arr[j+1][1];
				arr[j+1][1]=temp;
			}
		}	
	}
	
	
	for (i=1; i<n; i++)
	{
		ct[i]=cti+arr[i][1];
		cti=ct[i];
	}
	//for (i=0; i<n; printf("%d\n", ct[i++]));
	for (i=0; i<n;  i++)
	{
		tat[i]=ct[i]-arr[i][0];
		stat+=tat[i];
	
	}


	for (i=0; i<n;  i++)
	{
		wt[i]=tat[i]-arr[i][1];
		swt+=wt[i];
	
	}



	printf("avg. tat = %d\n", stat/n );
	printf("avg. wt = %d\n", swt/n );


}

int main()
{
	int n=5;
	int at_bt[][5]={{1,7}, {2,5}, {3,1}, {4,2}, {5,8}};
	findAvgTimes(at_bt, n);

}
