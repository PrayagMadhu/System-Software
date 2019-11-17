#include<stdio.h>
#include<stdlib.h>
int q[25], pf, f=0, r=0, loc=0, idx=0, count=0, tar=0, i, elm,flag=0;

void lru_replace(int arr[], int pg, int fsiz)
{
	if  (count<fsiz){
		arr[idx++]=pg;
		count++;
		for (i=0; i<count; printf("%d, ", arr[i++]));
		printf("\n");}
	else{
				
		for (i=r; i>r-fsiz-1; i--){
			if (q[f]==q[i]){
				elm=q[f++];flag=1;
				}
			else {elm=q[f];}
			}

		//if (q[f]==q[r]) {elm=q[f+1];f++;}
		//else elm=q[f];


		for (i=0; i<fsiz; i++)
			if (arr[i]==elm) {tar=i;break;}
		arr[tar]=pg;
		for (i=0; i<count; printf("%d, ", arr[i++]));
		printf("\n");
	        if (flag==0){
		if (f==r) f=0;//delete pg from front of q if new pg is inserted
		else f++;}
	}	

	//always insert for new pg to rear
	if (r==25){
		r=0;
		q[r]=pg;}
	else {
		q[r++]=pg;}
	flag==0;
}

int main()
{
	int fsize, n, i, j, fl=0,k;
	printf("\nEnter total pages : ");
	scanf("%d", &n);
	printf("\nEnter frame size : ");
	scanf("%d", &fsize);
	int refstr[n], arr[fsize];
	for (i=0; i<fsize;arr[i++]=-1);//if not done, then 0 will not be considered
	printf("\nEnter reference string : ");
	for (i=0; i<n; scanf("%d", &refstr[i++]));
	for (i=0; i<n; i++)
	{
		for (j=0; j<fsize; j++)
			if (arr[j]==refstr[i]){
				fl=1;
				printf("np pf\n");
				if (r==25){
					r=0;
					q[r]=refstr[i];}
				else {
					q[r++]=refstr[i];
					}
				printf("Q : ");
				for (k=f; k<r; printf("%d, ", q[k++]));
				printf("\n");
				break;}
				
		if (fl==0){

			lru_replace(arr, refstr[i], fsize);
			pf++;
			}
		if (fl==1) fl=0;
			
	}
	printf("\nPage fault : %d\n", pf);	
}
