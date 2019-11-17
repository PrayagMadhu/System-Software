#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char dir[15][15];
char tmp[15];
int i=0, k=0, f=0, j=0, f1=0, f2=0;

void create()
{
	printf("\nEnter file name : ");
	scanf("%s", tmp);
	if (k==0 || k==-1)
	{
		strcpy(dir[k++], tmp);
	}
	else
	{
		for(i=0; i<k; i++)
		{
			if (strcmp(dir[i], tmp)==0){printf("\nfile alredy exists !! \n");f=1;break;}
		}
		if (f==0) strcpy(dir[k++], tmp);
	}
		
}

void display()
{
	if (k==0){ printf("\nDirectory empty !!\n"); return;}
	else
	{
		for (i=0; i<k; i++)
			printf("%s\n", dir[i]);
			
	}
	
}

void delete()
{
	printf("\nEnter file to delete ");
	scanf("%s", tmp);
	for (i=0; i<k; i++)
	{
		if (strcmp(dir[i], tmp)==0)
		{
			for (j=i; j<k-1; j++)
			{
				strcpy(dir[j], dir[j+1]);
			}
			k--;
			f1=1;
			break;
			
			
		}
		
	}
	if (f1==0) printf("\nFile not found !!\n");
}

void search()
{
	printf("\nEnter file to search : ");
	scanf("%s", tmp);
	for (i=0; i<k; i++)
	{
		if (strcmp(tmp, dir[i])==0) {printf("\nFile exists in directory\n");f2=1;break;}
			
	}
	if (f2==0) printf("\nFile not found\n");
	f2=0;
}

int main()
{
	int opt;
	printf("1. create\n2. display\n3. delete\n4. search\n5. exit\n");
	while(1)
	{
		printf("Choose option : ");
		scanf("%d",  &opt);
		switch(opt)
		{
			case 1: create();break;
			case 2: display();break;
			case 3: delete();break;
			case 4: search();break;
			case 5: exit(0); break;
		}
	}
}

