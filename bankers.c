#include<stdio.h>
void isSafe(int proc[], int alloc[][5], int max[][5], int avail[], int n, int r)
{
	int need[n][r];
	int i=0, j=0;
	for (i=0; i<n; i++)
		for (j=0; j<r; j++)
			need[i][j]=max[i][j]-alloc[i][j];


	int finish[]={0,0,0,0,0};
	int sSeq[n];
	int c=0;
	while (c<n)
	{
		int i=0;
		int found = 0;
		for (i=0; i<n; i++)
		{
			if (finish[i]==0)
			{
				int j=0;
				for (j=0; j<r; j++)
					if (avail[j]<need[i][j])
						break;
				if (j==r)
				{
					int k=0;
					for (k=0; k<r; k++)
						avail[k]+=alloc[i][k];
				
				finish[i]=1;
				sSeq[c++]=i;
				found=1;
				}

			}
		}

	
	}
	for (i=0; i<n; i++)
		printf("%d ", sSeq[i]);

}



int main()
{
	int n=5, r=3;
	int process[]={1,2,3,4,5};
	int allocated[][5]={{0,1,0}, {2,0,0}, {3,0,2}, {2,1,1}, {0,0,2}};
	int max[][5]={{7,5,3}, {3,2,2}, {9,0,2}, {4,2,2}, {5,3,3}};
	int avail[]={3,3,2};
	isSafe(process, allocated, max, avail, n ,r);	
}
