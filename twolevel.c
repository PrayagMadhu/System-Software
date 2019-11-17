#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct user
{
	int uid,i, k, f, j, f1, f2;
	char dir[15][15];
}user;

user arr[5];
int id;
char tmp[15];


void create()
{
	printf("\nEnter user id : ");
	scanf("%d", &id);
	printf("\nEnter file name : ");
	scanf("%s", tmp);
	if (arr[id].k==0 || arr[id].k==-1)
	{
		strcpy(arr[id].dir[arr[id].k++], tmp);
	}
	else
	{
		for(arr[id].i=0; arr[id].i<arr[id].k; arr[id].i++)
		{
			if (strcmp(arr[id].dir[arr[id].i], tmp)==0){printf("\nfile alredy exists !! \n");arr[id].f=1;break;}
		}
		if (arr[id].f==0) strcpy(arr[id].dir[arr[id].k++], tmp);
	}
		
}

void display()
{
	printf("\nEnter user id : ");
	scanf("%d", &id);
	if (arr[id].k==0){ printf("\nDirectory empty !!\n"); return;}
	else
	{
		for (arr[id].i=0; arr[id].i<arr[id].k; arr[id].i++)
			printf("%s\n", arr[id].dir[arr[id].i]);
			
	}
	
}

void delete()
{
	printf("\nEnter user id : ");
	scanf("%d", &id);
	printf("\nEnter file to delete ");
	scanf("%s", tmp);
	for (arr[id].i=0; arr[id].i<arr[id].k; arr[id].i++)
	{
		if (strcmp(arr[id].dir[arr[id].i], tmp)==0)
		{
			for (arr[id].j=arr[id].i; arr[id].j<arr[id].k-1; arr[id].j++)
			{
				strcpy(arr[id].dir[arr[id].j], arr[id].dir[arr[id].j+1]);
			}
			arr[id].k--;
			arr[id].f1=1;
			break;
			
			
		}
		
	}
	if (arr[id].f1==0) printf("\nFile not found !!\n");
}

void search()
{
	printf("\nEnter user id : ");
	scanf("%d", &id);
	printf("\nEnter file to search : ");
	scanf("%s", tmp);
	for (arr[id].i=0; arr[id].i<arr[id].k; arr[id].i++)
	{
		if (strcmp(tmp, arr[id].dir[arr[id].i])==0) {printf("\nFile exists in directory\n");arr[id].f2=1;break;}
			
	}
	if (arr[id].f2==0) printf("\nFile not found\n");
	arr[id].f2=0;
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
